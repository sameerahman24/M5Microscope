#ifndef POWER_H
#define POWER_H

#include <Arduino.h>


#define POWER_BUTTON_PIN 38


/**
 * @brief Updates the timestamp for the last /capture endpoint access.
 * This should be called from your web server code when /capture is accessed.
 */
void updateCaptureTime();

/**
 * @brief Checks if the inactivity time since last /capture access exceeds 5 minutes.
 * If so, the device will go to sleep.
 */
void checkInactivity();

#endif // POWER_H