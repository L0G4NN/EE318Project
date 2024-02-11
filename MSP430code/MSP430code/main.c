/*
 * main.c
 * EE318 Group 24
 *
 */

#include <msp430.h> 
//#include <driverlib.h> //dont think its needed whilst using CCS
#include "motor.h"
/**
 * main.c
 */


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


}


