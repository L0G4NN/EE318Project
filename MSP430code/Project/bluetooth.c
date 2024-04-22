
#include <msp430.h>
#include "bluetooth.h"

void initUART(void) {

    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO high-impedance mode

    // Assuming P1.2 = RXD, P1.3 = TXD for example. Adjust according to your board.

    P1SEL0 |= BIT0 | BIT1;


    UCA0CTLW0 |= UCSWRST; // Reset state

    UCA0CTLW0 |= UCSSEL__SMCLK; // SMCLK

    // Baud Rate configuration for 9600

    UCA0BR0 = 6;

    UCA0BR1 = 0;

    UCA0MCTLW = UCOS16 | UCBRF_8 | UCOS16 | 0x20;

    UCA0CTLW0 &= ~UCSWRST;

    UCA0IE |= UCRXIE;
}


void initGPIO(void) {

}
