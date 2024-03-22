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

void initialise_actuator()
{


    // Setting the output pin
    //P1DIR |= 0x40;

      //WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer    --NOT NEEDED CALLED IN MAIN

      // Configure GPIO
      P1DIR |= BIT7; // Set servo pin as output
      P1SEL0 |= BIT7; // Select PWM output for the servo pin


      // Configure Timer
      TA1CTL |= TACLR;
      TA1CTL |= TASSEL__ACLK;
      //TA1CTL |= ID__8;
      TA1CTL |= MC__UP;

      //Capture compare registers
      TA1CCR0 = 32768; // PWM Period
      TA1CCR1 = 1;  //Initial value - set servo to default pos; TODO: CHANGE

      TA1CCTL0 = CM_1;
      TA1CCTL0 = CCIS_1;
      TA1CCTL0 = OUTMOD_7; // CCR1 reset/set

      TA1CCTL0 &= ~CCIFG;
      TA1CCTL1 &= ~CCIFG;
}


void setServoPosition(unsigned int position)
{
    int plant_count = 0;
    const int pushback = 10;    //TODO: FIND FINAL VALUE
    volatile char recieved_signal = recievedChar();

    if(plant_count <= 3)
    {
        //Can keep planting
        switch(recieved_signal){
            case 'p':
                TA1CCR1 = TA1CCR1 - pushback;
                break;

            default:
                //Dont move position
                TA1CCR1 = TA1CCR1;
                break;
        }
    }
    else
    {
        //do nothing
    }
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





