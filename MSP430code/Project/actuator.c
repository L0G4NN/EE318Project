#include "actuator.h"

void delay()
{
    P4OUT ^= BIT0;

    volatile unsigned long i;
    i = 49999;
    do (i--);
    while (i != 0);
}

void initActuator(void)
{

    P4DIR |= BIT0;                          // Internal LEDs P1.0 of Launchpad is output

    P1DIR |= BIT7;                          // P1.6/TA0.1 is used for PWM, thus also an output -> servo 1

    P1OUT = 0;                              // Clear all outputs P1

    P1SEL0 |= BIT7;                          // P1.6 select TA0.1 option

    // if SMCLK is about 1MHz (or 1000000Hz),
    // and 1000ms are the equivalent of 1 Hz,
    // then, by setting CCR0 to 20000 (1000000 / 1000 * 20)
    // we get a period of 20ms
    TA1CCR0 = 20000-1;                           // PWM Period TA1.1

    // setting 1500 is 1.5ms is 0deg. servo pos
    TA1CCR1 = 1500;                            // CCR1 PWM duty cycle

    TA1CCTL1 = OUTMOD_7;                       // CCR1 reset/set
    TA1CTL   = TASSEL_2 + MC_1;                // SMCLK, up mode

    // loop just blinks build in LEDs to show activity
    for (;;)
    {
        delay();
        TA1CCR1 = 2000;

        delay();
        TA1CCR1 = 1500;

        delay();
        TA1CCR1 = 1000;

        delay();
        TA1CCR1 = 1500;
    }
}
