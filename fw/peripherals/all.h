#ifndef PERIPHERALS_H
#define PERIPHERALS_H


#include <avr/interrupt.h>

#include "gpio.h"
#include "led.h"
#include "pwm.h"
#include "motor.h"

void adc_enable(void);
void comm_enable(void);
void optical_sensor_enable(void);
void all_peripherals_enable(void);


#endif
