#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include "Csucks.h"
#include "state.h"
#include "peripherals/all.h"
#include "util.h"
#include <avr/io.h>

void set_output(state st) {
    motor_set_dir(st.speed < 0);
    motor_set_speed(((uint16_t)abs(st.speed)) >> 8);
    led_set_brightness(st.light >> 8);
}

ISR(TIMER2_OVF_vect) {
    real_state_frame();
    set_output(get_real_state());
}

void main(void) {
    all_peripherals_enable();
    sei();

    while (1) {
        set_state((state){ .speed = 0xffff, .light = 0xffff });
        _delay_ms(300);
        set_state((state){ .speed = 0x8fff, .light = 0x0 });
        _delay_ms(200);
    }
}
