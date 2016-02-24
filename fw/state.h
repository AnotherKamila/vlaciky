// Provides a global state container.
//
// Instead of independent weirdly interacting "input -> output" spaghetti, input
// events should only set this explicit state and output should depend only on
// the state (so that we have only "input -> state" and "state -> output", and
// state is reconciled properly).
// (Here "input" means "any events incoming from the real world (such as rail
// mark observed, comm signal, or timer expired" and "output" means "action
// visible in the real world (such as changing train speed)".)
//
// Also, state hides fun details (such as simulating inertia). Therefore the
// "real" state as it should appear in the real world may be different from the
// "intended" state as set by input handlers (but will eventually converge).
//
// The main loop should make sure the real state is reflected by the
// peripherals.

#ifndef STATE_H
#define STATE_H


#include "Csucks.h"

typedef struct state {
    int32_t  speed;
    uint16_t light;
} state;

// Set the (intended) state.
// State may be set in response to various real-world events.
// Intended use: call in interrupts when the sensors (or timer) say something
// interesting.
void set_state(state st);

// Get the current (intended) state.
state get_state(void);

// Get the current real state (which may be different from the intended state,
// as we are simulating inertia and such.)
state get_real_state(void);

// Update the real state in response to the intended state. Must be called in
// regular intervals (e.g. from a timer).
void real_state_frame(void);

// "real real state" (what things look like when the device is turned on)
#define INITIAL_REAL_STATE { .speed = 0, .light = 0 }


#endif
