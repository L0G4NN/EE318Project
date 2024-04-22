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


volatile char signal;   //received from bluetooth ISR
//MOTORS ISR
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

//SERVO ISR
#pragma vector = TIMER1_A0_VECTOR
__interrupt void ISR_TA1_CCR0(void)
{
    P1OUT |= BIT7;

    P4OUT |= BIT0;

    TA1CCTL0 &= ~CCIFG;

    //Keep track of the number of rotations on the HIGH pulse.
}


#pragma vector = TIMER1_A1_VECTOR
__interrupt void ISR_TA1_CCR1(void)
{
    P1OUT &= ~BIT7;

    P4OUT &= ~BIT0;

    TA1CCTL1 &= ~CCIFG;
}


//BLUETOOTH ISR
volatile char receivedChar;

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void) {
    switch (__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG)) {
        case USCI_NONE:
            break;
        case USCI_UART_UCRXIFG:

            receivedChar = UCA0RXBUF; // Read the received character
            switch(receivedChar) {
            case '1':
                signal = 'w';
                break;
            case '2':
                signal = 'x';
                break;
            case '3':
                signal = 'a';
                break;
            case '4':
                signal = 'd';
                break;
            case '5':
                signal = 's';
                break;
            case '6':
                signal = 'p';
                break;
            default:
                signal = 'x';
            }
            break;
        default: break;
    }
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
    initActuator();

    initGPIO();
    initUART();

    //MAIN PROGRAM LOOP
    while(1)
    {
        //signal = _lab_test_('w');
    }
}


