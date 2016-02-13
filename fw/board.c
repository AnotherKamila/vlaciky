#include "board.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void enable_adc(void) {
    // TODO
}

void enable_gpio(void) {
    // TODO
}

void enable_pwm(void) {

}

void enable_comm(void) {
    enable_gpio();
    // TODO
}

void enable_optical_sensor(void) {
    enable_adc();
    // TODO
}

void enable_motor(void) {
    enable_gpio();
    enable_pwm();
    // TODO
}

void enable_led(void) {
    enable_pwm();
    // TODO
}

void enable_all_peripherals(void) {
    enable_comm();
    enable_optical_sensor();
    enable_motor();
    enable_led();
}

void set_output(state_data state) {
    // TODO set motor C1, C2, PWM
    // TODO set LED PWM
}
