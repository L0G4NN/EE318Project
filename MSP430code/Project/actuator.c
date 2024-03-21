/*
* actuator.c
*
*
*   -- Might be easier if I give you PIN1.7 due to its built-in PWM functionality (Digital IO section in the userguide p314/319)
*      P1SEL1
*
*      Should be able to control PWM with TIMERA1 and only the pin itself, no need for CAPTURE/COMPARE registers
*/

#include "actuator.h"

void initialise_actuator(){


    // Setting the output pin
    //P1DIR |= 0x40;

      //WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer    --NOT NEEDED CALLED IN MAIN

      // Configure GPIO
      P1DIR |= BIT7; // Set servo pin as output
      P1SEL0 |= BIT7; // Select PWM output for the servo pin


      // Configure Timer

      //CANT WRITE TO TIMER 0. MOTORS.C ALREADY WRITING TO THESE - NEED TO MOVE TO TA1

      TA0CCR0 = 20000-1; // PWM Period (SMCLK/50Hz) - Assuming SMCLK = 1MHz
      TA0CCTL1 = OUTMOD_7; // CCR1 reset/set
      TA0CCR1 = 1500; // CCR1 PWM duty cycle, 1.5 ms initially
      TA0CTL = TASSEL__SMCLK | MC__UP | TACLR; // SMCLK, up mode, clear TAR


      /*
       *
      // DUPLICATED PREVIOUS SECTION -- NOT NEEDED
      // Configure Timer
      TA0CCR0 = 20000-1; // PWM Period (SMCLK/50Hz) - Assuming SMCLK = 1MHz
      TA0CCTL1 = OUTMOD_7; // CCR1 reset/set
      TA0CCR1 = 1500; // CCR1 PWM duty cycle, 1.5 ms initially
      TA0CTL = TASSEL__SMCLK | MC__UP | TACLR; // SMCLK, up mode, clear TAR
      */

      }


void setServoPosition(unsigned int position) {
    if (position > 180) position = 180; // Limit position to 0-180 degrees
    unsigned int pulseWidth = (position * 10) + 1000; // Convert position to pulse width
    TA0CCR1 = pulseWidth; // Update CCR1 with the new pulse width
}


/*
        

        //messy code section
void set_clock(){
    //setting up clock    
    TA1CCTL0 |= TACLR;

    TA1CTL0 |= TASSEL__ACLK;
    TA1CTL0 |= ID__8; //4.096KhZ
    TA1CTL |= MC_1;
    
    P1SEL |= 0x40;
    P1OUT |= 0x01;
    
    TA1CCR0 |= 0x06;
    
}
*/
/*
int degrees = 0;

void drop_tree_1(){
    
    TA1CCR0 |= 0x07;
    
}

void drop_tree_2(){
    
    TA1CCR0 |= 0x08;
    
}

void drop_tree_3(){
    
    TA1CCR0 |= 0x0A;
    
}

void reset(){
    
    TA1CCR0 |= 0X06;
}


*/





