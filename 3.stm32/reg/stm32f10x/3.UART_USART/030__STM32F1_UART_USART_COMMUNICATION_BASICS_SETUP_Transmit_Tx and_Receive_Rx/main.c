#include "stm32f10x.h"                  // Device header
#include "gp_driver.h"
#include "systick_time.h"
char chat =  'c';


int main(void){
	// delay function
	Systick_init();
	
	// --------------- init UART---------------------//
	// enable the alternate function for pins
	RCC->APB2ENR |= 1;
	// ENABLE UART2 / 1 3
	RCC->APB1ENR |= 0x20000;
	// ENABLE the ralated pins
	init_gp(PA,2,OUT50,O_AF_PP); // rx pin
	init_gp(PA,3,IN,I_PP);
	// setup the baude rate for 9600
	USART2->BRR = 0xEA6;
	// enable uart transmit
	USART2->CR1 |= 8;
	// enable uart recive
	USART2->CR1 |= 4;
	// enable uart
	USART2->CR1 |= 0x2000;
	while(1){
	// recieve char
		while(((USART2->SR &0x20)) == 0x00);
		chat = USART2->DR;
		
		// transmit char
		Delayms(100);
		while((USART2->SR & (1<<6)) == 0x80);
		// thanh ghi USART2->DR lu tru gia tri cua truyen nhan uart
		USART2->DR = chat;	
	}
	

}
