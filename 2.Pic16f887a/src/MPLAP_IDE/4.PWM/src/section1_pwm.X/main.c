/*
 * File:   main.c
 * Author: PC
 *
 * Created on December 30, 2023, 8:40 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 20000000

void setPWMdutycycle(unsigned int duty){
    CCPR1L = duty>>2;
    CCP1CON = CCP1CON & 0xCF;
    CCP1CON = CCP1CON & (0x30 & (duty << 4));
}

unsigned int i;

void main(void) {
    TRISC = 0x00;
    CCP1CON = 0x0C;
    PR2 = 0xFF;
    T2CON = 0x04;
    while(1){
        for(i = 0; i< 1023; i++){
            setPWMdutycycle(i);
            __delay_ms(2);
        }
    }
    return;
}
