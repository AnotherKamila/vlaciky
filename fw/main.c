#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "Csucks.h"

#define FORCE_K 16

enum state_type {
    ST_STOP    = 1,
    ST_FORWARD = 2,
};

volatile enum state_type state;  // may be changed from interrupts or whatever

void state_machine(void) {
    int16_t current_speed = 0;
    int16_t intended_speed;

    while (1) {
        switch (state) {

            case ST_STOP:
                intended_speed = 0;
                break;

            case ST_FORWARD:
                intended_speed = 255;
                break;
        }

        // adjust speed, simulating inertia (somehow...)
        int16_t delta = (intended_speed - current_speed)/FORCE_K;
        current_speed += delta;
        // TODO write somewhere for PWM adjustment
    }
}

int main(void) {
    // TODO initialization of PWM and sensors and comm and whatever
    state = ST_FORWARD;
    state_machine();
}
