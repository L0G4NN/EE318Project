
#include <msp430.h>
#include "bluetooth.h"

void bluetooth_init() {

    P1SEL0 |= BIT1; // Set RXD pin to UART mode

    UCA0CTLW0 |= UCSWRST; // Put UART module in reset state
    UCA0CTLW0 |= UCSSEL__SMCLK; // Select SMCLK as clock source

    // Baud rate configuration for 9600
    UCA0BR0 = 104;  // Set the baud rate control registers for 9600 baud
    UCA0BR1 = 0;
    UCA0MCTLW = UCOS16 | UCBRF_1 | 0x4900; // Modulation and oversampling settings

    // Release UART module for operation
    UCA0CTLW0 &= ~UCSWRST;

    UCA0IE |= UCRXIE;   // Enable UART RX interrupt

    // Configure LED pin
    P1DIR |= BIT0; // Set LED pin (P4.0) as output
    P1OUT &= ~BIT0; // Turn off LED



}

/*
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void) {
    switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG)) {
        case USCI_NONE: break;
        case USCI_UART_UCRXIFG:
            // Assuming a character '1' turns the LED on and '0' turns it off
                              // Take Data from RX Buffer
           if(Recvd_Char[Buffer_Index] == '1'){// check the end of data stream from computer
               P4OUT |= BIT0;
        }
           else if (Recvd_Char[Buffer_Index] == '0') {
                    P4OUT &= ~BIT0; // Turn off LED
                }
            break;
        case USCI_UART_UCTXIFG: break;
        case USCI_UART_UCSTTIFG: break;
        case USCI_UART_UCTXCPTIFG: break;
    }
}

*/
volatile char received_char;
// ISR for UART RX
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void) {
    switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG)) {
        case USCI_NONE:
            break;

        case USCI_UART_UCRXIFG:
            received_char = UCA0RXBUF; // Read to clear the interrupt flag
                        // Process received_char here, e.g., store it in a buffer
            break;

        case USCI_UART_UCTXIFG:
            break;
        case USCI_UART_UCSTTIFG:
            break;
        case USCI_UART_UCTXCPTIFG:
            break;
    }
}

char recievedChar()
{
    char signal = received_char;
    return signal;
}

