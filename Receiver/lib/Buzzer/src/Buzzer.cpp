#include <Arduino.h>
#include "ControlData.h"
#include "Buzzer.h"

void Buzzer::BeepOnce(const ControlData* car, const int Buzzer) {
    if (car->horn == LOW) {      // PRESS = LOW = BEEP VOICE
        digitalWrite(Buzzer, HIGH);
    }
    else {
        digitalWrite(Buzzer, LOW);
    }
}