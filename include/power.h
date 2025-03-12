#ifndef POWER_H
#define POWER_H

#include <Arduino.h>

#define POWER_BUTTON_PIN 38


#define DEVICE_LED 2

void updateCaptureTime();


void checkInactivity();

unsigned long getRemainingTime();

#endif // POWER_H