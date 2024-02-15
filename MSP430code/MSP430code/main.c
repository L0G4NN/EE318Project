/*
 * main.c
 * EE318 Group 24
 *
 * TODO:
 * Implement interrupts for ADC - and bluetooth?
 *
 */

#include <msp430.h> 
//#include <driverlib.h> //unsure if it is needed whilst using CCS
#include "motor.h"


__interrupt void P1_ISR(void)
{
    //TODO: SETUP INTERRUPT SERVICE ROUTINE
	
}

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	//Watchdog timer
	PM5CTL0 &= ~LOCKLPM5;
	PMM_unlockLPM5();
	
	//initialise motor pins
	initGPIO();

	//initialise ADC/PWM
	initADC();


	__enable_interrupt();

	while(true)
	{
	    //main program loop

		//Recieve bluetooth signal

		//whatever the signal is, call the appropriate function ie driveForward()

		//if plant button is pressed interrupt and call plantTree()
	}


}


