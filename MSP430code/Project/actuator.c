#include "actuator.h"

/*
 * SERVO MOTOR CODE
 * LOGAN NOONAN
 * https://deepbluembedded.com/servo-motor-control-with-pic-microcontroller-software-pwm-pt2/
 *
 * TODO: MAY NEED TO LATCH THE SIGNAL WE RECIEVE. CAN FIGURE OUT ONCE LAB TESTED.
 * TODO: REFINE DEFINED NUMBERS, MAY NEED SMALL ADJUSTMENTS
 */

#define POS_LEFT 200  //0.5ms
#define POS_MID 1500    //1.5ms
#define POS_RIGHT 2000  //2.0ms

void initActuator()
{
    //SETUP TIMERA1
    P1DIR |= BIT7;
    P4DIR |= BIT0;  //ref LED

    TA1CTL |= TACLR;
    TA1CTL |= TASSEL__SMCLK;
    //TA1CTL |= ID__8;    //32768 / 8 = 4096
    TA1CTL |= MC__UP;

    //Cap compare registers
    TA1CCR0 = 20000;     // 1/50Hz = 20ms, therefore 20,000
    TA1CCR1 = POS_MID;

    TA1CCTL0 |= CM_1;    //Rising edge
    TA1CCTL0 |= CCIS_1;  //Compare to CCR1
    TA1CCTL0 |= OUTMOD_7;

    TA1CCTL0 |= CCIE;   //local interrupts
    TA1CCTL1 |= CCIE;

    TA1CCTL0 &= ~CCIFG; //clear any existing interrupts
    TA1CCTL1 &= ~CCIFG;

}


/*
void delay_us(unsigned int delay)
{
    while(delay--) {
        __delay_cycles(1);
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
                    TA1CCR1 = POS_RIGHT;
                    break;
                case 2:
                    TA1CCR1 = POS_MID;
                    break;
                case 3:
                    TA1CCR1 = POS_LEFT;
                    break;
                default:
                    TA1CCR1 = POS_RIGHT;
                    break;
            }
        }
        else {
            TA1CCR1 = POS_LEFT;
        }
    }
}


