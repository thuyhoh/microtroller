#include "stm32f10x.h" 
#include "systick_drive.h"

void SysTick_init(void)
{
	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL |= 5;
}

void SysTick_ISR(void){
	// reset reg
	SysTick->CTRL = 0; 
	SysTick->LOAD = 0;
	// setup ISR_int
	__disable_irq();
	SysTick->LOAD = 72000;
	SysTick->VAL = 0;
	SysTick->CTRL |= 7;
	/*
		SysTick->CTRL |= 1;
		SysTick->CTRL |= 1 << 2;
		SysTick->CTRL |= 1 << 3;
	*/
	__enable_irq();
}

void DelayMillis(void)
{
	SysTick->LOAD = 0x11940;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}

void DelayMs(unsigned long t)
{
	for(;t>0;t--)
		{
			DelayMillis();
		}
}


