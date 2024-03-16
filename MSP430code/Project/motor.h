/******************
    motor.h

    Logan Noonan

    PORT 1 PINS 5,6,7 AND PORT 5 PINS 0
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
#include <driverlib.h>

//initialisation functions
void initMotors();
void initPWMTimers();   //setup timers for PWM control

void drive(char bluetooth_signal);
void delay_us(int microseconds);

void _lab_test_();  //simple function to test the hardware

#endif //MOTOR_H
