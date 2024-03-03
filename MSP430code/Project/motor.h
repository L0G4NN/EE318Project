/******************
motor.h

Logan Noonan

PORT 1 PINS 3,4,5 AND PORT 5 PINS 0
PORT 5 PINS 1,2,3 AND PORT 8 PIN
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
#include <driverlib.h>
#include "bluetooth.h"

//initialisation functions
void initTimers(); //setup timers for PWM control

//action functions
void drive(char bluetooth_signal);
void accel_rate(); //function in how fast we drive spin the motors
void delay_us(int microseconds);

void _lab_test(); //simple function to test the hardware

#endif //MOTOR_H
