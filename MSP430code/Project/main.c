/*
 *   main.c
 *   EE318 Group 24
 *
 *   MSP430 PINOUT
 *   BLUETOOTH: PORT 1 PINS 0 TX, 1 RX
 *   MOTOR: A: 2.5, 1.6 B: 1.5, 5.0
 *   SERVO: PORT 1 PIN 7
 */

#include <msp430.h>
#include <driverlib.h>
#include "motor.h"
#include "bluetooth.h"
#include "actuator.h"

char signal;  //for testing purposes -- will be set by bluetooth in practice

//ISR for CCR0 and CCR1 capture compare registers
#pragma vector = TIMER0_A0_VECTOR
__interrupt void ISR_TA0_CCR0(void)
{
    //Reference pulse
    //P4OUT &= ~BIT0;  //SET LED HIGH
    //P8OUT |= BIT0;

    drive(signal);

    TA0CCTL0 &= ~CCIFG; //clear interrupt flag
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void ISR_TA0_CCR1(void)
{
    //P4OUT |= BIT0; //SET LED LOW
    //P8OUT &= ~BIT0;

    drive(signal);

    TA0CCTL1 &= ~CCIFG; //clear interrupt
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void ISR_TA1_CCR0(void)
{
    P4OUT |= BIT0;

    P1OUT |= BIT7;
    TA1CCTL0 &= ~CCIFG;

    //Keep track of the number of rotations on the HIGH pulse.
    int rotations = rotate_count();
}

#pragma vector = TIMER1_A1_VECTOR
__interrupt void ISR_TA1_CCR1(void)
{
    P4OUT &= ~BIT0;

    P1OUT &= ~BIT7;
    TA1CCTL1 &= ~CCIFG;
}

void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   //stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    __enable_interrupt();
    //__bis_SR_register(LPM0_bits);

    signal = recievedChar();
    //initialise motor DO and timers
    initMotors();
    initPWMTimers();
    initActuator();
    bluetooth_init();

    //MAIN PROGRAM LOOP
    while(1)
    {
        signal = _lab_test_('w');

        //drive(recievedChar    //called in TA0 ISR
        //push_tree(recievedChar, rotations);   //UNSURE IF CALLED IN TA1 ISR YET
    }
}


