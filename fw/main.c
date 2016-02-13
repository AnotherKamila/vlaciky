#include <stdio.h>
#include <stdlib.h>

#include "Csucks.h"
#include "state.h"
#include "peripherals/all.h"

////////////////////////////////////////////////////////////////////////////////

void set_output(state_data state) {
    cli(); // let's say we want this to be atomic
    motor_set_dir(state.speed < 0);
    motor_set_speed((uint16_t)abs(state.speed) >> 8);
    led_set_brightness(state.light >> 8);
    sei();
}

// Must be >1 to avoid overflow down there.
#define FORCE_K 256
#define LIGHT_K 16

// Adjusts `x` towards `intended`, with some "stickiness/inertia".
int32_t ease(int32_t x, int32_t intended, int32_t k) {
    int32_t delta = (intended - x)/k;
    return x + delta;
}

#define INITIAL_REAL_STATE { .speed = 0, .light = 0 }

// Transitions from the real current state to the intended state
void main_loop(void) {
    state_data real = INITIAL_REAL_STATE;
    volatile state_data *intended = &state; // alias to that global

    while (1) {
        real.speed = ease(real.speed, intended->speed, FORCE_K);
        real.light = ease(real.light, intended->light, LIGHT_K);

        set_output(real);
    }
}

////////////////////////////////////////////////////////////////////////////////

void main(void) {
    all_peripherals_enable();
    sei();

    state.speed = 0xefff; state.light = 0x8fff;
    main_loop();
}
