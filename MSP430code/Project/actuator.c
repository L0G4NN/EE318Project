#include "actuator.h"

/*
 * SERVO MOTOR CODE
 * LOGAN NOONAN
 * POS Values calculated to be 1ms, 1.5ms, and 2ms.
 * Period of ACLK is 1/4096 = 0.2ms therefore the value is multiplied to meet the
 * required values.
 */

#define POS_LEFT 4.096
#define POS_MID 6.14
#define POS_RIGHT 8.19

void initActuator()
{
    //SETUP TIMERA1
    P4DIR |= BIT0;

    TA1CTL |= TACLR;
    TA1CTL |= TASSEL__ACLK;
    TA1CTL |= ID__8;    //32768 / 8 = 4096
    TA1CTL |= MC__UP;

    //Cap compare registers
    TA1CCR0 = 4096;     // 1/4096 = 0.24ms
    TA1CCR1 = POS_MID;

    TA1CCTL0 |= CM_1;    //Rising edge
    TA1CCTL0 |= CCIS_1;  //Compare to CCR1
    TA1CCTL0 |= OUTMOD_7;

    TA1CCTL0 |= CCIE;   //local interrupts
    TA1CCTL1 |= CCIE;

    TA1CCTL0 &= ~CCIFG; //clear any existing interrupts
    TA1CCTL1 &= ~CCIFG;

}


void set_pos(char signal, int pos)
{
    volatile int i = 0;

    for (i = 0; i <= 3;) {
        if (signal == 'p') {
            //MOVE POS
            switch (i) {
                case 1:
                    TA1CCR1 = POS_LEFT;
                    break;
                case 2:
                    TA1CCR1 = POS_MID;
                    break;
                case 3:
                    TA1CCR1 = POS_RIGHT;
                    break;
                default:
                    TA1CCR1 = POS_LEFT;
                    break;
            }
            i++;    //keep track of how many trees have been pushed
        }
    }
}
