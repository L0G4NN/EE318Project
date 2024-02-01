/******************
motor.h

Logan Noonan
updated 1 feb 2024
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
#include <driverlib.h>

//list of functions

bool initGPIO();
void initADC();
void lab_test_();

//unsure if needed yet
void drive();
void turnLeft();
void turnRight();
void reverse();
void accel_rate(); //function in how hard we drive / reverse?


#endif //MOTOR_H