#ifndef PERIPHERALS_MOTOR_H
#define PERIPHERALS_MOTOR_H


#include "../Csucks.h"

void motor_enable(void);
void motor_set_dir(uint8_t dir); // 0: FW, 1: BW
void motor_set_speed(uint8_t speed);


#endif
