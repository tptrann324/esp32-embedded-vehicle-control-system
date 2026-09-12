#include <Arduino.h>
#include <Wifi.h>
#include <esp_now.h>
#include "ESPNOWTrans.h" 
#include "debugTrans.h"

// Set up ESP-NOW
void setupESPNOW(const uint8_t* receiverMAC) {

    // Initialize ESP-NOW
    esp_err_t initResult = esp_now_init();
    initDebug(initResult);

    // Initialize struct defined by ESP-NOW library
    esp_now_peer_info_t peerInfo = {};            
    memcpy(peerInfo.peer_addr, receiverMAC, 6);   
    peerInfo.channel = 0;
    peerInfo.encrypt = false; 

    // Add ESP32_Receiver 
    esp_err_t addResult = esp_now_add_peer(&peerInfo);
    addReceiverDebug(addResult);
}

// Send data to Receiver
void sendData(const uint8_t* receiverMAC, const ControlData* car, int carSize, esp_err_t &lastResult, esp_err_t &currentResult) {
    currentResult = esp_now_send(receiverMAC, (uint8_t*) car, carSize);

    dataSendDebug(lastResult, currentResult);
    delay(50);
}