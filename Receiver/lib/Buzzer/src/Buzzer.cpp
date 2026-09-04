#include <Arduino.h>
#include "ControlData.h"
#include "Buzzer.h"

extern ControlData Car;

void Buzzer::BeepOnce(const int Buzzer) {
    if (Car.horn == LOW) {      // PRESS = LOW = BEEP VOICE
        digitalWrite(Buzzer, HIGH);
    }
    else {
        digitalWrite(Buzzer, LOW);
    }
}