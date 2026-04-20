#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t IR_PIN = 4;
IRsend irsend(IR_PIN);

// codigo capturado del control del televisor en ej3
#define CODIGO_POWER 0x20DF10EF

void setup() {
    Serial.begin(115200);
    irsend.begin();
}

void loop() {
    irsend.sendNEC(CODIGO_POWER, 32);
    delay(3000);
}