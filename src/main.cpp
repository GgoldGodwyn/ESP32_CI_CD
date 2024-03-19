#include <Arduino.h>
#include "ota_update.h"

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize OTA update
  initOTAUpdate();
}

void loop() {
  // Your application code here
}
