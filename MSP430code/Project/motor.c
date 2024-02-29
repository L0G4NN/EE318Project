/******************
*motor.c
*
*Implementation of controlling the
*motors on our vehicle
*
*Logan Noonan
*Daniel Ofem
*TODO:
*Finish Drive()
*Finish Timers function
*Test on hardware
******************/

#include "motor.h"

int direction = 1; //default to forwards

//Set the output pins for ENABLE1&2, and inputs 1A,2A,3A,4A of the motor.
void initMotors()
{
  //TODO: FINISH FUNCTION
  //setup
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN3);
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN4);
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN5);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0);
  
  //init all pins to LOW
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN3);
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN5);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0);
}

void initTimers()
{
}

void _lab_test_()
{
    //TODO: FINISH FUNCTION
    driveForward();
    //start a timer for x amount of time
    //when timer complete - drive backwards
    direction = 0;

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

