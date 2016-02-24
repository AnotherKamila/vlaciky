#include "state.h"

volatile state intended_state;
volatile state real_state = INITIAL_REAL_STATE;

// Easing parameters for the state fields.
// Must be >1 to avoid overflow down there.
#define FORCE_K 32
#define LIGHT_K 16

void set_state(state st) { intended_state = st; }
state get_state(void) { return intended_state; }
state get_real_state(void) { return real_state; }

// Adjusts `x` towards `intended`, with some "stickiness/inertia".
int32_t ease(int32_t x, int32_t intended, int32_t k) {
    int32_t delta = (intended - x)/k;
    return x + delta;
}

void real_state_frame(void) {
    real_state.light = ease(real_state.light, intended_state.light, LIGHT_K);
    real_state.speed = ease(real_state.speed, intended_state.speed, FORCE_K);
}
