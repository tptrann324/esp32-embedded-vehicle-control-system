#include <Arduino.h>
#include "GPIO.h"

void Pin::attachGPIO() {
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}