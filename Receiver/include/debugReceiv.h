#ifndef DEBUGRECEIV_H
#define DEBUGRECEIV_H

// Comment out the line below to turn off debug
#define DEBUG_ON

void initDebug(esp_err_t);                                  // Initialization Debug
bool dataReceiveDebug(int, bool&);                          // Data Receive Debug
void motorAttachDebug(bool, bool);     // Motor Attach Debug

#endif