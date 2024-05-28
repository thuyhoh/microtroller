#include "stm32f10x.h"                  // Device header
#include "adc.h"
int adc_val;
int main(void)
{
	
	adc_init(adc1,PA,0);
	while(1)
	{
		if(adc_check(adc1,PA,0))
		{
				adc_val = adc_rx(adc1, PA, 0);
		}
		
	}
		
	//return 0;
}
