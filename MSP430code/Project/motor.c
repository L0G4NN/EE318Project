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
#include <driverlib.h>

//Using LEDs to visualise the motor pulses
#define LED_CATHODE_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7) //set cathode to LOW
#define LED_1_ON GPIO_toggleOutputOnPin(GPIO_PORT_P8, GPIO_PIN0)
#define LED_2_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN1)
#define LED_3_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN2)
#define LED_4_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN3)

#define MOTOR_A_1_FWD GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN3)
#define MOTOR_A_2_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4)

#define MOTOR_A_2_RVRS GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4)
#define MOTOR_A_1_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN3)

#define MOTOR_B_1_FWD GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN5)
#define MOTOR_B_2_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0)

#define MOTOR_B_2_RVRS GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN0)
#define MOTOR_B_1_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN5)


//Set the output pins for ENABLE1&2, and inputs 1A,2A,3A,4A of the motor.
void initMotors()
{
  //TODO: FINISH FUNCTION
  //Initialise pins 1.3,1.4,1.5 and 5.0 for the motor control signals
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN3);
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN4);
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN5);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0);
  
  //init LED visualisation pins
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN7);
  GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN2);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN3);

  //init all pins to LOW
//  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN3);
//  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);
//  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN5);
//  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0);

  GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN2);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
}

void initTimers() //taken from Timers Lab
{
    //TODO: FINISH FUNCTION
}

void delay_us(int microseconds)
{
    while(microseconds--)
    {
        __delay_cycles(1);
    }
}

void _lab_test_()
{
    //TODO: FINISH TEST FUNCTION

    drive('w');
}

void drive(char signal)
{
    //TODO: FINISH FUNCTION
    LED_CATHODE_OFF;
    if(signal == 'w') //drive forwards
    {
        //IN1 AND IN3 TOGGLED HIGH, IN2 AND IN4 LOW
        MOTOR_A_1_FWD;
        MOTOR_A_2_OFF;
        MOTOR_B_1_FWD;
        MOTOR_B_2_OFF;

        //REPRESENT ON LEDs ALSO FOR VISUALISATION
        LED_1_ON;
        LED_3_ON;
        LED_CATHODE_OFF;

        //delay
        delay_us(10000); //NOT A TRUE VALUE - WILL NEED TO CHANGE
    }
    else if(signal == 'a') //turn left
    {
    }
    else if(signal == 'd') //turn right
    {
    }
    else if(signal == 's') //backwards
    {
    }
}

