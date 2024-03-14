/*
* actuator.h
*
*/
#ifndef __ACTUATOR_H__
#define __ACTUATOR_H__

#include <msp430.h>
#include "driverlib.h"

void initialise_actuator();
void drop_tree();
void turn_forward();


#endif // __ACTUATOR_H__
