/******************
* motor.c
*
* Implementation of controlling the
* motors on our vehicle
*
* Logan Noonan
*
*
* Useful references
* https://dev.ti.com/tirex/explore/node?node=A__AMqhsgBhm3-jH1WI3FE0eA__msp430ware__IOGqZri__LATEST
* Brock J. LaMers - Embedded Systems Design
* http://www.msp430launchpad.com/2010/07/timers-and-clocks-and-pwm-oh-my.html
******************/

#include "motor.h"
#include <driverlib.h>

//Set the output pins for ENABLE1&2, and inputs 1A,2A,3A,4A of the motor.
void initMotors()
{
    //MOTOR PORTS
    /*
     *  Motor A - P2.5, P1.6 -- Left hand sidew  --TODO reevaluate to see how much of a mess the wires are
     *  Motor B - P1.5, P5.0 -- Right hand side
     */

    P2DIR |= BIT5;
    P1DIR |= BIT6;
    P1DIR |= BIT5;
    P5DIR |= BIT0;

    //LED VISUALISATION PORTS
    P2DIR |= BIT7;
    P2OUT &= ~BIT7;  //set 2.7 cathode LOW

    P8DIR |= BIT0;  //LED1
    P5DIR |= BIT1;  //LED2
    P5DIR |= BIT2;  //LED3
    P5DIR |= BIT3;  //LED4

    //INIT ALL LOW
    P2OUT &= ~BIT5;
    P1OUT &= ~BIT6;
    P1OUT &= ~BIT5;
    P5OUT &= ~BIT0;

    P8OUT &= ~BIT0;
    P5OUT &= ~BIT1;
    P5OUT &= ~BIT2;
    P5OUT &= ~BIT3;

}

void initPWMTimers()
{
    //SETUP PORTS
    P4DIR |= BIT0;
    P4OUT &= ~BIT0;  //P4.0 LED initially set to LOW

    //Setup timer control registers
    TA0CTL |= TACLR;    // -- clear the timer to init
    TA0CTL |= TASSEL__SMCLK; //init ACLK 32.768kHz
    //TA0CTL |= ID__8;  //Divide ACLK by 8 - 4.096kHz
    TA0CTL |= MC__UP;   //Set UP mode

    //Capture compare registers
    TA0CCR0 = 32768;    //delta t = T * N - set PWM period
    TA0CCR1 = TA0CCR0 - 25000;  //Amount of LOW time in the signal -- USERGUIDE page 329

    TA0CCTL0 |= CM_1;   //Rising edge
    TA0CCTL0 |= CCIS_1;   //compare to the value stored in CCR1
    TA0CCTL0 |= OUTMOD_7;

    TA0CCTL0 |= CCIE;   //local interrupt enable for CCR0
    TA0CCTL1 |= CCIE;

    //clear any interrupts
    TA0CCTL0 &= ~CCIFG;
    TA0CCTL1 &= ~CCIFG;
}


char _lab_test_(char signal)
{
    //TODO: FINISH TEST FUNCTION
    char _signal = signal;
    //char signals[] = {'w','a','s','d'};
    return _signal;
}



void drive(char signal)
{
    static volatile int STATE;
    STATE ^= 1;
    switch(signal) {

        case 'w':
            if(STATE)           //Go forwards
            {
                P2OUT ^= BIT5;
                P1OUT ^= BIT5;

                P8OUT ^= BIT0;
                P5OUT ^= BIT2;
                STATE = !STATE;
            }
            break;

        case 'a':
            //Toggle RIGHT motor, LEFT motor stationary
            if(STATE)
            {
                P1OUT ^= BIT6;  //Motor A backwards
                P1OUT ^= BIT5;  //Motor B forwards

                P5OUT ^= BIT1;
                P5OUT ^= BIT2;
                STATE = !STATE;
            }
            break;

        case 'd':
            //Toggle LEFT motor, RIGHT motor stationary -- maybe backwards?
            if(STATE)
            {
                P2OUT ^= BIT5;
                P5OUT ^= BIT0;

                P8OUT ^= BIT0;
                P5OUT ^= BIT3;
                STATE = !STATE;
            }
            break;

        case 's':
            //Toggle backwards pins
            if(STATE)
            {
                P1OUT ^= BIT6;
                P5OUT ^= BIT0;

                P5OUT ^= BIT1;
                P5OUT ^= BIT3;
                STATE = !STATE;
            }
            break;

        default:
            //Stay still -- all pins written to LOW
            if(STATE)
            {
                P2OUT &= ~BIT5;
                P1OUT &= ~BIT6;
                P1OUT &= ~BIT5;
                P5OUT &= ~BIT0;

                P8OUT &= ~BIT0;
                P5OUT &= ~BIT1;
                P5OUT &= ~BIT2;
                P5OUT &= ~BIT3;
            }
            break;
    }
}


