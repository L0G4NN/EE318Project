#include <msp430.h>
#include "bluetooth.h"

#define RXD BIT1
#define LED BIT0

void bluetooth_init() {
    // Initialize UART
    P1SEL0 |= RXD; // Set RXD pin to UART mode

    // Configure LED pin
    P1DIR |= LED; // Set LED pin as output
    P1OUT &= ~LED; // Turn off LED

    // Configure UART settings
    UCA0CTLW0 |= UCSWRST; // Put eUSCI in reset
    UCA0CTLW0 |= UCSSEL__SMCLK; // Select SMCLK as clock source
    UCA0BRW = 52; // Set baud rate to 9600 (assuming 1 MHz SMCLK)
    UCA0MCTLW |= UCOS16 | UCBRF_1 | 0x4900; // Modulation UCBRSx = 0x49, UCBRFx = 1
    UCA0CTLW0 &= ~UCSWRST; // Initialize eUSCI
    UCA0IE |= UCRXIE; // Enable USCI_A0 RX interrupt
}

void bluetooth_check() {
    if (UCA0IFG & UCRXIFG) { // Check if data is available
        char received_char = UCA0RXBUF; // Read received character

        // Check received character and control LED accordingly
        switch (received_char) {
            case '0':
                P1OUT |= LED; // Turn on LED
                break;
            case '1':
                P1OUT &= ~LED; // Turn off LED
                break;
            default:
                break;
        }
    }
}
