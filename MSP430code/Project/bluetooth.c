#include <msp430.h>
#include "bluetooth.h"


void bluetooth_init() {

    WDTCTL=WDTPW | WDTHOLD;

    UCA0CTLW0 |= UCSWRST; // Put UART module in reset state
    UCA0CTLW0 |= UCSSEL__SMCLK; // Select SMCLK as clock source (assuming SMCLK is running at desired frequency)
    UCA0BRW = 6; // Set baud rate to 9600 with SMCLK at 1 MHz (see Table 36-5 in MSP430FR4xx Family User's Guide)
    UCA0CTLW0 &= ~UCSWRST;


    // Initialise UART


    P1SEL0 |= BIT1; // Set RXD pin to UART mode


    // Configure LED pin
    P4DIR |= BIT0; // Set LED pin as output
    P4OUT &= ~BIT0; // Turn off LED

    PM5CTL0 &= ~LOCKLPM5;





}

void bluetooth_check() {
    if (UCA0IFG & UCRXIFG) { // Check if data is available
        char received_char = UCA0RXBUF; // Read received character

        // Check received character and control LED accordingly
        switch (received_char) {
            case '1':
                P4OUT |= BIT1; // Turn on LED
                break;
            case '0':
                P4OUT &= ~BIT1; // Turn off LED
                break;
            default:
                break;
        }
    }
}
