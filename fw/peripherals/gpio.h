#ifndef PERIPHERALS_GPIO_H
#define PERIPHERALS_GPIO_H


#include "../Csucks.h"

enum gpio_mode {
    GPIO_MODE_INPUT  = 0,
    GPIO_MODE_OUTPUT = 1,
};

void gpio_set_mode(volatile uint8_t *port, uint8_t pin, enum gpio_mode mode);


#endif
