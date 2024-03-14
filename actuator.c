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
    TA1CCTL |= TASSEL_2;
    TA1CCTL |= ID_4;
    TA1CCTL |= TACLR;
    
}

