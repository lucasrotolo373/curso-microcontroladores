#include <Arduino.h>

#define ledPin 2
#define botonPin 21
int estadoActual = 0;

void setup(){
	Serial.begin(115200);
	pinMode(botonPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop(){
	estadoActual = digitalRead(botonPin);
	if (estadoActual == LOW){
		digitalWrite(ledPin, HIGH);
	}else {
		digitalWrite(ledPin, LOW);
	}
}