#include <Arduino.h>

#define PIN0 15
#define PIN1 16
#define PIN2 17
#define PIN3 18
#define PIN4 19

int ultimoValor = -1;

void setup() {
    Serial.begin(38400);
    pinMode(PIN0, INPUT_PULLUP);
    pinMode(PIN1, INPUT_PULLUP);
    pinMode(PIN2, INPUT_PULLUP);
    pinMode(PIN3, INPUT_PULLUP);
    pinMode(PIN4, INPUT_PULLUP);
}

void loop() {
    int valor = 0;
    valor |= !digitalRead(PIN0) << 0;
    valor |= !digitalRead(PIN1) << 1;
    valor |= !digitalRead(PIN2) << 2;
    valor |= !digitalRead(PIN3) << 3;
    valor |= !digitalRead(PIN4) << 4;
    if (valor != ultimoValor) {
        Serial.println(valor);
        ultimoValor = valor;
    }
    delay(50);
}
