#include "stm32f10x.h"                  // Device header
#include "gp_driver.h"

int signal = 0;
void delay(void);

int main(void){
	
	init_gp(PA,0,IN,I_PP);
	init_gp(PC,13,OUT50,O_GP_PP);
	
	__disable_irq(); // vo hieu hoa toan bo ngat trong he thong
	AFIO->EXTICR[0] = 0x00; // kich hoat ngat EXTI0
	EXTI->IMR |= 1; // thanh ghi cho phep bat ngat ngoai vi rieng le: bit0->9: xac dinh muc do uu tien cua cac ngat ngoai vi
	EXTI->RTSR |= 1; // bat ngat canh len (low -> high)
	NVIC_EnableIRQ(EXTI0_IRQn); // Kích hoat ngat EXTI0 trong bo dieu khien ngat (NVIC)
	__enable_irq(); // cho phep toan bo ngat duoc thuc hien
	
	while(1){
			W_GP(PA,12,signal);
			if(signal){
				delay();
				W_GP(PC,13,HIGH);
				delay();
				W_GP(PC,13,LOW);
			}
			else{
				GPIOC->ODR |= 0x200;
			}
	}
}

void delay(void){
	int i;
	for(i = 0; i < 100000; i++);
}

void EXTI0_IRQHandler(void){ // ham thuc hien ngat ngoai tren tra cuu trong file setup
	EXTI->PR |= 1; // xoa ngat tren EXTI0
	if(signal){
		signal = 0;
	}else{
		signal = 1;
	}
}

