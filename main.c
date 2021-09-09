#include <avr/io.h>
#include <util/delay.h>

#include "led_disp.h"
#include "spi.h"

const uint8_t digits[] = {
    ~0xFC, ~0x60, ~0xDA, ~0xF2, ~0x66, ~0xB6, ~0xBE, ~0xE0, ~0xFE, ~0xF6
};

int main(void){
    led_disp_data_t data;

    DDRB |= (1 << CLK);
    DDRB |= (1 << MOSI);
    PORTB &= ~(1 << CLK);

    DDRB |= (1 << LATCH);
    PORTB &= ~(1 << LATCH);

    data.first = digits[1];
    data.second = digits[2];
    /*
    init_spi();
    init_led();
    _delay_ms(1);
    */


    while(1){
        send_set(&data);
        _delay_ms(1000);
    }
}