#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <driverlib.h>
// Function to initialise Bluetooth module
void bluetooth_init();

// Function to check for incoming data from Bluetooth
void initUART();
void initGPIO();

#endif /* BLUETOOTH_H_ */
