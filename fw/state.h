#ifndef STATE_H
#define STATE_H


#include "Csucks.h"

typedef struct state_data {
    int32_t  speed;
    uint16_t light;
} state_data;

// This global may be set in response to various real-world events.
// Intended use: set in interrupts when the sensors (or timer) say something
// interesting.
// The main loop will make sure this is reflected by the peripherals.
extern volatile state_data state;


#endif
