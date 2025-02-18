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

    .xclk_freq_hz = 8000000, 
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,
    .pixel_format = PIXFORMAT_JPEG, 
    .frame_size = FRAMESIZE_SVGA, 
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

camera_fb_t* captureImage() {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("DEBUG: Camera capture failed.");
    }
    return fb;
}
void adjustCameraSettings(int exposure_value) {
    sensor_t *s = esp_camera_sensor_get();
    if (s) {
        s->set_brightness(s, 0);     // Range: -2 to 2
        s->set_contrast(s, 0);       // Range: -2 to 2
        s->set_saturation(s, 0);     // Range: -2 to 2
        s->set_special_effect(s, 0); // Range: 0-6 (0 = No Effect, 1 = Negative, etc.)
        s->set_whitebal(s, 0);       // 0 = disabled, 1 = enabled
        s->set_awb_gain(s, 1);       // 0 = disabled, 1 = enabled
        s->set_wb_mode(s, 0);        // Range: 0-4 (if AWB gain enabled: 0 = Auto, 1 = Sunny, etc.)
        s->set_exposure_ctrl(s, 0);  // 0 = disable, 1 = enable
        s->set_aec2(s, 0);           // 0 = disable, 1 = enable
        s->set_ae_level(s, 0);       // Range: -2 to 2
        s->set_aec_value(s, exposure_value);  // Range: 0 to 1200
        s->set_gain_ctrl(s, 1);      // 0 = disable, 1 = enable
        s->set_agc_gain(s, 0);       // Range: 0 to 30
        s->set_gainceiling(s, (gainceiling_t)0);  // Range: 0 to 6
        s->set_bpc(s, 0);            // 0 = disable, 1 = enable
        s->set_wpc(s, 1);            // 0 = disable, 1 = enable
        s->set_raw_gma(s, 1);        // 0 = disable, 1 = enable
        s->set_lenc(s, 1);           // 0 = disable, 1 = enable
        s->set_hmirror(s, 0);        // 0 = disable, 1 = enable
        s->set_vflip(s, 0);          // 0 = disable, 1 = enable
        s->set_dcw(s, 1);            // 0 = disable, 1 = enable
        s->set_colorbar(s, 0);       // 0 = disable, 1 = enable
    } else {
        Serial.println("DEBUG: Unable to get sensor pointer for adjusting settings.");
    }
}