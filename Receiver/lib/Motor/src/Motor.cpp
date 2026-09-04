#include <Arduino.h>
#include "Motor.h"

// Attach Motor
void MotorControl::attachMotor(const int ENA, const int ENB){

    bool setupLeft = ledcSetup(0, 1000, 8);
    bool setupRight = ledcSetup(1, 1000, 8);
    if (!setupLeft || ! setupRight) {
        Serial.println("Failed to setup Motor");
    }
    ledcAttachPin(ENA, 0);
    ledcAttachPin(ENB, 1); 
    Serial.println("Motor is Ready!");
}

// Handle digital signal to move forward or back ward
void MotorControl::forward_backward(int speed, int smallIN, int bigIN) {
    if (speed == 0) {
        digitalWrite(smallIN,LOW);
        digitalWrite(bigIN,LOW);
    }
    else if (speed > 0){
        digitalWrite(smallIN, HIGH);
        digitalWrite(bigIN, LOW);
    }
    else {
        digitalWrite(smallIN, LOW);
        digitalWrite(bigIN, HIGH);
    }
}

// Output motor speed
void MotorControl::speedOutput(const ControlData* car, const int channel0, const int channel1) {
    ledcWrite(channel0, abs(car->leftSpeed));
    ledcWrite(channel1, abs(car->rightSpeed));
}

// Stop motor
void MotorControl::stopMotor(ControlData* car) {
    car->leftSpeed = 0;
    car->rightSpeed = 0;
}
