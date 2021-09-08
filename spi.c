#include "spi.h"
#include <util/delay.h>

void init_spi(void){
    DDR_CLK |= (1 << CLK);
    DDR_MOSI |= (1 << MOSI);
    PORT_CLK &= ~(1 << CLK);
}

void send_byte(uint8_t byte){
    for(uint8_t i = 0; i < 8; ++i){
        if(byte & (1 << i)){
            if(!(PORT_MOSI & (1 << MOSI))){
                PORT_MOSI |= (1 << MOSI);
            }
        }
        else{
            PORT_MOSI &= ~(1 << MOSI);
        }
        
        PORT_CLK |= (1 << CLK);
        _delay_us(2.0);
        PORT_CLK &= ~(1 << CLK);
        _delay_us(2.0);
    }
}