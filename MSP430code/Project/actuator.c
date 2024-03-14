/*
* actuator.c
*
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

