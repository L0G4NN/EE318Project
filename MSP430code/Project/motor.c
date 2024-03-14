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
*https://dev.ti.com/tirex/explore/node?node=A__AMqhsgBhm3-jH1WI3FE0eA__msp430ware__IOGqZri__LATEST
******************/

#include "motor.h"
#include <driverlib.h>

//Set the output pins for ENABLE1&2, and inputs 1A,2A,3A,4A of the motor.
void initMotors()
{
}

/*
 * void initTimers()
{

    //TODO: CAN SET THE PWM SIGNAL ONTO PORT 4 PIN 0 - ONBOARD LED FINE. NEED TO SETUP PWM ONTO THE OUTPUT PINS AND MEASURE RESPONSE IN THE LAB
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P4, GPIO_PIN0, GPIO_PRIMARY_MODULE_FUNCTION);
    //GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    int DUTY_CYCLE = 850; //In OUTPUTMODE_SET_RESET the duty cycle value is the value of "downtime" in the PWM signal.
    int TIMER_A_PERIOD = 1000;

    //TODO: FINISH FUNCTION -
    // HAVE A TOTAL OF 4 PWM SIGNALS RUNNING AT THE ONE TIME - WHERE 2 ARE ALWAYS CONSTANT LOW(CONSTANT LOW UNTIL THEY ARE NEEDED FOR REVERSE)
    // HAVE THE 2 PWM SIGNALS PULSING AT THE SAME RATE UNTIL A DIRECTIONAL CHANGE OCCURS

    Timer_A_outputPWMParam param = {0};
    param.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
    param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_32;
    param.timerPeriod = TIMER_A_PERIOD;
    param.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1; //ERROR MAYBE HERE?
    param.compareOutputMode = TIMER_A_OUTPUTMODE_SET_RESET;
    param.dutyCycle = DUTY_CYCLE;

    Timer_A_outputPWM(TIMER_A1_BASE, &param);

    __bis_SR_register(LPM0_bits); //accidently deleted this and broke everything
}
 *
 */

void initTimers()
{
    //SETUP TIMERS
    TA0CTL |= TACLR;

    TA0CTL |= TASSEL__ACLK; //init ACLK
    TA0CTL |= ID__8; //Divide ACLK by 8
    TA0CTL |= MC_1; //Set UP mode

    //Capture compare registers
    TA0CCR0 = 1000;
    TA0CCR1 = 150;

    //Enable interrupts on capture compare

    TA0CCTL0 |= CM_1; //Rising edge
    TA0CCTL0 |= CCIS_0; //compare to the value stored in CCR0
    TA0CCTL0 |= OUTMOD_7;
    TA0CCTL0 |= CCIE;




    //SETUP PORTS
    P4DIR = BIT0;
    P4OUT &= ~BIT0;

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
    if(signal == 'w') //drive forwards
    {
        initTimers();
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

