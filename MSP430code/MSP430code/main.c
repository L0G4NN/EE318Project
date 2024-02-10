#include <msp430.h> 
//#include <driverlib.h> //dont think its needed whilst using CCS
#include "motor.h"
#include "utils.h"
/**
 * main.c
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}

