/*
* actuator.c
*
*
*   -- Might be easier if I give you PIN1.7 due to its built-in PWM functionality (Digital IO section in the userguide p314/319)
*      P1SEL1
*
*      Should be able to control PWM with TIMERA1 and only the pin itself, no need for CAPTURE/COMPARE registers
*/

#include "actuator.h"

void initialise_actuator(){


    // Setting the output pin
    P1DIR |= 0x40;

}

void turn_forward(){
    //setting up clock
    TA1CCTL0 |= TASSEL__ACLK;
    TA1CCTL0 |= ID__8;
    TA1CCTL0 |= TACLR;

}

