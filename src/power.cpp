#include "power.h"
#include <esp_sleep.h>


volatile unsigned long lastCaptureTime = 0;


const unsigned long inactivityTimeout = 180000; 

void updateCaptureTime() {
 
    lastCaptureTime = millis();
    Serial.print("DEBUG: Capture endpoint accessed. Time updated to: ");
    Serial.println(lastCaptureTime);
}

void checkInactivity() {
    unsigned long remaining = getRemainingTime();
    if (remaining == 0) {
        Serial.println("DEBUG: Inactivity timeout reached. Going to sleep...");
        delay(100); 
        esp_deep_sleep_start();
    } else {
        Serial.print("DEBUG: Inactivity check: ");
        Serial.print(remaining);
        Serial.println(" seconds remaining until sleep.");
        delay(1000);
    }
}

unsigned long getRemainingTime() {
    unsigned long currentTime = millis();
    if (currentTime - lastCaptureTime >= inactivityTimeout) {
         return 0;
    } else {
         return (inactivityTimeout - (currentTime - lastCaptureTime)) / 1000;
    }
}