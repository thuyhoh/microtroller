
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

int adc, tmp;
float temperature, adc1;

void interrupt_setup(){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
}

void adc_init(){
    ADCON0 =  0x41;
    ADCON1 =  0x8E;
}

void interrupt adc_convert(){
    if(PIR1bits.ADIF == 1){
        adc = (ADRESH<<8);
        adc = adc | ADRESL;
        PIR1bits.ADIF = 0;
        
    }
}

float temprature(){
    float temp;
    temp = (adc/2.046)*100;
    return temp;
}

void main(void){
    interrupt_setup();
    adc_init();
    
    while(1){
        float a = temprature();
    }
    return;
}