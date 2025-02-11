#include <Arduino.h>
#include "camera.h"
#include <esp_camera.h>

// Camera configuration
camera_config_t config = {
    .pin_pwdn = -1,        // Not used on M5Stack Timer CAM
    .pin_reset = 15,       // RESET pin
    .pin_xclk = 27,        // XCLK pin
    .pin_sccb_sda = 25,    // SDA pin
    .pin_sccb_scl = 23,    // SCL pin
    .pin_d7 = 19,          // Y9 pin
    .pin_d6 = 36,          // Y8 pin
    .pin_d5 = 18,          // Y7 pin
    .pin_d4 = 39,          // Y6 pin
    .pin_d3 = 5,           // Y5 pin
    .pin_d2 = 34,          // Y4 pin
    .pin_d1 = 35,          // Y3 pin
    .pin_d0 = 32,          // Y2 pin
    .pin_vsync = 22,       // VSYNC pin
    .pin_href = 26,        // HREF pin
    .pin_pclk = 21,        // PCLK pin

    .xclk_freq_hz = 10000000, 
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,
    .pixel_format = PIXFORMAT_JPEG, 
    .frame_size = FRAMESIZE_XGA, 
    .jpeg_quality = 10,           
    .fb_count = 2,               
    .grab_mode = CAMERA_GRAB_LATEST               
};

bool initCamera() {
    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x\n", err);
        return false;
    }
    return true;
}