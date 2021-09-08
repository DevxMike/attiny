#include "led_disp.h"
#include "spi.h"

void init_led(void){
    init_spi();
}

void send_set(const led_disp_data_t* data){
    send_byte(data->second);
    send_byte(data->first);
    PORT_LATCH |= (1 << LATCH); //wyłącz wyjścia rejestrów i przenieś zawartość rejestru przesuwnego do wyjść
    PORT_LATCH &= ~(1 << LATCH); //włącz wyjścia
}