#include "stm32f10x.h"                  // Device header
#include "gp_driver.h"

void delayfor(unsigned long t);
void Systick_init(void);
void delayMilis(void);
void delay(unsigned long t);
int main(void){
	Systick_init();
	init_gp(PA,12,OUT50,O_GP_PP);
	while(1){
		W_GP(PA,12,1);
		delay(1000);
		//delayfor(10000);
		W_GP(PA,12,0);
		delay(1000);
		//delayfor(10000);
	}
	
}

void delayfor(unsigned long t){
	for(; t> 0; t--);
}

void Systick_init(void){
	SysTick->CTRL = 0;// reset value in reg
	
	SysTick->LOAD = 0x00ffffff;
	
	SysTick->VAL = 0;
	
	SysTick->CTRL |= 5;
	/*
	SysTick->CTRL->
	*/ 
}

void delayMilis(void){
	SysTick->LOAD = 0x1A5E0;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}

void delay(unsigned long t){
	for(; t > 0; t--){
		delayMilis();
	}
}
