#include <Arduino.h>

#define LED 2
String comando = "";

void setup() {
    Serial.begin(38400);
    pinMode(LED, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        comando += c;
        if (c == ':') {
            if (comando == "ON:") {
                digitalWrite(LED, HIGH);
                Serial.println("Led 13 Encendido!");
            } else if (comando == "OFF:") {
                digitalWrite(LED, LOW);
                Serial.println("Led 13 apagado!");
            }
            comando = "";
        }
    }
}