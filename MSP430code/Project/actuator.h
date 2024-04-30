/*
* actuator.h
*
*/
#ifndef __ACTUATOR_H__
#define __ACTUATOR_H__

#include <msp430.h>
#include "driverlib.h"

void initActuator();
void set_pos(int i, char signal);
void delay_us(unsigned int delay);


#endif // __ACTUATOR_H__
