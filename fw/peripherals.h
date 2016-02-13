#ifndef PERIPHERALS_H
#define PERIPHERALS_H


#include "Csucks.h"
#include "state.h"

// TODO wiring/stuff

void enable_adc(void);
void enable_gpio(void);
void enable_pwm(void);
void enable_comm(void);
void enable_optical_sensor(void);
void enable_motor(void);
void enable_led(void);
void enable_all_peripherals(void);

void set_output(state_data state);


#endif
