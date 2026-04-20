#include <Arduino.h>

#define ledPin 2
#define botonPin 21
volatile bool eventoOcurrido = false;
volatile bool eventoOcurrido2 = false;

void IRAM_ATTR ISR() {
    if (digitalRead(botonPin) == LOW) {
        eventoOcurrido = true;
    } else {
        eventoOcurrido2 = true;
    }
}

void setup(){
	pinMode(botonPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(botonPin), ISR, CHANGE);
}

void loop(){
  if(eventoOcurrido){
    eventoOcurrido = false;
    digitalWrite(ledPin, HIGH);
  }
	if (eventoOcurrido2){
    eventoOcurrido2 = false;
    digitalWrite(ledPin, LOW);
  }
}