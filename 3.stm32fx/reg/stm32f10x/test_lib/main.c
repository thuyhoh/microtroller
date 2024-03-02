#include "stm32f10x.h"                  // Device header
#include "gp_driver.h"
//#include "systick_time.h"

void SysTick_int(void);
void DelayMillis(void);
void DelayMs(unsigned int time);



int main(void){

	GPIOx_init(PA,14,IN,I_PP);
	GPIOx_init(PA,10,OUT50,O_GP_PP);
	SysTick_int();
	while(1){
		GPIOx_W(PA,14,HIGH);
		DelayMs(1000);
		GPIOx_W(PA,14,LOW);
		DelayMs(1000);
	}
}

void SysTick_int(void){
	// reset regsistor
	SysTick->LOAD &= 0x00000000;
	SysTick->CTRL &= 0x00000000;
	SysTick->VAL  &= 0x00000000;
	// setup SysTick enable
	SysTick->CTRL |= 1; // enable couter
	SysTick->CTRL |= (1<<2); // choose sourse clock (ABH)
}

void DelayMillis(void){
	SysTick->LOAD |= 108000;
	SysTick->VAL   = 0;
	while((SysTick->CTRL & 0x10000) != 0);
}

void DelayMs(unsigned int t){
	while(t == 0){
		t--;
		DelayMillis();
	}
}
