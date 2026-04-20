#include <Arduino.h>

void setup() {
    Serial.begin(38400);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        Serial.println(c);
    }
}