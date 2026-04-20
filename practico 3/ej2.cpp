#include <Arduino.h>

#define PIN_POT 32
#define PIN_LED 2

void setup() {
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    int valor = analogRead(PIN_POT);
    int pwm = map(valor, 0, 4095, 0, 255);
    analogWrite(PIN_LED, pwm);
    delay(10);
}