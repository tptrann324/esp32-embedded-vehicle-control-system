#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "ControlData.h"
#include "GPIO.h"
#include "Joystick.h"
#include "ESPNOWTrans.h"

ControlData Car;
Pin Trans;
JoystickControl Joystick;

esp_err_t lastSendResult = (esp_err_t) 1;
esp_err_t currentSendResult = ESP_FAIL;


//MAC Address: 00:70:07:26:C2:40
uint8_t receiverMAC[] = {0x00, 0x70, 0x07, 0x26, 0xC2, 0x40};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);    // Turn on WiFi station

  // Attach  Joystick GPIO
  Trans.attachGPIO();

  // ESP-NOW setup
  setupESPNOW(receiverMAC);
  delay(100);
}

void loop() {
  
  // Read Joystick Values
  int xVal = Joystick.joystickAnalogRead(xPin);
  int yVal = Joystick.joystickAnalogRead(yPin);
  Car.horn = Joystick.joystickDigitalRead(BUTTON);
  
  // Manipulate Values
  Joystick.manipulateValue(&Car, xVal, yVal);
  
  // Send Data
  sendData(receiverMAC, &Car, sizeof(Car), lastSendResult, currentSendResult);
  delay(20);
}

