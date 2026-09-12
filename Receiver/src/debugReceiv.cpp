#include <Arduino.h>
#include "debugReceiv.h"
#include "ControlData.h"

#ifdef DEBUG_ON

//-------------DEBUG ESP-NOW RECEIVER------------

// Initialization Debug 
void initDebug(esp_err_t initResult) {
    if (initResult == ESP_OK) {
        Serial.println("ESP-NOW Receiver: Initialization Done.");
    } else{
        Serial.println("ESP-NOW Receiver Error: Failed to initialize.");
    }
}

// Data Received Debug
bool dataReceiveDebug(int len, bool &lastReceiveResult) {
    // Send message at the first time successfull
    // Then only print if the receiveResult change
    // Weakness: If data received is fail on the first time, it does not print any warning
    if (len == sizeof(ControlData)) {
        if (!lastReceiveResult) {       // lastReceiveResult = false
            Serial.println("ESP-NOW Receiver: Data Received.");
            lastReceiveResult = true;
        }   
        return true;
    }
    else {
        if (lastReceiveResult) {        // // lastReceiveResult = true
            Serial.println("ESP-NOW Receiver: Data Receive Error.");
            lastReceiveResult = false;
        }
        return false;
    }
}

// ---------------END ESP-NOW RECEIVER------------

// ---------------MOTOR DEBUG---------------------
// Motor Attach Debug
void motorAttachDebug(bool setupLeft, bool setupRight) {
    if (setupLeft && setupRight) {
        Serial.println("Motor: Attach Successful.");
    }
    else {
        Serial.println("Motor: Failed to attach motor.");
    }
}
#endif