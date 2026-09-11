#ifndef DEBUG_TRANS_H
#define DEBUG_TRANS_H

//-------------------------------------------------------
// Comment out the following line to disable debug output
#define DEBUG_ON
//-------------------------------------------------------


// --------DEBUG ESP-NOW TRANSMITTER--------
void initDebug(esp_err_t);                         // Initialization Debug 
void addReceiverDebug(esp_err_t);                  // Adding ESP32_Receiver Debug
void dataSendDebug(esp_err_t, esp_err_t);          // Sending Data Debug
//----------------------------------------


#endif // DEBUG_TRANS_H