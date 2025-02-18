#include "power.h"
#include <esp_sleep.h>

// Global timestamp in ms for the last /capture access.
volatile unsigned long lastCaptureTime = 0;

// Define inactivity timeout (in ms) as a constant.
const unsigned long inactivityTimeout = 300000; 

void updateCaptureTime() {
    // Call this whenever the /capture endpoint is hit.
    lastCaptureTime = millis();
    Serial.print("DEBUG: Capture endpoint accessed. Time updated to: ");
    Serial.println(lastCaptureTime);
}

void checkInactivity() {
    unsigned long currentTime = millis();
    // Check if the inactivity period has been exceeded.
    if (currentTime - lastCaptureTime >= inactivityTimeout) {
         Serial.println("DEBUG: Inactivity timeout reached. Going to sleep...");
         delay(100); // Allow serial messages to flush.
         esp_deep_sleep_start();
    } else {
         unsigned long remaining = (inactivityTimeout - (currentTime - lastCaptureTime)) / 1000;
         delay(1000);
         Serial.print("DEBUG: Inactivity check: ");
         Serial.print(remaining);
         Serial.println(" seconds remaining until sleep.");
    }
}