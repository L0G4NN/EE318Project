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

#include <msp430.h> 
//#include <driverlib.h> //unsure if it is needed whilst using CCS
#include "motor.h"

#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void) //interrupts on PORT1
{
	switch (__even_in_range(P1IV, P1IV_P1IFG7))
	{
	case P1IV_P1IFG2:
		SW1_interruptFlag = 1;
		GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN2);
		break;
}

//interrupt handler for the timer
//see user guide 11.2.6 and msp430fr4133 line 3016
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TimerA0_ISR(void) //timer ISR
{
	//TA0CCR0 CCIFG Flag is cleared automatically
	//- no need to clear it in the software
	TimerA0_CCR0_interrutp_hit = 1;
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMERA0_ISR1(void)
{
	switch(__even_in_range(TA01V,10)) //clears the flag
	{
		; //not used
	}
}

void main(void)
{	
	//Default MCLK = 1MHz and SMCLK = MCLK
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;
	PMM_unlockLPM5();
	//initialise motor pins
	initGPIO();

	//initialise timers
	initTimers();


	__enable_interrupt();

	while(true) //Main program loop
	{
		//Recieve bluetooth signal

		//whatever the signal is, call the appropriate function ie driveForward()

		//if plant button is pressed interrupt and call plantTree()

		//repeat
	}


}


