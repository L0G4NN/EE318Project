/*
*   actuator.c
*
*   //TODO: FIX PUSH TREE
*
*/


#include "actuator.h"

//TODO: FIND THESE FINAL VALUES
#define DEFAULT 327;
#define POS_1 1000;
#define POS_2 2000;
#define POS_3 3000;
#define MAX_ROTATIONS 100;

void initActuator()
{
      //Setup TIMERA1 identical to TIMERA0 for the Servo
      // Configure GPIO
      P1DIR |= BIT7; // Set servo pin as output

      // Configure Timer
      TA1CTL |= TACLR;
      TA1CTL |= TASSEL__ACLK;
      TA1CTL |= ID__8;
      TA1CTL |= MC__UP;

      //Capture compare registers
      TA1CCR0 = 32768; // PWM Period = 1s
      TA1CCR1 = TA1CCR0 - DEFAULT;  //Initial value - set servo to default pos; TODO: 1MS PULSE = 0DEG
      TA1CCTL0 = CM_1;
      TA1CCTL0 = CCIS_1;
      TA1CCTL0 = OUTMOD_7; // CCR1 reset/set

      TA1CCTL0 |= CCIE;
      TA1CCTL1 |= CCIE;

      TA1CCTL0 &= ~CCIFG;   //Enable local interrupts
      TA1CCTL1 &= ~CCIFG;

      //TODO: set to min position
}

unsigned int rotations = 0;
int rotate_count()
{
    //Keep track of the number of rotations the servo has made
    rotations++;
    return rotations;
}

/*
void push_tree(char signal, int rotation)
{
    switch (signal) {
        case 'p':
            int rotations = rotation;
            while((rotations = rotate_count()) <= MAX_ROTATIONS)
            {
                if(rotations <= POS_1)
                {
                    TA1CCR1 = TA1CCR0 - POS_1;
                }
                else if(rotations <= POS_2)
                {
                    TA1CCR1 = TA1CCR0 - POS_2;
                }
                else if(rotations <= POS_3)
                {
                    TA1CCR1 = TA1CCR0 - POS_3;
                }
            }
            //Reset pos
            TA1CCR1 = TA1CCR0 - DEFAULT;
        }
            break;

        default:
            break;
    }
}
*/



