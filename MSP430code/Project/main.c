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
#include "bluetooth.h"


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

void main(void)
{
	//Default MCLK = 1MHz and SMCLK = MCLK
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//PM5CTL0 &= ~LOCKLPM5;
	PMM_unlockLPM5();

	//initialise timers
	initTimers();

	__enable_interrupt();
	__bis_SR_register(LPM0_bits);

	GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
	//MAIN PROGRAM LOOP
	while(1)
	{
	    _lab_test_();
	}
}


