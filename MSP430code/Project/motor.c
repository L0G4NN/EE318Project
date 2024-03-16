/******************
* motor.c
*
* Implementation of controlling the
* motors on our vehicle
*
* Logan Noonan
*
* TODO:
* Finish Drive()
* Test on hardware
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
     * Motor A - P1.7, P1.6 -- Left hand side
     * Motor B - P1.5, P5.0 -- Right hand side
     */

    P1DIR |= BIT7;
    P1DIR |= BIT6;
    P1DIR |= BIT5;
    P5DIR |= BIT0;

    //LED VISUALISATION PORTS
    P2DIR |= BIT7;
    P2OUT &= ~BIT7;  //set 2.7 cathode LOW

    P8DIR |= BIT0;  //LED1
    P5DIR |= BIT1;  //LED2
    P5DIR |= BIT2;  //LED3
    P5DIR |= BIT4;  //LED4
}

void initPWMTimers()
{
    //SETUP PORTS
<<<<<<< HEAD
    //P4DIR |= BIT0;
    //P4OUT |= BIT0; //P4.0 LED initially set to HIGH
=======
    P4DIR |= BIT0;
    P4OUT |= BIT0;  //P4.0 LED initially set to HIGH
    P1OUT |= BIT7;
<<<<<<< Updated upstream
=======
>>>>>>> 131714a7287d26c2590c3ac68f6e3e18d221dd6a
>>>>>>> Stashed changes

    //Setup timer control registers
    //TA0CTL |= TACLR;    // -- clear the timer to init
    TA0CTL |= TASSEL__ACLK; //init ACLK 32.768kHz
    TA0CTL |= ID__8;  //Divide ACLK by 8 - 4.096kHz
    TA0CTL |= MC__UP;   //Set UP mode

    //Capture compare registers
    //TODO: FIGURE OUT APPROPRIATE TIMING VALUES
    TA0CCR0 = 65535;   //delta t = T * N - set PWM period
    TA0CCR1 = 2054;

    TA0CCTL0 |= CM_1; //Rising edge
    TA0CCTL0 |= CCIS_1;   //compare to the value stored in CCR1
    TA0CCTL0 |= OUTMOD_6;
//    TA0CCTL0 |= CCIE;   //local interrupt enable for CCR0
//    TA0CCTL1 |= CCIE;

    //clear any interrupts
    TA0CCTL0 &= ~CCIFG;
    TA0CCTL1 &= ~CCIFG;
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
    //TODO: FINISH FUNCTION NOW PWM WORKS -- THIS DOES NOT WORK AS EXPECTED
    switch (signal) {
        case 'w':
            P1OUT ^= BIT7;  //Toggle PIN
            P1OUT ^= BIT5;

            //P8OUT ^= BIT0;  //LED PINS
            //P5OUT ^= BIT2;
            break;
        case 'a':
            //Toggle RIGHT motor, LEFT motor stationary -- maybe backwards?
            P1OUT &= ~BIT7;
            //P1OUT ^= BIT6;
            P1OUT ^= BIT5;
            break;

        case 'd':
            //Toggle LEFT motor, RIGHT motor statinary -- maybe backwards?
            P1OUT ^= BIT7;
            P1OUT &= ~BIT5;
            //P5OUT ^= BIT0;
            break;

        case 's':
            //Toggle backwards pins
            P1OUT ^= BIT6;
            P5OUT ^= BIT0;

            P5OUT ^= BIT1;
            P5OUT ^= BIT3;
            break;

        default:
            //Stay still -- all pins written to LOW
            P1OUT &= ~BIT7;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT5;
            P5OUT &= ~BIT0;
            break;
    }
}


