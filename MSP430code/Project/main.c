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
//#include "Board.h" //unsure if we need this - dont think we do
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

//interrupt handler for the timer
//see user guide 11.2.6 and msp430fr4133 line 3016

void main(void)
{
	//Default MCLK = 1MHz and SMCLK = MCLK
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;
	PMM_unlockLPM5();

	//initialise motor pins
	initMotors();

	//initialise timers
	initTimers();

	__enable_interrupt();

	//SETUP LED INDICATION
	GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0);
	GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN0);



	//MAIN PROGRAM LOOP
	while(1)
	{
	    _lab_test_();
	    //delay_us(1);
	}
}


