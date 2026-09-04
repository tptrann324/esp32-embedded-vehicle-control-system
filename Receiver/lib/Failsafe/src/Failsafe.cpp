// -------FAILSAFE-------
// timeout
// packet validation
// sequence number
// connection/liveness state
// decide whether motor command is safe

#include <Arduino.h>
#include "Failsafe.h"

extern unsigned long lastSignalTime;

const unsigned long TIMEOUT = 1000;

bool checkFailSafe(unsigned long lastSignalTime) {
    if ((millis() - lastSignalTime) > TIMEOUT ) {
        return false;       // Not safe
    }
    return true;
}