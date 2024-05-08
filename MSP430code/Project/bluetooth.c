/******
 *  bluetooth.c
 * 
 *  Cailean O'Reilly
 *  UPDATED 22/04/2024
 *  - added test LED in interrupt
 *  - removed uneccessary function
 * 
******/


#include <msp430.h>
#include "bluetooth.h"

void initUART(void) {

    //P1.0 = TXD, P1.1 = RXD
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

