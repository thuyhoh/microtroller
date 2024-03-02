#include "stdint.h"

// SPI_BR
#define f_2 	 0
#define f_4 	 1
#define f_16	 2
#define f_32	 4
#define f_64	 5
#define f_128	 6
#define f_256	 7 

#define Master 1
#define Slave  0 

// SPI_CLOCK
#define clk_1 0
#define clk_2 1
#define clk_3 2
#define clk_4 3

// SPI_NSS_MODE
#define NSS_IN 	 2
#define NSS_OUTE 1
#define NSS_OUTD 0


typedef struct {
	uint32_t SPI_Channel  : 2;
	uint32_t SPI_MODE 		: 1; 		// master mode: 1/ slave mode: 0
	uint32_t SPI_DFF 			: 1; 		// data fram format 8bit:0/ 16 bit:1
	uint32_t SPI_LSBFIST 	: 1;
	uint32_t SPI_Clock		: 2;		// chose CPHA vs 
	uint32_t SPI_NSS_MODE : 6;		// = 1 NSS_IN/ = 0 NSS_OUT / != sofware(2 bit MSB-> port(A:01 B:10)), PIN[4 bit LSB]; 	
	uint32_t SPI_BR				: 3;
	char 		 SPI_msg[]		;
}SPI_t;

void SPIx_init(SPI_t SPI_mgr);
