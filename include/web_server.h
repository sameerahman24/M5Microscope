#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESPAsyncWebServer.h>

extern AsyncWebServer server;
extern const char* ssid;
extern const char* password;

void handleCapture(AsyncWebServerRequest *request);
void handleIP(AsyncWebServerRequest *request);
void handleBattery(AsyncWebServerRequest *request);
void initWebServer();

#endif // WEB_SERVER_H