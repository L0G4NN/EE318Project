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
*
* https://dev.ti.com/tirex/explore/node?node=A__AMqhsgBhm3-jH1WI3FE0eA__msp430ware__IOGqZri__LATEST
******************/

#include "motor.h"
#include <driverlib.h>

//Using LEDs to visualise the motor pulses
#define LED_CATHODE_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7) //set cathode to LOW
#define LED_1_ON GPIO_toggleOutputOnPin(GPIO_PORT_P8, GPIO_PIN0)
#define LED_2_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN1)
#define LED_3_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN2)
#define LED_4_ON GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN3)

//MOTORS A AND B
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
}

void initTimers() //taken from Timers Lab
{

    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P4, GPIO_PIN0, GPIO_PRIMARY_MODULE_FUNCTION);
    int DUTY_CYCLE = 100;
    int TIMER_A_PERIOD = 1000;
    //TODO: FINISH FUNCTION - INITIALISE THE TIMERS FOR PWM
    Timer_A_outputPWMParam param = {0};
    param.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
    param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_32;
    param.timerPeriod = TIMER_A_PERIOD;
    param.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1;
    param.compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET;
    param.dutyCycle = DUTY_CYCLE;

    Timer_A_outputPWM(TIMER_A1_BASE, &param);
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

}


