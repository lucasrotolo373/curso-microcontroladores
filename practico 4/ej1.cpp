#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] = {19, 18, 17, 16};
byte colPins[COLS] = {15, 14, 13, 12};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(115200);
}

void loop() {
    char key = keypad.getKey();
    if (key) {
        Serial.println(key);
    }
}