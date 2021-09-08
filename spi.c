#include "spi.h"
#include <util/delay.h>

void init_spi(void){
    DDR_CLK |= (1 << CLK);
    DDR_MOSI |= (1 << MOSI);
}

void send_byte(uint8_t byte){
    for(uint8_t i = 0; i < 8; ++i){
        _delay_us(2);
        PORT_CLK |= (1 << CLK);
        
        if(byte & (1 << i)){
            if(!(PORT_MOSI & (1 << MOSI))){
                PORT_MOSI |= (1 << MOSI);
            }
        }
        else{
            PORT_MOSI &= ~(1 << MOSI);
        }

        _delay_us(2);
        PORT_CLK &= ~(1 << CLK);
    }
}