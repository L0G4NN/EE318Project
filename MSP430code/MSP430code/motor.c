/******************
*motor.c
*
*Implementation of controlling the
*motors on our vehicle
*
*Logan Noonan
*Daniel Ofem
*TODO:
*Finish ADC function
*Finish Test()
*Finish Drive()
*Finish Timers function
******************/

#include "motor.h"

//Set the output pins for ENABLE1&2, and inputs 1A,2A,3A,4A of the motor.
void initGPIO()
{
  //TODO: FINISH FUNCTION
  //return false; //an error occurred initialising the motor controller
  //setup
  GPIO_setAsOutputPin(0, 0);
}


void initADC()
{
    //TODO: FINISH FUNCTION
    //setup the ADC for a PWM signal to control the speed
}

void initTimers()
{
}

void _lab_test_()
{
    //TODO: FINISH FUNCTION
    int direction = 1; //forward
    drive(direction);
    //start a timer for x amount of time
    //when timer complete - drive backwards
    direction = 0;
    drive(direction);

    //spin left wheel only
    turnLeft();
    //wait for a bit
    turnRight();
}

void driveForward()
{
    //TODO: FINISH FUNCTION
    if(direction == 1)
    {
        //if == 1, go forwards
    }
    else
    {
        //go backwards
    }
}

void driveBackward()
{
}
