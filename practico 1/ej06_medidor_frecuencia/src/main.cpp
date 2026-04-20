#include <Arduino.h>

#define pinSalida 18
#define pinEntrada 19

float periodo = 0.0;
uint64_t t_alto = 0;
uint64_t last = 0;
uint64_t tiempoRising1 = 0;
uint64_t tiempoRising2 = 0;
uint64_t tiempoFalling = 0;
float duty = 0.0;
int ultimoEstado = HIGH;
bool estadoSalida = LOW;
bool primerFlanco = false;
int tiempoAlto = 200;
int tiempoBajo = 800;


void setup() {
  Serial.begin(115200);
  pinMode(pinSalida, OUTPUT);
  pinMode(pinEntrada, INPUT_PULLDOWN);
}

void loop() {
  if (estadoSalida == HIGH && millis() - last > tiempoAlto) {
    estadoSalida = LOW;
    digitalWrite(pinSalida, estadoSalida);
    last = millis();
} else if (estadoSalida == LOW && millis() - last > tiempoBajo) {
    estadoSalida = HIGH;
    digitalWrite(pinSalida, estadoSalida);
    last = millis();
}

  int estadoActual = digitalRead(pinEntrada);
  if (estadoActual != ultimoEstado){
    if (estadoActual == HIGH){
      if (!primerFlanco){
        tiempoRising1 = micros();
        primerFlanco = true;
      } else {
          tiempoRising2 = micros();
          periodo = tiempoRising2 - tiempoRising1;
          t_alto = tiempoFalling - tiempoRising1;
          duty = (t_alto / periodo) * 100;
          Serial.print("Frecuencia: ");
          Serial.print(1000000.0 / periodo);
          Serial.println(" Hz");
          Serial.print("Ciclo util: ");
          Serial.print(duty);
          Serial.println(" %");
          tiempoRising1 = tiempoRising2;
      }
    } else {
        tiempoFalling = micros();
    }
    ultimoEstado = estadoActual;
  }

}