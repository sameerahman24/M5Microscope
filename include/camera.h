#ifndef CAMERA_H
#define CAMERA_H
#include <esp_camera.h>

bool initCamera();
camera_fb_t* captureImage();

void adjustCameraSettings(int exposure_value, int gain_value);

#endif // CAMERA_H