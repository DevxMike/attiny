#include "led_disp.h"
#include "spi.h"
#include <util/delay.h>

void init_led(void){
    init_spi();
}

void send_set(const led_disp_data_t* data){
    send_byte(data->second);
    send_byte(data->first);
    PORT_LATCH |= (1 << LATCH); //wyłącz wyjścia rejestrów i przenieś zawartość rejestru przesuwnego do wyjść
    _delay_us(1.0);
    PORT_LATCH &= ~(1 << LATCH); //włącz wyjścia
}