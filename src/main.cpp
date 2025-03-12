#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>
#include "camera.h"
#include "web_server.h"
#include "M5TimerCAM.h"
#include "power.h"  


void setup() {
    Serial.begin(115200);
    Serial.println("Starting setup...");

    TimerCAM.begin(true);

    // Initialize LED indicator.
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);

    

    Serial.println("Mounting SPIFFS...");
    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
        return;
    }
    Serial.println("SPIFFS mounted successfully");

    Serial.println("Initializing camera...");
    if (!initCamera()) {
        Serial.println("Camera init failed");
        return;
    }
    Serial.println("Camera initialized successfully");

    Serial.println("Starting web server...");
    initWebServer();
    Serial.println("Web server started successfully");

    Serial.println("Setup completed");
}

void loop() {
    updateLED();
    checkInactivity(); 
    delay(100);      
}