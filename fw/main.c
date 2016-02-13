#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>

#include "Csucks.h"
#include "state.h"
#include "peripherals.h"

////////////////////////////////////////////////////////////////////////////////

// Must be >1 to avoid overflow down there.
#define FORCE_K 256
#define LIGHT_K 16

// Adjusts `x` towards `intended`, with some "stickiness/inertia".
int32_t ease(int32_t x, int32_t intended, int32_t k) {
    int32_t delta = (x - intended)/k;
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
    enable_all_peripherals();
    sei();

    state.speed = 255; state.light = 128;
    main_loop();
}
