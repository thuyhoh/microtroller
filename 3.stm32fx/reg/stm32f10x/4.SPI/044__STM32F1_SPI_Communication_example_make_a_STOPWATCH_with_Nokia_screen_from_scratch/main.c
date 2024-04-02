/*
doc: PCD8544.PDF
*/

#include "stm32f10x.h"                  // Device header
#include "SPI_drive.h"
#include "gpio_drive.h"
#include "systick_drive.h"
#include "nokia5110lcd.h"
#include "stopwatch.h"
#include "help_func.h"


/* 	connection lines
PA0 -->RST
PA1 --> DC
PA2 -->Screen Light
PA4 --> SS
PA5 --> SCLK
PA7 --> MOSI


PB0 -> reset
PB1 -> start/stop

*/
//
unsigned short sw_start = 0;
unsigned short sw_rst = 1;
unsigned int counter = 0;
unsigned long millis = 0;


unsigned short digit =0;
char number[3];
char time[7];	

int main(void)
{
	systick_init();
	sw_init();
	while(1){
		// reset function
		if(sw_rst){
			sw_reset(&sw_rst,&millis);
		}
		// stop funct
		else if((sw_start == 0)&& (counter != 0)){
			sw_stop(&counter);
		}else if((sw_start == 1)&& (counter != 0)){
			sw_start(&millis, &counter, number,time);
			
		}
		
	}
	
	
	
	return 0;
}

void EXTI0_IRQHandler(){
	EXTI->PR |= 1;
	sw_rst = 1;
}

void EXTI1_IRQHandler(){
	EXTI->PR |= 2;
	if(sw_start){
		sw_start = 0;
	}else{
		sw_start = 1;
		systick_int_start();
	}
}

void SysTick_Handler(){
	counter++;
}
