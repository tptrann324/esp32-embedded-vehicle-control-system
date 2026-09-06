#include <Arduino.h>
#include "debugTrans.h"

#ifdef DEBUG_ON
// --------DEBUG ESP-NOW TRANSMITTER--------

// Initialization Debug 
void initDebug(esp_err_t initResult) {
    if (initResult == ESP_OK) {
        Serial.println("ESP-NOW Transmitter: Initialization Done.");
    } else{
        Serial.println("ESP-NOW Transmitter Error: Failed to initialize.");
    }
}

// Adding ESP32_Receiver Debug
void addReceiver(esp_err_t addResult) {
    if (addResult == ESP_OK) {
        Serial.println("ESP-NOW Transmitter: Receiver Added.");
    } else {
        Serial.println("ESP-NOW Transmitter Error: Failed to add Receiver");
    }
}

// Sending Data Debug
void sendDataDebug(esp_err_t sendResult) {
    // Send message at the first time successfull
    // Then only print if the sendResult change
}

#endif  