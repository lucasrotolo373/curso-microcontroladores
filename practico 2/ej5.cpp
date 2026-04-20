#include <Arduino.h>

String comando = "";

int calcular(String expr) {
    int resultado = 0;
    int numero = 0;
    char operacion = '+';
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            numero = numero * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            resultado = (operacion == '+') ? resultado + numero : resultado - numero;
            numero = 0;
            operacion = c;
        }
    }
    resultado = (operacion == '+') ? resultado + numero : resultado - numero;
    return resultado;
}

void setup() {
    Serial.begin(38400);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c == ';') {
            if (comando.startsWith("=")) {
                int resultado = calcular(comando.substring(1));
                Serial.println(resultado);
            }
            comando = "";
        } else {
            comando += c;
        }
    }
}