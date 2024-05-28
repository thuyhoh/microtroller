#include "gp_drive.h"
#include "stm32f10x.h" 
#include "systick_time.h"

#define adc1          1 
#define adc2          2

typedef struct ADC_TypeDef_t{
	// interrupt 
	uint16_t adc_interrupt_channel : 1;
	// watchdog 
	uint16_t adc_watchdog_channel : 1;
	uint16_t adc_flag : 1;
	uint16_t adc_val : 14;
}ADC_t;

char adc_init(char adc, short port, short pin);
char adc_check(char adc, short port, short pin);
int adc_rx(char adc, short port, short pin);

