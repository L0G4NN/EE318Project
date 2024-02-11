/******************
motor.c

Implementation of controlling the
motors on our vehicle

Logan Noonan
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

void _lab_test_()
{
    //TODO: FINISH FUNCTION
    //simple function to test the hardware
    int direction = 1;
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

void drive(int direction)
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
