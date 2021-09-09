#ifndef led_disp_h_
#define led_disp_h_

#include <avr/io.h>


//LD (PB2)
#define LATCH 2 
#define PORT_LATCH PORTB
#define DDR_LATCH DDRB

typedef struct{ //dane wysyłane do wyświetlacza
    uint8_t first, second; //pierwszy segment i drugi
}led_disp_data_t;

void init_led(void);
void send_set(const led_disp_data_t* data);

#endif