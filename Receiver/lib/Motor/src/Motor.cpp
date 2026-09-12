#include <Arduino.h>
#include "Motor.h"
#include "GPIO.h"
#include "debugReceiv.h"

// Attach Motor
void MotorControl::attachMotor(const int ENA, const int ENB, const int EN1, const int EN2, const int EN3, const int EN4){

    bool setupLeft = ledcSetup(0, 1000, 8);
    bool setupRight = ledcSetup(1, 1000, 8);
    
    motorAttachDebug(setupLeft, setupRight);

    ledcAttachPin(ENA, 0);
    ledcAttachPin(ENB, 1); 

    // Set all to 0 at the beginning
    ledcWrite(0,0);
    ledcWrite(1,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
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
