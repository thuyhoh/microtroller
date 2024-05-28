#include "adc_drive.h"
#include "help_func.h"
#include "uart_drive.h"
#include "stdint.h"

ADC_t adc1_t;
ADC_t adc2_t;

int adc1_int = 0;
int adc2_int = 0;
int adc1_wd = 0;
int adc2_wd = 0;
int analog_val = 0;
int adc1_flag = 0;
int adc2_flag = 0;
int main(void)
{
// Initialize the ADC
	systick_init();
	UART_init(2,115200);
	adc_init(adc1, PA, 0);
	
	// setting up interrupt adc 1 2
	//ADC1->CR1 |= 0x20;
	//ADC2->CR1 |= 0x20;
	
	// setting wd
	ADC1->CR1 |= 0x800000; // enable watchdog
	ADC1->HTR |= 0xC00;
	ADC1->LTR |= 0x500;
	ADC1->CR1 |= 0x40;
	
	__disable_irq();
	NVIC_EnableIRQ(ADC1_2_IRQn);
	__enable_irq();
	
while(1)
{
	if(adc_check(adc1, PA, 0))
	{
		analog_val = adc_rx(adc1, PA, 0);
		
	}
}
}

void ADC1_2_IRQHandler(){
	if(adc1_int){
		ADC1->CR1 &= ~0x20;
		analog_val = ADC1->DR;
		adc1_flag = 1;
	}
	if(adc2_int){
		ADC2->CR1 &= ~0x20;
		analog_val = ADC2->DR;
		adc2_flag = 1;
	}
	if(adc2_wd){
		ADC2->CR1 &= ~0x20;
		ADC2->SR &= ~0x01;
		analog_val = ADC2->DR;
		adc2_flag = 1;
	}
	if(adc1_wd){
		ADC1->CR1 &= ~0x20;
		ADC1->SR &= ~0x01;
		analog_val = ADC1->DR;
		adc2_flag = 1;
	}
}
