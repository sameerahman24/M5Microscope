#ifndef CAMERA_H
#define CAMERA_H
#include <esp_camera.h>

bool initCamera();

camera_fb_t* captureImage();

#endif // CAMERA_H