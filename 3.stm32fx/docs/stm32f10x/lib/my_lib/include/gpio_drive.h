#include "stm32f10x.h" 
#include "stdint.h"

// define 
#define __IO__  volatile

#define RCC_APBENR       (*((volatile unsigned long *) 0x40021018))

#define GPIO_A       		 (*((volatile unsigned long *) 0x40010800))
#define GPIO_B       		 (*((volatile unsigned long *) 0x40010C00))
#define GPIO_C       		 (*((volatile unsigned long *) 0x40011000))



#define PA          1           
#define PB          2           
#define PC          3          

#define HIGH       1
#define LOW        0

#define  IN        0
#define  OUT10     1
#define  OUT2      2
#define  OUT50     3


#define I_AN 0
#define I_F  1
#define I_PP 2

#define O_GP_PP 0
#define O_GP_OD 1
#define O_AF_PP 2
#define O_AF_OD 3


// define inline function
#define set_bit((reg), (index))     (reg) |= 1<<(index)
#define clear_bit((reg), (index))   (reg) &= ~(1<<(index))

// init function
void GPIO_Init(uint8_t PORT,uint8_t PIN,uint8_t DIR,uint8_t OPT);
int GPIO_Read(uint8_t PORT,uint8_t pin);
void GPIO_Write(uint8_t PORT,uint8_t pin, uint8_t STATUS);
void GPIO_Toggle_Pin(uint8_t Port, uint8_t Pin)
