#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "ota_update.h"

void initOTAUpdate() {
  // Initialize OTA
  ArduinoOTA.onStart([]() {
    Serial.println("OTA update started");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA update finished");
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("OTA update error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("OTA authentication failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("OTA begin failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("OTA connect failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("OTA receive failed");
    else if (error == OTA_END_ERROR) Serial.println("OTA end failed");
  });

  ArduinoOTA.begin();
}

void handleOTAUpdate() {
  ArduinoOTA.handle();
}
