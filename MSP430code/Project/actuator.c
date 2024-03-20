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


        
void set clock(){
    //setting up clock    
    TA1CCTL0 |= TACLR;
<<<<<<< Updated upstream

=======
    TA1CTL0 |= TASSEL__ACLK;
    TA1CTL0 |= ID__8; //4.096KhZ
    TA1CTL |= MC_1;
    
    P1SEL |= 0x40;
    P1OUT |= 0x01;
    
    TA1CCR0 |= 0x06;
    
>>>>>>> Stashed changes
}

int degrees = 0;

void drop_tree_1(){
    
    TA1CCRO |= 0x07;
    
}

void drop_tree_2(){
    
    TA1CCRO |= 0x08;
    
}

void drop_tree_3(){
    
    TA1CCRO |= 0x0A;
    
}

void reset(){
    
    TA1CCRO |= 0X06;
}








