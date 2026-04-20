#include <Arduino.h>

String comando = "";

void setup() {
    Serial.begin(38400);
    for (int i = 2; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
}

void procesarComando(String cmd) {
    bool encender = cmd.startsWith("ON:");
    bool apagar = cmd.startsWith("OFF:");
    if (!encender && !apagar) return;
    int inicio = cmd.indexOf(':') + 1;
    String pines = cmd.substring(inicio);
    int desde = 0;
    while (true) {
        int coma = pines.indexOf(',', desde);
        String pinStr = (coma == -1) ? pines.substring(desde) : pines.substring(desde, coma);
        pinStr.trim();
        if (pinStr.length() > 0) {
            int pin = pinStr.toInt();
            digitalWrite(pin, encender ? HIGH : LOW);
        }
        if (coma == -1) break;
        desde = coma + 1;
    }
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c == ';') {
            procesarComando(comando);
            comando = "";
        } else {
            comando += c;
        }
    }
}