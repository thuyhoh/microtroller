#include "systick_time.h"


void Systick_init(void){
	// reset reg value
	SysTick_CTRL = 0;
	SysTick_LOAD = 0x00ffffff;
	// SysTick->LOAD thanh ghi load duoc ghi vao SysTick->VAL
	SysTick_VAL = 0;
	
	// enable bit 0,2
	SysTick_CTRL |= 5;
}

void DelayMilis(void){
	SysTick_LOAD = 0x1A5E0; // 0x1A5E0: so xung duoc tao ra trong 1ms
	SysTick_VAL = 0;
	while((SysTick_CTRL & 0x00010000) == 0);
	// SysTick_CTRL->bit17: co ngat khi SysTick->VAL dem 1->0
}

void Delayms(unsigned long t){
	for(; t > 0; t--){
		DelayMilis();
	}
}

