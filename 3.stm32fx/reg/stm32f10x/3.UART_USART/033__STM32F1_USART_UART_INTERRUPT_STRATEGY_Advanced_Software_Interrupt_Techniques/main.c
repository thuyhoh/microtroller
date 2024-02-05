/*
	1 - set up an efficient UART communication
	2 - using UART interrupt
*/

#include "stm32f10x.h"                  // Device header
#include "gp_driver.h"
#include "uart_driver.h"
#include "systick_time.h"


// giao tiep giwa 2 fptd lien ket voi stm32f103c8 tai uart2 va uart3


char UART1_msg[100];
unsigned short UART1_signal = 0;
unsigned int UART1_counter = 0;
unsigned short UART1_bgd = 0;

char UART2_msg[100];
unsigned short UART2_signal = 0;
unsigned int UART2_counter = 0;
unsigned short UART2_bgd = 0;

char UART3_msg[100];
unsigned short UART3_signal = 0;
unsigned int UART3_counter = 0;
unsigned short UART3_bgd = 0;

int main(void){
	Systick_init();
	UART_init(1,9600);
	UART_init(2,9600);
	UART_init(3,9600);
	Delayms(10);
	
	while(1){
		// TRUONG HOP 2 THIET BI KHONG CUNG TOC DO BR 
		
		if(UART2_signal == 1){ // UART3_BRR < UART2_BRR
			UART_SEND(3,UART2_msg);
			UART2_signal = 0;
			str_empty(UART2_msg);
		}
		if(UART3_signal == 1){// UART3_BRR < UART2_BRR
			UART_SEND(2,UART3_msg);
			UART3_signal = 0;
			str_empty(UART3_msg);
		}
	}

}


// 2 thiet bi co cung toc do baund rate -> giao tiep qua lai khong can phai qua stm32 (bridge co the != 0)
// 2 thiet bi khong cung toc do baund rate -> giao tiep phai qua stm32 (bridge co the == 0)

void USART2_IRQHandler(){// ham ngat tai USART2 khi tin hieu tai cac chan uart2(tx,rx)
	UART_ISR(2,3,&UART2_signal,&UART2_counter,UART2_msg);
}

void USART3_IRQHandler(){// ham ngat tai USART2 khi tin hieu tai cac chan uart2(tx,rx)
	UART_ISR(3,2,&UART3_signal,&UART3_counter,UART3_msg);
}

