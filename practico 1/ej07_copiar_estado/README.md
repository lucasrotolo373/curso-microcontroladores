# Ejercicio 7 — Copiar estado de un pulsador

## Consigna
Implementar un sketch que copie el estado de un pulsador a un LED.
Observar qué sucede si no hay pull-up.

## Descripción
El pin 21 lee el estado del pulsador y lo copia directamente al LED onboard (pin 2).
Sin lógica de flancos ni contadores, solo copia directa del estado.

## Conceptos clave
- INPUT_PULLUP: resistencia interna que jala el pin a HIGH por defecto
- Sin pull-up el pin queda flotante y capta ruido eléctrico del ambiente
- Con INPUT el LED queda semiprendido o parpadea sin tocar nada
- Con INPUT_PULLUP la lógica es invertida: botón en reposo = HIGH, presionado = LOW
