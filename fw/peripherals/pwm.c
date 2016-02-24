// Uses the Timer1 Output Compare mode to drive OC1A and OC1B with the duty
// cycle specified by OCR1A and OCR1B, respectively.

#include "pwm.h"

#include <avr/io.h>
#include "../util.h"

#define TIMER1_TOP (1<<8)

void pwm_enable(void) {
    TCNT1  = 0; // clear counter
    ICR1   = TIMER1_TOP; // set top

    // enable "set on match when up-counting, clear when down-counting" for both OC1A and OC1B
    TCCR1A = MASK1(COM1A1) | MASK1(COM1B1);

    // waveform generation mode: phase+frequency correct PWM; clock select: internal, no prescaler
    TCCR1B = MASK1(WGM13) | MASK1(CS10);
}
