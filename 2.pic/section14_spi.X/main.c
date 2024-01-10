

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



#include<xc.h> // include processor files - each processor file is guarded.  
#define _XTAL_FREQ 20000000

unsigned int a;
void spi_write  (unsigned int value)
{
		SSPBUF = value;
		while(!SSPSTATbits.BF);
}
unsigned char spi_read()
{
  SSPBUF = 0x00;                // initiate bus cycle
  while(!PIR1bits.SSPIF);  // wait until cycle complete
  return ( SSPBUF );            // return with byte read	
}
void write_to_25AA106A(unsigned char msb, unsigned char lsb, unsigned char data)
{
         PORTBbits.RB0 = 0;
			         spi_write(0x02);
			         spi_write(msb);
			         spi_write(lsb);
			         spi_write(data);
         PORTBbits.RB0 = 1;
         
	
}
void  read_from_25AA160A(unsigned char msb, unsigned char lsb)
{
	         PORTBbits.RB0 = 0;
			         spi_write(0x03);
			         spi_write(msb);
			         spi_write(lsb);
		             while( !SSPSTATbits.BF );
			         a = (spi_read());  
                   PORTBbits.RB0 = 1;
}
void main()
{
  

  TRISCbits.TRISC3  =  0;        //   SERIAL CLOCK AS OUTPUT
  TRISCbits.TRISC4  = 1;       //  MISO AS INPUT
  TRISCbits.TRISC5  = 0;       // MOSI AS OUTPUT
  TRISBbits.TRISB0  = 0;       // SLAVE SELECT PIN AS OUTPUT

SSPCON = 0x20;
SSPSTAT = 0x00;


            PORTBbits.RB0 = 0;      // slave select low
            spi_write(0x06);
            PORTBbits.RB0 = 1;    // slave select high

            write_to_25AA106A(0x03,0x43,0x09);  // 0x0343 = 09
            __delay_ms(1000);

            PORTBbits.RB0 = 0;   // slave select low
            spi_write(0x04);
            PORTBbits.RB0 = 1;  // slave select high

            __delay_ms(1000);
            read_from_25AA160A(0x03,0x43);
while(1)
{





}
return;
}