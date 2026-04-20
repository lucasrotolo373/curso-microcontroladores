# Ejercicio 9 — Copiar estado de pulsador con interrupción externa

## Consigna
Modificar el ejercicio 7 para que el evento se produzca ante una interrupción externa.

## Descripción
En lugar de polling, el pin 21 genera una interrupción en cualquier cambio de estado.
La ISR lee el estado actual del pin y setea la variable correspondiente.
El loop lee esas variables y actualiza el LED onboard (pin 2).

## Conceptos clave
- attachInterrupt() registra una función ISR para un pin y tipo de evento
- CHANGE dispara en cualquier flanco, FALLING solo en descendente, RISING solo en ascendente
- El ESP32 no soporta dos attachInterrupt en el mismo pin, el segundo pisa al primero
- Variables compartidas entre ISR y loop deben ser volatile
- La ISR debe ser corta, sin delay() ni Serial.println()
- IRAM_ATTR coloca la ISR en RAM interna para ejecución rápida
