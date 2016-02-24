#include "all.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../util.h"

void adc_enable(void) {
    // TODO
}

void comm_enable(void) {
    // TODO
}

void optical_sensor_enable(void) {
    adc_enable();
    // TODO
}

void all_peripherals_enable(void) {
    comm_enable();
    optical_sensor_enable();
    motor_enable();
    led_enable();
    timer2_enable();
}
