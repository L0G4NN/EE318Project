/*
* actuator.h
*
*/
#ifndef __ACTUATOR_H__
#define __ACTUATOR_H__

#include <msp430.h>
#include "driverlib.h"

void initActuator();
void push_tree(char signal, int rotations);
int rotate_count();

#endif // __ACTUATOR_H__
