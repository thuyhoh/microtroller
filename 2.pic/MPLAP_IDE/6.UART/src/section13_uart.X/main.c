/*
 * File:   main.c
 * Author: PC
 *
 * Created on January 1, 2024, 10:52 PM
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

unsigned char y[10];    
int k = 0;
void interrupt receive(){
    if(PIR1bits.RCIF == 1){
        y[k] = RCREG;
        k++;
        PIR1bits.RCIF = 0;
    }
}

//transmit one data
void tx(unsigned char data){
    if(PIR1bits.TXIF == 1){
        TXREG = data;
        PIR1bits.TXIF = 0;
    }
}

void string_tx(const char *str){
    int i = 0;
    while(str[i] != '\0'){
        tx(str[i]);
        i++;
        __delay_ms(200);
    }
}

void main(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1; // cho phep nhan
    PIE1bits.TXIE = 1; // cho phep truyen
    
    
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 129;
    
    
    while(1){
        string_tx("hello");
        
    }
    return;
}
