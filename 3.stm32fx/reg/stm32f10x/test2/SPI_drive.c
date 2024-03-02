#include "stm32f10x.h"                  // Device header

#include "SPI_drive.h"
#include "gpio_drive.h"


/*
SPI2:
SPI_NSS		: PB12  
SPI_SCK		: PB13
SPI_MISO	:	PB14
SPI_MOSI	:	PB15

SPI1:
SPI_NSS		: PA4  
SPI_SCK		: PA5
SPI_MISO	:	PA6
SPI_MOSI	:	PA7

*/

/* PIN_config:
	SPIx_SCK: 
		- master: Alternate function push-pull
		- slave : Input floating
	SPIx_MOSI:
		- master: Alternate function push-pull
		- slave : Input floating / Input pull-up
	SPIx_MISO :
		- master: input floating / Input pull-up
		- slave : Alternate function push-pull(point to point)/ Alternate function open drain(muti-slave)
	SPIx_NSS 	:
		- hardware : Input floating/ Input pull-up / Input pull-down 
		- hardware enable output : Alternate function push-pull
		- software : Be used as a GPIO
		
*/


void SPIx_init(SPI_t SPI_mgr){
	// set alternative function 
	
	// select BR
	
	// set the DFF: data frame format/ LSBFIRST
	
	// select CPOL CPHA
	
	// PIN configure
	if(SPI_mgr.SPI_Channel == 1){
		// reset reg value
		SPI1->CR1 &= 0x0000;
		SPI1->CR2 &= 0x0000;
		
		if(SPI_mgr.SPI_MODE == Master){
			// master config
			SPI1->CR1 |= (SPI_mgr.SPI_BR<<2);
			// data frame format
			if(SPI_mgr.SPI_LSBFIST) (SPI1->CR1 |= (1<<7));
			if(SPI_mgr.SPI_DFF) 		(SPI1->CR1 |= (1<<11));
			// set CPHA vs CPOL 
			SPI1->CR1 |= SPI_mgr.SPI_Clock;
			// CONFIG PIN
			GPIOx_init(PA,5,OUT50,O_AF_PP); // SCK
			GPIOx_init(PA,6,IN,I_PP);				// MISO
			GPIOx_init(PA,7,OUT50,O_AF_PP); //	MOSI
			// CONFIG NSS
			// hardware mode input
			if(SPI_mgr.SPI_NSS_MODE == NSS_IN){
				GPIOx_init(PA,4,IN,I_PP);
				GPIOx_W(PA,4,LOW);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTE){// hardware mode output
				SPI1->CR2 |= (1<<2);
				GPIOx_init(PA,4,OUT50,O_AF_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTD){// hardware mode output disable
				
			}
			else{// software mode
				SPI1->CR1 |= (1<<9);
				if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PA,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PA,(tmp>>2),HIGH);
				}else if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PB,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PB,(tmp>>2),HIGH);
				}
			}
			
		}
		else if(SPI_mgr.SPI_MODE == Slave ){
			//reset reg value
			SPI1->CR1 &= 0x0000;
			SPI1->CR2 &= 0x0000;
			// data frame format // same as the master devices
			if(SPI_mgr.SPI_LSBFIST) (SPI1->CR1 |= (1<<7));
			if(SPI_mgr.SPI_DFF) 		(SPI1->CR1 |= (1<<11)); // 16bit
			// set CPHA vs CPOL // same as the master devices
			SPI1->CR1 |= SPI_mgr.SPI_Clock;
			// config pin
			GPIOx_init(PA,5,OUT50,O_AF_PP); 			// 	SCK
			GPIOx_init(PA,6,OUT50,O_AF_PP);				// 	MISO
			GPIOx_init(PA,7,IN,I_PP); 						//	MOSI
			// config NSS
			if(SPI_mgr.SPI_NSS_MODE == NSS_IN){ // NSS INPUT
				GPIOx_init(PA,4,IN,I_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTE){// hardware mode output
				SPI1->CR2 |= (1<<2);
				GPIOx_init(PA,4,OUT50,O_AF_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTD){// hardware mode output disable
				
			}
			else{// software mode
				// set SSI
				SPI1->CR1 |= (1<<9);
				if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PA,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PA,(tmp>>2),HIGH);
				}else if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PB,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PB,(tmp>>2),HIGH);
				}
			
		}
		// enable SPI
		SPI1->CR1 |= (1<<6);
	}
	else	if(SPI_mgr.SPI_Channel == 2){
		// reset reg value
		SPI2->CR1 &= 0x0000;
		SPI2->CR2 &= 0x0000;
		
		if(SPI_mgr.SPI_MODE == Master){
			// master config
			SPI2->CR1 |= (SPI_mgr.SPI_BR<<2);
			// data frame format
			if(SPI_mgr.SPI_LSBFIST) (SPI2->CR1 |= (1<<7));
			if(SPI_mgr.SPI_DFF) 		(SPI2->CR1 |= (1<<11));
			// set CPHA vs CPOL 
			SPI2->CR1 |= SPI_mgr.SPI_Clock;
			// CONFIG PIN
			GPIOx_init(PA,5,OUT50,O_AF_PP); // SCK
			GPIOx_init(PA,6,IN,I_PP);				// MISO
			GPIOx_init(PA,7,OUT50,O_AF_PP); //	MOSI
			// CONFIG NSS
			// hardware mode input
			if(SPI_mgr.SPI_NSS_MODE == NSS_IN){
				GPIOx_init(PA,4,IN,I_PP);
				GPIOx_W(PA,4,LOW);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTE){// hardware mode output
				SPI2->CR2 |= (1<<2);
				GPIOx_init(PA,4,OUT50,O_AF_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTD){// hardware mode output disable
				
			}
			else{// software mode
				SPI2->CR1 |= (1<<9);
				if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PA,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PA,(tmp>>2),HIGH);
				}else if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PB,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PB,(tmp>>2),HIGH);
				}
			}
			
		}
		else if(SPI_mgr.SPI_MODE == Slave ){
			//reset reg value
			SPI2->CR1 &= 0x0000;
			SPI2->CR2 &= 0x0000;
			// data frame format // same as the master devices
			if(SPI_mgr.SPI_LSBFIST) (SPI2->CR1 |= (1<<7));
			if(SPI_mgr.SPI_DFF) 		(SPI2->CR1 |= (1<<11)); // 16bit
			// set CPHA vs CPOL // same as the master devices
			SPI2->CR1 |= SPI_mgr.SPI_Clock;
			// config pin
			GPIOx_init(PA,5,OUT50,O_AF_PP); 			// 	SCK
			GPIOx_init(PA,6,OUT50,O_AF_PP);				// 	MISO
			GPIOx_init(PA,7,IN,I_PP); 						//	MOSI
			// config NSS
			if(SPI_mgr.SPI_NSS_MODE == NSS_IN){ // NSS INPUT
				GPIOx_init(PA,4,IN,I_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTE){// hardware mode output
				SPI2->CR2 |= (1<<2);
				GPIOx_init(PA,4,OUT50,O_AF_PP);
				GPIOx_W(PA,4,HIGH);
			}
			else if(SPI_mgr.SPI_NSS_MODE == NSS_OUTD){// hardware mode output disable
				
			}
			else{// software mode
				// set SSI
				SPI2->CR1 |= (1<<9);
				if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PA,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PA,(tmp>>2),HIGH);
				}else if((SPI_mgr.SPI_NSS_MODE >> 4) == 1){
					unsigned short tmp = (unsigned short)(SPI_mgr.SPI_NSS_MODE << 2);
					GPIOx_init(PB,(tmp>>2),OUT50,O_GP_PP);
					GPIOx_W(PB,(tmp>>2),HIGH);
				}
			
		}
		// enable SPI
		SPI2->CR1 |= (1<<6);
			}
		}
	}
}
void SPI_Tx(){
	
}

void SPI_Send_msg(SPI_t SPI_mgr){
	
}

