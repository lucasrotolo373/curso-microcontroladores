# Ejercicio 6 — Medidor de frecuencia y ciclo útil

## Consigna
Implementar un medidor de frecuencia y ciclo útil por consola Serial.

## Descripción
El pin 18 genera una señal digital con tiempos configurables de HIGH y LOW.
El pin 19 mide esa señal detectando flancos y calculando:
- **Frecuencia** en Hz
- **Ciclo útil** en %

Conectar un cable jumper entre pin 18 y pin 19.

## Conceptos clave
- Detección de flancos por polling sin bloqueo (`millis()`)
- Medición de tiempo con `micros()` para mayor resolución
- Período = tiempo entre dos flancos ascendentes consecutivos
- Ciclo útil = t_alto / período * 100
- Generador no bloqueante con tiempos asimétricos de HIGH y LOW
