/******************
motor.h

Logan Noonan
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
//#include <driverlib.h>

//initialisation functions
void initGPIO();
void initADC(); //setup ADC for PWM control
void initTimers(); //setup timers for PWM control
//UNSURE IF INITADC AND INITTIMERS ARE REALLY NEEDED AS THEY ARE SETUP IN MAIN

void _lab_test(); //simple function to test the hardware

//action functions
void driveForward();
void driveBackward();
void turnLeft();
void turnRight();
void accel_rate(); //function in how fast we drive spin the motors


#endif //MOTOR_H
