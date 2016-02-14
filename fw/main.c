#include <stdio.h>
#include <stdlib.h>

#include "Csucks.h"
#include "state.h" // declares the `state` global
#include "peripherals/all.h"

void set_output(state st) {
    motor_set_dir(st.speed < 0);
    motor_set_speed(((uint16_t)abs(st.speed)) >> 8);
    led_set_brightness(st.light >> 8);
}

void main(void) {
    all_peripherals_enable();
    sei();

    set_state((state){ .speed = 0xefff, .light = 0x8fff });
    while (1) {
        set_output(real_state_frame());
    }
}
