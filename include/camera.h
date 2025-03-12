#ifndef CAMERA_H
#define CAMERA_H
#include <esp_camera.h>

#define EXT_LED_PIN 4  // change the number to 4 later
#define EXT_LED_FLASH_DURATION 2000  

// Variable declarations
extern unsigned long ledTurnOffTime;
extern bool ledActive;

// Function declarations
bool initCamera();
camera_fb_t* captureImage();
void updateLED();
void adjustCameraSettings(int exposure_value, int gain_value);
void requestCapture();
camera_fb_t* getLatestFrame();

#endif // CAMERA_H