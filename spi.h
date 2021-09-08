#ifndef spi_h_
#define spi_h_

#include <avr/io.h>

void init_spi(uint16_t baud);
void send_byte(uint8_t byte);

#endif