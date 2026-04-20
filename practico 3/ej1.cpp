#include <Arduino.h>

#define PIN_POT 32

void setup() {
    Serial.begin(115200);
}

void loop() {
    int valor = analogRead(PIN_POT);
    Serial.println(valor);
    delay(500);
}