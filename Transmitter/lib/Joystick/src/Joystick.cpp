#include <Arduino.h>
#include "Joystick.h"

extern ControlData Car;

// CONST Varriable for deadzone filtering
const int CENTER = 2048;
const int DEADZONE = 350;

// Read joystick Analog Value
int JoystickControl::joystickAnalogRead(int pin) {
    int value = analogRead(pin);
    return value;
}

// Read Joystick Digital Value
int JoystickControl::joystickDigitalRead(int btn) {
    int btnStat = digitalRead(btn);
    return btnStat;
}

// Manipulate Joystick Value
void JoystickControl::manipulateValue(ControlData* car, int xVal, int yVal) {
    int speed = 0;
    int turn = 0;

    // yVal Deadzone filter to calculate Speed
    if (abs(yVal - CENTER) < DEADZONE) {
        speed = 0;    // DEADZONE
    }
    else if ((yVal - CENTER) >= DEADZONE) {
        speed = map(yVal, CENTER + DEADZONE, 4095, 0, -255);
    }
    else {
        speed = map(yVal, 0, CENTER - DEADZONE, 255, 0); // 0
    }

    // xVal Deadzone filter to calculate Turn
    if (abs(xVal - CENTER) < DEADZONE) {  
        turn = 0;     // DEADZONE
    }
    else if ((xVal - CENTER) >= DEADZONE) {
        turn = map(xVal, CENTER + DEADZONE, 4095, 0, 255);
    }
    else {
        turn = map(xVal, 0, CENTER - DEADZONE, -255, 0);
    }

    // Caluculate and constrain leftSpeed and rightSpeed to prevent PWM overflow
    car->leftSpeed = constrain(speed + turn, -255, 255);
    car->rightSpeed = constrain(speed - turn, -255, 255);

    return;
}
