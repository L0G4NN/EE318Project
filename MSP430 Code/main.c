/*
 * main.c
 * EE318 Group 24
 * University of Strathclyde
 *
 */

#include "driverlib.h"
#include "utils.h"
#include "motor.h"

void main (void)
{
    //disable high impedance ports
    WDTCTL = WDPTW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;
    PMM_unlockLPM5();


    //initialisations
    _initADC();
}
