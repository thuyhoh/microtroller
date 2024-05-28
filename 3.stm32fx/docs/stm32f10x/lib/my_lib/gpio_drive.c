#include "gpio_drive.h"

void GPIO_Init(uint8_t PORT,uint8_t PIN,uint8_t DIR,uint8_t OPT)
{
	__IO__ uint64_t * CR;
	uint8_t tPin = PIN;
	uint8_t offset = 0x00;
	
		if(PIN > 7)
		{
			tPin -=8;
			offset = 0x01;
		}
		

	if(PORT == 1)
		{
			RCC_APBENR |= 0x4;

			CR = (__IO__ uint64_t *)(&GPIO_A + offset);
		}
	else if(PORT == 2)
		{
		RCC_APBENR |= 0x8;
		CR = (__IO__ uint64_t *)(&GPIO_B+ offset);
		}
	else if(PORT == 3)
		{
		RCC_APBENR |= 0x10;
		CR = (__IO__ uint64_t *)(&GPIO_C + offset);
		}

	*CR &= ~(0xf<<(tPin)*4);
	*CR |= ((DIR<<(tPin*4)) | (OPT<<(tPin*4+2)));
}

int GPIO_Read(uint8_t PORT,uint8_t pin)
{
	__IO__ uint64_t * IDR;
	uint64_t offset = 0x02;
	int state;
	
	if(PORT == 1)
		{
			IDR = (__IO__ uint64_t *)(&GPIO_A + offset);
		}
	else if(PORT == 2)
		{
		IDR = (__IO__ uint64_t *)(&GPIO_B+ offset);
		}
	else if(PORT == 3)
		{
		IDR = (__IO__ uint64_t *)(&GPIO_C+ offset);
		}
		state =  ((*IDR & (1<<pin))>>pin)  ;
		
		return state;
}

void GPIO_Write(uint8_t PORT,uint8_t pin, uint8_t STATUS)
{
	__IO__ uint64_t * ODR;
	uint64_t offset = 0x03;
	if(PORT == 1)
		{
			ODR = (__IO__ uint64_t *)(&GPIO_A + offset);
		}
	else if(PORT == 2)
		{
		ODR = (__IO__ uint64_t *)(&GPIO_B+ offset);
		}
	else if(PORT == 3)
		{
		ODR = (__IO__ uint64_t *)(&GPIO_C+ offset);
		}
	STATUS ? (*ODR |= (STATUS<<pin)) : (*ODR &= ~(1<<pin));
}

void GPIO_Toggle_Pin(uint8_t Port, uint8_t Pin)
{
	if(GPIO_Read(Port, Pin))
	{
		GPIO_Write(Port, Pin, 0);
	}
	else
	{
		GPIO_Write(Port, Pin, 1);
	}
}

void Blink_Led(void)
{
	GPIO_Write(PB, 2, 0);
}
