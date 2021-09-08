#ifndef spi_h_
#define spi_h_

#define MOSI 0
#define PORT_MOSI PORTB
#define DDR_MOSI DDRB

#define CLK 1 
#define PORT_CLK PORTB
#define DDR_CLK DDRB

#include <avr/io.h>

void init_spi(void);
void send_byte(uint8_t byte);

#endif