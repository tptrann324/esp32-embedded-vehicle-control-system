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
void sendDataDebug(esp_err_t &lastSendResult, esp_err_t &currentSendResult) {
    // Send message at the first time successfull
    // Then only print if the sendResult change
    if (lastSendResult != currentSendResult) {   
        if (currentSendResult == ESP_OK) {
            Serial.println("Data Sent!");
        }
        else {
            Serial.println("Failed to send data!");
        }
    lastSendResult = currentSendResult;
    }
}

#endif  