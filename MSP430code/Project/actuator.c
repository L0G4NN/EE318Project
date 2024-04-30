#include "actuator.h"

/*
 * SERVO MOTOR CODE
 * LOGAN NOONAN
 * POS Values calculated to be 1ms, 1.5ms, and 2ms.
 * Period of ACLK is 1/4096 = 0.2ms therefore the value is multiplied to meet the
 * required values.
 */

#define POS_LEFT 4.096  //1.0ms
#define POS_MID 6.14    //1.5ms
#define POS_RIGHT 8.19  //2.0ms

void initActuator()
{
    //SETUP TIMERA1
    P1DIR |= BIT7;
    P4DIR |= BIT0;  //ref LED

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


void delay_us(unsigned int delay)
{
    while(delay--) {
        __delay_cycles(1);
    }
}

/*
void manual_pulsing(char signal)
{
    volatile unsigned int i = 0;  //keep track of no. of plants

    for (i = 0; i <= 3;) {
            if (signal == 'p') {
                switch (i) {
                    case 1:
                        //Create 50Hz pulse with 0.5ms high pulse
                        P1OUT |= BIT7;
                        delay_us(500);
                        P1OUT &= ~BIT7;
                        delay_us(19500);
                        break;

                    case 2:
                        P1OUT |= BIT7;
                        delay_us(1500);
                        P1OUT &= ~BIT7;
                        delay_us(18500);
                        break;

                    case 3:
                        P1OUT |= BIT7;
                        delay_us(2000);
                        P1OUT &= ~BIT7;
                        delay_us(18000);
                        break;

                    default:
                        P1OUT &= ~BIT7;
                        break;
                }
                i++;
            }
    }
}
*/


void set_pos(int i, char signal)
{

    if (i <= 3) {
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
        }
    }
}


