#include "actuator.h"

void initActuator()
{
    //SETUP TIMERA1
    P4DIR |= BIT0;

    TA1CTL |= TACLR;
    TA1CTL |= TASSEL__ACLK;
    TA1CTL |= MC__UP;

    //Cap compare registers
    TA1CCR0 = 3000;
    TA1CCR1 = 150;

    TA1CCTL0 |= CM_1;    //Rising edge
    TA1CCTL0 |= CCIS_1;  //Compare to CCR1
    TA1CCTL0 |= OUTMOD_7;

    TA1CCTL0 |= CCIE;   //local interrupts
    TA1CCTL1 |= CCIE;

    TA1CCTL0 &= ~CCIFG; //clear any existing interrupts
    TA1CCTL1 &= ~CCIFG;

}
