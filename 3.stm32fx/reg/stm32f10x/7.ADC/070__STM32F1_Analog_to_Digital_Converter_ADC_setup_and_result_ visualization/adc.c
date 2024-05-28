#include"adc.h"

// Initializing the ADC for the STM32F1
char adc_init(char adc, short port, short pin)
{
	char channel;
	char result = 0;
	if(port == PA)
	{
		if(pin < 8)
		{
			result = 1;
			channel = pin;
		}
	}
	else if (port == PB)
	{
		if(pin<2)
		{
		result = 1;
		channel = 8 + pin;
		}
	}
	else if (port == PC)
	{
		if(pin<6)
		{
		result = 1;
		channel = 10 + pin;
		}
	}
	if(result)
	{
		init_GP(port,pin,IN,I_AN);
		if(adc == adc1)
		{
			RCC->APB2ENR |= 0x201;
			ADC1->CR2 = 0;
			ADC1->SQR3 = channel;
			ADC1->CR2 |= 1;
			DelayMs(100);
			ADC1->CR2 |= 1;
			ADC1->CR2 |= 2;
		}
		else if(adc == adc2)
		{
			RCC->APB2ENR |= 0x401;
			ADC2->CR2 = 0;
			ADC2->SQR3 = channel;
			ADC2->CR2 |= 1;
			DelayMs(100);
			ADC2->CR2 |= 1;
			ADC2->CR2 |= 2;
		}
	}
	return result ;
}

// Reading the flag that says the data is ready
char adc_check(char adc, short port, short pin)
{
	char check = 0;
	if(adc == adc1)
		{
			if(ADC1->SR & 2)
			{
				check  = 1;
			}
		}
		else if(adc == adc2)
		{
			if(ADC2->SR & 2)
			{
				check  = 1;
			}
		}
	
	
	return check;
}

// Reading the ADC value 
int adc_rx(char adc, short port, short pin)
{
	int result = 0;
	int data = 0;
	if(adc == adc1)
	{
		data = ADC1->DR;
	} 
	else if(adc == adc2)
	{
		data = ADC2->DR;
	}
	
	result = (data*1000)/0xfff;
	
	
	return result;
}
