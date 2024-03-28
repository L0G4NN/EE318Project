/*
* actuator.c
*
*
*
*/

#include "actuator.h"

void initActuator()
{

      // Configure GPIO
      P1DIR |= BIT7; // Set servo pin as output

      // Configure Timer
      TA1CTL |= TACLR;
      TA1CTL |= TASSEL__SMCLK;
      TA1CTL |= ID__8;
      TA1CTL |= MC__UP;

      //Capture compare registers
      TA1CCR0 = 32768; // PWM Period =0.5us
      TA1CCR1 = TA1CCR0 - 26000;  //Initial value - set servo to default pos; TODO: CHANGE
      TA1CCTL0 = CM_1;
      TA1CCTL0 = CCIS_1;
      TA1CCTL0 = OUTMOD_7; // CCR1 reset/set

      TA1CCTL0 |= CCIE;
      TA1CCTL1 |= CCIE;

      TA1CCTL0 &= ~CCIFG;
      TA1CCTL1 &= ~CCIFG;

      //TODO: set to min position
}


int rotate_count()
{
    //Keep track of the number of rotations the servo has made
    unsigned int rotations = 0;
    rotations++;
    return rotations;
}


void push_tree(char signal, int rotations)
{
    const int max_rotations = 20;   //TODO: calc final value
    rotations = rotate_count();
    while(rotations <= max_rotations)
    {
        //keep rotating from pos1 till pos2 till pos3.

    }
    if(rotations == max_rotations)
    {
        //reset position
    }
}





