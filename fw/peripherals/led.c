#include "led.h"

#include <avr/io.h>
#include "../util.h"
#include "gpio.h"
#include "pwm.h"

// connected to OC1B
volatile uint8_t * const LED_PORT = &PORTB;
volatile uint8_t * const LED_DDR  = &DDRB;
uint8_t const LED_PIN = 2;
volatile uint16_t * LED_PWM_CR = &OCR1B;

void led_enable(void) {
    gpio_set_mode(LED_DDR, LED_PIN, GPIO_MODE_OUTPUT);
    pwm_enable();
}

void led_set_brightness(uint8_t brightness) {
    *LED_PWM_CR = brightness;
}
