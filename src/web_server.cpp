#include "web_server.h"
#include <WiFi.h>
#include <SPIFFS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "secrets.h"
#include "M5TimerCAM.h"
#include "power.h"
#include "camera.h"

#define LED_BUILTIN 2

AsyncWebServer server(80);

void handleCapture(AsyncWebServerRequest *request) {
   
    updateCaptureTime();

    // Capture image using camera.cpp function
    camera_fb_t *fb = captureImage();
    if (!fb) {
        request->send(500, "text/plain", "Camera capture failed");
        return;
    }
    request->send(200, "image/jpeg", fb->buf, fb->len);
    esp_camera_fb_return(fb);
}

void handleIP(AsyncWebServerRequest *request) {
    String ip = WiFi.softAPIP().toString();
    request->send(200, "text/plain", ip);
}

void handleBattery(AsyncWebServerRequest *request) {
    int batteryLevel = TimerCAM.Power.getBatteryLevel(); 
    request->send(200, "text/plain", String(batteryLevel));
}

void initWebServer() {
    pinMode(LED_BUILTIN, OUTPUT);
    // Initialize SPIFFS
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS error");
        return;
    }

    // Set WiFi mode to access point (AP)
    WiFi.mode(WIFI_AP);
    WiFi.softAP(apSSID, apPassword);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("Access Point IP: ");
    Serial.println(IP);

    // Set up routes
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        if (SPIFFS.exists("/index.html")) {
            request->send(SPIFFS, "/index.html", "text/html");
        } else {
            request->send(404, "text/plain", "File not found");
        }
    });

    server.on("/capture", HTTP_GET, handleCapture);
    server.on("/ip", HTTP_GET, handleIP);
    server.on("/battery", HTTP_GET, handleBattery);

    server.begin();
    Serial.println("Web server started in AP mode");
}