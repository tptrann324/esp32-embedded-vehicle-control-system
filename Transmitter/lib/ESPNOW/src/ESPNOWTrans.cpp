#include <Arduino.h>
#include <Wifi.h>
#include <esp_now.h>
#include "ESPNOWTrans.h" 

// Set up ESP-NOW
void ESPNOW::setupESPNOW(const uint8_t* receiverMAC){

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK){
        Serial.println("ESP-NOW initialization failed");
        return;
    }
    Serial.println("ESP-NOW receiver ready");

    // Initialize struct defined by ESP-NOW library
    esp_now_peer_info_t peerInfo = {};            
    memcpy(peerInfo.peer_addr, receiverMAC, 6);   
    peerInfo.channel = 0;
    peerInfo.encrypt = false; 

    // Add ESP32_Receiver 
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add receiver!");
        return;
    }
    Serial.println("ESP-NOW Transmitter Ready!");
}

// Send data to Receiver
void ESPNOW::sendData(const uint8_t* receiverMAC, const ControlData* car, int carSize) {
    esp_err_t result = esp_now_send(receiverMAC, (uint8_t*) car, carSize);

    if (result == ESP_OK) {
        Serial.println("Data Sent");
    }
    else {
        Serial.println("Failed to send data");
        result = esp_now_send(receiverMAC, (uint8_t*) car, carSize);
    }
}