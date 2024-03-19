/*
 *  main.c
 *  EE318 Group 24
 *
 *  TODO:
 *  Implement interrupts
 *  Implement bluetooth
 *  Implement PWM of motors
 *  Implement actuation control
 *
 */


/*
*   MSP430 PINOUT
*   BLUETOOTH: PORT 1 PINS 0 TX,1 RX
*   MOTOR: PORT 1 PINS 5,6,7 AND PORT 5 PIN 0
*   SERVO: PORT X PINS Y
*/

#include <msp430.h>
#include <driverlib.h>  //unsure if it is needed whilst using CCS
#include "motor.h"
#include "bluetooth.h"

char signal;  //for testing purposes -- will be set by bluetooth in practice

//ISR for CCR0 and CCR1 capture compare registers
#pragma vector = TIMER0_A0_VECTOR
__interrupt void ISR_TA0_CCR0(void)
{
    //Reference pulse
    P4OUT &= ~BIT0;  //SET LED HIGH
    //P8OUT |= BIT0;

    drive(signal);

    TA0CCTL0 &= ~CCIFG; //clear interrupt flag
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void ISR_TA0_CCR1(void)
{
    P4OUT |= BIT0; //SET LED LOW
    //P8OUT &= ~BIT0;

    drive(signal);

    TA0CCTL1 &= ~CCIFG; //clear interrupt
}

void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   //stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    __enable_interrupt();
    //__bis_SR_register(LPM0_bits);

    //initialise motor DO and timers
    initMotors();
    initPWMTimers();

    bluetooth_init();

    //MAIN PROGRAM LOOP
    while(1)
    {
        signal = _lab_test_('w');
        //bluetooth_check();
    }
}


