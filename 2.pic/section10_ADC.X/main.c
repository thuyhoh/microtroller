/*
 * File:   main.c
 * Author: PC
 *
 * Created on December 26, 2023, 4:15 PM
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



#define _XTAL_FREQ = 20000000

#define RS PORTDbits.RD0
#define RW PORTDbits.RD1
#define EN PORTDbits.RD2

int adc, tmp;
float temperature, adc1;    


void lcd_data(unsigned char data){
    PORTC = data;
    RS = 1;
    EN = 0;
    EN = 1;
    __delay_ms(1);
    EN = 0;
}

// hàm truy?n l?nh
void lcd_command(unsigned char cmd){
    PORTC = cmd;
    RS = 0;
    EN = 0;
    EN = 1;
    __delay_ms(1);
    EN = 0;
}

void lcd_string(unsigned char *str, unsigned char n){
    unsigned char i;
    for(i = 0; i< n; i++){
        lcd_data(str[i]);
    }
}

void lcd_clear(){
    lcd_command(0x01);
}

void lcd_coursor(unsigned int col,unsigned int row){
    if(row == 0){
        lcd_command(0x80+col);
    }else if(row == 1){
        lcd_command(0xC0+col);
    }
}

void lcd_shilf_left(){
    lcd_command(0x10);
}

void lcd_shilf_right(){
    lcd_command(0x14);
}

// kh?i t?o lcd
void lcd_initialise(){
    lcd_command(0x38);// seting type of lcd (16x2)
    lcd_command(0x06);// t?ng con tr? c?a lcd sau khi có m?t ký t? ???c hoàn thành
    lcd_command(0x0C);// l?nh b?t/t?t con tr? c?a lcd
    lcd_command(0x81);// clear lcd
}


void interrupt adc_convert(){
    if(PIR1bits.ADIF == 1){
        adc = (ADRESH<<8);
        adc = adc | ADRESL;
        PIR1bits.ADIF = 0;
        
    }
}

void main(void) {
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    
    
    // lcd
    TRISD = 0x00;
    TRISC = 0x00;
    
    PORTC = PORTD = 0x00;
    lcd_initialise();
    lcd_coursor(0,0);
    lcd_string("sensor: ",6);
    
    ADCON0 =  0x41;
    ADCON1 =  0x8E;
    
    while(1){
        ADCON0 = ADCON0 | (0x04); // set bit 3 GONE
        
        adc1 = adc/2.046;
        temperature = adc1*100;
        lcd_coursor(7,0);
        
    }
    
    
    return;
}
