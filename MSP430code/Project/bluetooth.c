#include <msp430.h>
#include "bluetooth.h"

void bluetooth_init() {
    P1SEL0 |= BIT1; // Set RXD pin to UART mode

    UCA0CTLW0 |= UCSWRST; // Put UART module in reset state
    UCA0CTLW0 |= UCSSEL__SMCLK; // Select SMCLK as clock source (assuming SMCLK is running at desired frequency)
    UCA0BR0 = 6; // Set baud rate to 9600 with SMCLK at 1 MHz (see Table 36-5 in MSP430FR4xx Family User's Guide)
    UCA0BR1 = 0;
    UCA0MCTLW |= UCOS16 | UCBRF_8 | 0x20; // Set modulation control to achieve desired baud rate

    // Release UART module for operation
    UCA0CTLW0 &= ~UCSWRST;

    UCA0IE |= UCRXIE;   // Enable UART RX interrupt

    // Configure LED pin
    P4DIR |= BIT1; // Set LED pin (P4.1) as output
    P4OUT &= ~BIT1; // Turn off LED
}

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_RX_ISR(void) {
    if (UCA0IFG & UCRXIFG) { // Check RX interrupt flag
        if (UCA0RXBUF == '1') {
            P4OUT |= BIT1; // Turn on LED
        }
        else if (UCA0RXBUF == '0') {
            P4OUT &= ~BIT1; // Turn off LED
        }

        UCA0IFG &= ~UCRXIFG; // Clear RX interrupt flag
    }
}


