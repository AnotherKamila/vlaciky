#include "motor.h"

#include <avr/io.h>
#include "../util.h"
#include "gpio.h"
#include "pwm.h"

volatile uint8_t * const MOTOR_PORT_C = &PORTD;
volatile uint8_t * const MOTOR_DDR_C  = &DDRD;
uint8_t const MOTOR_PIN_C1 = 6;
uint8_t const MOTOR_PIN_C2 = 7;

volatile uint8_t * const MOTOR_PORT_EN = &PORTB;
volatile uint8_t * const MOTOR_DDR_EN  = &DDRB;
uint8_t const MOTOR_PIN_EN = 1;

volatile uint16_t * MOTOR_EN_PWM_CR = &OCR1A;

void motor_enable(void) {
    gpio_set_mode(MOTOR_DDR_C, MOTOR_PIN_C1, GPIO_MODE_OUTPUT);
    gpio_set_mode(MOTOR_DDR_C, MOTOR_PIN_C2, GPIO_MODE_OUTPUT);

    gpio_set_mode(MOTOR_DDR_EN, MOTOR_PIN_EN, GPIO_MODE_OUTPUT);
    pwm_enable();
}

// 0: FW, 1: BW
void motor_set_dir(uint8_t dir) {
    if (dir == 0) {
        *MOTOR_PORT_C |=  MASK1(MOTOR_PIN_C1);
        *MOTOR_PORT_C &= ~MASK1(MOTOR_PIN_C2);
    } else {
        *MOTOR_PORT_C |= ~MASK1(MOTOR_PIN_C1);
        *MOTOR_PORT_C &=  MASK1(MOTOR_PIN_C2);
    }
}

void motor_set_speed(uint8_t speed) {
    *MOTOR_EN_PWM_CR = speed;
}
