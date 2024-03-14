/*
 * main.c
 * EE318 Group 24
 *
 * TODO:
 * Implement interrupts
 * Implement bluetooth
 * Implement PWM of motors
 * Implement actuation control
 *
 */


/*
* MSP430 PIN CONNECTIONS
* BLUETOOTH: PORT 1 PINS 0 TX,1 RX
* MOTOR: PORT X PINS Y
* SERVO: PORT X PINS Y
*/

#include <msp430.h>
#include <driverlib.h> //unsure if it is needed whilst using CCS
#include "motor.h"


//Interrupts
unsigned char SW1_interruptFlag = 0;

#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void) //interrupts on PORT1
{
	switch (__even_in_range(P1IV, P1IV_P1IFG7))
	{
	case P1IV_P1IFG2:
		SW1_interruptFlag = 1;
		//GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN2); //compiler does not like this
		break;
	}
}

//ISR for CCR0 and CCR1 capture compare registeres - to set PWM
#pragma vector = TIMER0_0_VECTOR
__interrupt void ISR_TA0_CCR0(void)
{
    P4OUT |= BIT0; //SET LED HIGH
    TA1CCTL0 &= ~CCIFG; //clear interrupt flag

}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void ISR_TA0_CCR1(void)
{
    P4OUT &= ~BIT0; //SET LED LOW
    TA1CCTL1 %= ~CCIFG; //clear interrupt

}

//interrupt handler for the timer
//see user guide 11.2.6 and msp430fr4133 line 3016

void main(void)
{
	//Default MCLK = 1MHz and SMCLK = MCLK
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//PM5CTL0 &= ~LOCKLPM5;
	PMM_unlockLPM5();
    __enable_interrupt();

	//initialise timers
	initPWMTimers();

	//MAIN PROGRAM LOOP
	while(1)
	{
	    _lab_test_();
	    //delay_us(1);
	}
}


