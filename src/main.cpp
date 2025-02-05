#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>
#include "camera.h"
#include "web_server.h"

void setup() {
    Serial.begin(115200);
    Serial.println("Starting setup...");

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
    // Your code here, if needed
}