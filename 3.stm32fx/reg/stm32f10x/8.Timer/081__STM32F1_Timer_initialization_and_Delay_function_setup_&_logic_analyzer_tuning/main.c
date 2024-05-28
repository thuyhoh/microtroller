#include "stm32f10x.h"

int main(void)
{
	// set up  the counter a the bus level
	RCC->APB2ENR = (1<<12);
}
