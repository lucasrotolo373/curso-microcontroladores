#include <Arduino.h>

#define pinboton 21
#define pinAnalogico 35
uint64_t last = 0;
// Agregamos una variable para recordar el pasado. 
// Arranca en HIGH porque tenemos INPUT_PULLUP.
int ultimoEstado = HIGH; 

void setup() {
  Serial.begin(115200);
  pinMode(pinboton, INPUT_PULLUP);
  randomSeed(analogRead(pinAnalogico));
}

void loop() {
  if(millis() - last > 100){
    int estadoActual = digitalRead(pinboton);
    if (estadoActual != ultimoEstado) {
      if (estadoActual == LOW) {
        int valor = random(1, 7);
        Serial.println(valor);
      } 
    }
    last = millis();
    ultimoEstado = estadoActual;
  }
}