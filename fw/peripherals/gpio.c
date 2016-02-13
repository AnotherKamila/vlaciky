#include "gpio.h"

#include <avr/io.h>
#include "../util.h"

void gpio_set_mode(volatile uint8_t *port, uint8_t pin, enum gpio_mode mode) {
    if (mode == GPIO_MODE_INPUT) {
        *port &= ~MASK1(pin);
    } else {
        *port |= MASK1(pin);
    }
}
