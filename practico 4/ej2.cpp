#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t IR_PIN = 21;
IRrecv irrecv(IR_PIN);
decode_results resultado;

void setup() {
    Serial.begin(115200);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&resultado)) {
        serialPrintUint64(resultado.value, HEX);
        Serial.println();
        irrecv.resume();
    }
}