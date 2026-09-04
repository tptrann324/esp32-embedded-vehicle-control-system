// -------ESPNOW Receiver-------
// Get MAC address
// initialize ESP-NOW
// register callback
// check packet size/basic validity
// pass received data to system


#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "ControlData.h"
#include "ESPNOWReceiv.h"

extern ControlData Car;         // Do not create new Car, use the one imported from another file  
extern unsigned long lastSignalTime;

// get MAC address
void ESPNOW::getMACAddress() {
    WiFi.mode(WIFI_STA);

    delay(100);

    Serial.print("WiFi mode: ");
    Serial.println(WiFi.getMode());

    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
    return;
}

// Receive Function
void OnDataSent(const uint8_t* mac, const uint8_t* data, int len) {
    
    // check packet size/basic validity
    if (len == sizeof(ControlData)) {
        // pass received data to system
        memcpy(&Car, data, sizeof(ControlData));
        lastSignalTime = millis();          // Record the time received data
        Serial.println("Data Received.");
    }
    else {
        Serial.println("Failed to receive data.");
    }
    return;
}

// ESPNOW setup and receive data
void ESPNOW::ESPNOW_setup_receive() {
    WiFi.mode(WIFI_STA);

    // Initialize ESP-NOW
    esp_err_t init = esp_now_init();
    if (init != ESP_OK) {
        Serial.println("ESP-NOW Initialization Failed!");
        init = esp_now_init();
    }
    Serial.println("ESP-NOW Ready!");
    delay(100);

    // Register callback
    esp_now_register_recv_cb(OnDataSent);
}