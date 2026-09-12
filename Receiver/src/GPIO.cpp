#include <Arduino.h>
#include "GPIO.h"

void Pin::attachGPIO() {
    
    // ATTACH MOTOR
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // ATTACH BUZZER
    pinMode(BUZZER, OUTPUT);
}