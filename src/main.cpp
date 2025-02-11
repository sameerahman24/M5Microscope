#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>
#include "camera.h"
#include "web_server.h"
#include "M5TimerCAM.h"

const int LED_PIN = 2;  // LED indicator pin

void setup() {
    Serial.begin(115200);
    Serial.println("Starting setup...");

    TimerCAM.begin(true);

    // Initialize LED indicator
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);  // Turn on LED to indicate power

    Serial.println("Mounting SPIFFS...");
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
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
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    
}