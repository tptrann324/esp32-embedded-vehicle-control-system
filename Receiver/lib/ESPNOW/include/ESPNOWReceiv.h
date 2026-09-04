#ifndef ESPNOWRECEIV_H
#define ESPNOWRECEIV_H

#include <WiFi.h>
#include <esp_now.h>
#include "ControlData.h"

class ESPNOW {
public:
    // get MAC address
    void getMACAddress();
    
    // ESPNOW setup and receive data
    void ESPNOW_setup_receive();

};
#endif