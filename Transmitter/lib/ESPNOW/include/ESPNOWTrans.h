#ifndef ESPNOWTRANS_H
#define ESPNOWTRANS_H

#include "ControlData.h"

void setupESPNOW(const uint8_t*);
void sendData(const uint8_t*, const ControlData*, int);

#endif