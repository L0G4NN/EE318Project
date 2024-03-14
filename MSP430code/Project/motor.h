/******************
motor.h

Logan Noonan

PORT 1 PINS 3,4,5 AND PORT 5 PINS 0
******************/

#ifndef MOTOR_H
#define MOTOR_H

#include <msp430.h>
#include <driverlib.h>

//initialisation functions
void initMotors();
void initADC(); //setup ADC for PWM control
void initPWMTimers(); //setup timers for PWM control
//UNSURE IF INITADC AND INITTIMERS ARE REALLY NEEDED AS THEY ARE SETUP IN MAIN

//action functions
void drive(char bluetooth_signal);
void accel_rate(); //function in how fast we drive spin the motors
void delay_us(int microseconds);

void _lab_test_(); //simple function to test the hardware

#endif //MOTOR_H
