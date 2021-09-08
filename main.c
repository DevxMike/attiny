#include <avr/io.h>
#include "led_disp.h"

const uint8_t digits[] = {
    ~0xFC, ~0x60, ~0xDA, ~0xF2, ~0x66, ~0xB6, ~0xBE, ~0xE0, ~0xFE, ~0xF6
};

int main(void){
    led_disp_data_t data;

    init_led();
    while(1){

    }
}