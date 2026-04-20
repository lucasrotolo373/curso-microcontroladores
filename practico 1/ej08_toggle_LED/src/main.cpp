#include <Arduino.h>

#define ledPin 2
#define botonPin 21
int estadoActual = 0;
uint64_t last = 0;
bool estadoLed = false;
int estadoAnterior = 0;

void setup(){
	Serial.begin(115200);
	pinMode(botonPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
}

void loop(){
    estadoActual = digitalRead(botonPin);
    if (millis() - last > 70){
        if (estadoActual != estadoAnterior){
            if (estadoActual == LOW){
                estadoLed = !estadoLed;
                digitalWrite(ledPin, estadoLed);
            }
            estadoAnterior = estadoActual;
        }
        last = millis();
    }
}