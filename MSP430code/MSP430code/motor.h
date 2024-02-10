/******************
motor.h

Logan Noonan
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include "utils.h"
#include <msp430.h>

//list of functions

void initGPIO();
void lab_test_();

//unsure if needed yet
void drive();
void turnLeft();
void turnRight();
void reverse();
void accel_rate(); //function in how hard we drive / reverse?


#endif //MOTOR_H
