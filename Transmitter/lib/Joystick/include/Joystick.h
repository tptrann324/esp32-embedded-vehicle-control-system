#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "ControlData.h"

class JoystickControl {
public:
    // Read Joystick Analog Value
    int joystickAnalogRead(int);

    // Read Joystick Digital Value
    int joystickDigitalRead(int);

    // Manipulate Joystick Value
    void manipulateValue(ControlData*, int, int);
};
#endif