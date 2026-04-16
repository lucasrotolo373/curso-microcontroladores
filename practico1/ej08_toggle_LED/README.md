# Ejercicio 8 — Toggle del LED con pulsador

## Consigna
Modificar el ejercicio 7 para que cada evento del pulsador provoque un cambio en el LED.

## Descripción
Cada flanco descendente del pulsador invierte el estado del LED onboard (pin 2).
El LED tiene su propia variable de estado independiente del botón.

## Conceptos clave
- Toggle: el LED recuerda su propio estado y lo invierte en cada evento
- Detección de flanco: comparar estadoActual con estadoAnterior para detectar cambios
- Debounce por tiempo: ignorar cambios más rápidos que 70ms
- La pregunta clave: ¿me importa el estado o el momento del cambio?
