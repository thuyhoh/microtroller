/*
 * File:   main.c
 * Author: PC
 *
 * Created on December 21, 2023, 7:04 PM
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

unsigned char timer_counter = 0;


void interrupt setup_timer0(){ // setup timer0 co do tre la 10ms
    if(INTCONbits.TMR0IF == 1){
        timer_counter++;
        INTCONbits.TMR0IF = 0;
    }
}


void main(void) {
    
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
//    OPTION_REG = 0x07;
    OPTION_REGbits.INTEDG = 0; // dem xuong tu gt TMR0 -> 0
    
//    dat bo chia 1/256
    OPTION_REGbits.T0CS = 0;// chon xung noi
    OPTION_REGbits.PSA = 0;// chon bo chia timer0
    
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 1;

    TMR0 = 59; // tim dc theo cong thuc 
    TRISB0 = 0;
    while(1){
        if(timer_counter == 0){
            PORTBbits.RB0 = 1;
        }
        if(timer_counter == 50){
            PORTBbits.RB0 = 0;
        }
        if(timer_counter == 200){
            timer_counter = 0;
        }
    }
    
    return;
}
