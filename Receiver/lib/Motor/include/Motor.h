#ifndef MOTOR_H
#define MOTOR_H

#include "ControlData.h"

class MotorControl{
public:

    // Attach Motor
    void attachMotor(const int, const int );

    // Handle digital signal to move forward or back ward
    void forward_backward(int, int, int);

    // Output motor speed
    void speedOutput(const ControlData*, const int, const int);

    // Stop motor
    void stopMotor(ControlData*);
};
#endif