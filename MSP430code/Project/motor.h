/******************
    motor.h

    Logan Noonan
    UPDATED 18/04/2024
    - Updated testing function return type and arguments 
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
#include <driverlib.h>

//initialisation functions
void initMotors();
void initPWMTimers();   //setup timers for PWM control

void drive(char bluetooth_signal);

char _lab_test_(char signal);  //simple function to test the hardware

#endif //MOTOR_H
