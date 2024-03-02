#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "systick_drive.h"
#include "SPI_drive.h"
#include "nokia5110lcd.h"



void n5110_init(unsigned short Spi_Channel){
	systick_init();

// setup reset pin
	GPIOx_init(PA,0,OUT50,O_GP_PP);
// set RST HIGH and wait 10ms set low and 
	GPIOx_W(PA,0,HIGH);
	DelayMs(10);
	GPIOx_W(PA,0,LOW); // reset of screem
	DelayMs(10);
	GPIOx_W(PA,0,HIGH);
// setup DC pin and set low
	GPIOx_init(PA,1,OUT50,O_GP_PP);
	GPIOx_W(PA,1,LOW);
// setup screenlight pin and test ligh with tonggle
	GPIOx_init(PA,2,OUT50,O_GP_PP);

// setup spi
	SPI_init(Spi_Channel);
	
// extended instruction set and set voltage
	SPI_Tx(Spi_Channel,0x21);	// -> funtion set: extended instruction
	SPI_Tx(Spi_Channel,0xC0); // -> set voltage tang do tuong phan  
// basic instruction set and config display controll
	SPI_Tx(Spi_Channel,0x20);	// -> funtion set: basic set
	SPI_Tx(Spi_Channel,0x0C); // -> display normal mode 
}
/*
void n5110(n5110_t n5110_mgr){
	// setup reset pin
	GPIOx_init(n5110_mgr.RST.Port,n5110_mgr.RST.Pin,OUT50,O_GP_PP);
	// set RST HIGH and wait 10ms set low and 
	GPIOx_W(n5110_mgr.RST.Port,n5110_mgr.RST.Pin,HIGH);
	DelayMs(10);
	GPIOx_W(n5110_mgr.RST.Port,n5110_mgr.RST.Pin,LOW); // reset of screem
	DelayMs(10);
	GPIOx_W(n5110_mgr.RST.Port,n5110_mgr.RST.Pin,HIGH);
	// setup DC pin and set low
	GPIOx_init(n5110_mgr.DC.Port,n5110_mgr.DC.Pin,OUT50,O_GP_PP);
	GPIOx_W(n5110_mgr.DC.Port,n5110_mgr.DC.Pin,LOW);
	// setup screenlight pin and test ligh with tonggle
	GPIOx_init(n5110_mgr.BL.Port,n5110_mgr.BL.Pin,OUT50,O_GP_PP);
	
	// setup spi
	SPI_init(n5110_mgr.Spi_Channel);
	// extended instruction set and set voltage
	SPI_Tx(n5110_mgr.Spi_Channel,0x21);	// -> funtion set: extended instruction
	SPI_Tx(n5110_mgr.Spi_Channel,0xC0); // -> set voltage tang do tuong phan  
// basic instruction set and config display controll
	SPI_Tx(n5110_mgr.Spi_Channel,0x20);	// -> funtion set: basic set
	SPI_Tx(n5110_mgr.Spi_Channel,0x0C); // -> display normal mode 
}
*/
void n5110_print(unsigned short Spi_Channel,short Ypos, short Xpos, char str[]){
	// write string into n5110
	n5110_pos(Spi_Channel,Xpos,Ypos);
	int i,j;
	i = 0;
	GPIOx_W(PA,1,HIGH);
	while(str[i]){
		for(j = 0; j<5;j++){
			SPI_Tx(Spi_Channel,charset[(int)(str[i]-32)][j]);
		}
		i++;
	}
	GPIOx_W(PA,1,LOW);
	// string positon
	
	// clear the string
}

void n5110_pos(unsigned short Spi_Channel,short Xpos, short Ypos){
	GPIOx_W(PA,1,LOW);
	SPI_Tx(Spi_Channel,0x20);	// -> funtion set: basic set
	SPI_Tx(Spi_Channel,(char)(0x40 | Ypos)); // -> display normal mode 
	SPI_Tx(Spi_Channel,(char)(0x80 | Xpos));
	GPIOx_W(PA,1,HIGH);
}

void n5110_clear(unsigned short Spi_Channel){
	GPIOx_W(PA,1,HIGH);
	int j;
	for(j = 0; j< 504;j++){
		SPI_Tx(Spi_Channel,0x00);
	}
}
