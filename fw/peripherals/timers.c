#include "timers.h"

#include <avr/io.h>
#include "../util.h"

void timer2_enable() {
    TCCR2 = MASK1(CS21) | MASK1(CS20); // start timer2 with /32 prescaler
    TIMSK = MASK1(TOIE2); // enable timer2 interrupt
    TCNT2 = 0; // reset counter
}
