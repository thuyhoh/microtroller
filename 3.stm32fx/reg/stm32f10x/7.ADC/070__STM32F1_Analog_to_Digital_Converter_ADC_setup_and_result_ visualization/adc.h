#include "stm32f10x.h"                  // Device header

#include "gpio_drive.h"
#include "systick_drive.h"

#define adc1 1
#define adc2 2

char adc_init(char adc, short port, short pin);
char adc_check(char adc, short port, short pin);
int adc_rx(char adc, short port, short pin);
