#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "ControlData.h"
#include "GPIO.h"
#include "Motor.h"
#include "ESPNOWReceiv.h"
#include "Buzzer.h"
#include "Failsafe.h"

ControlData Car;
Pin Receiv;
MotorControl Motor;
ESPNOW Recv;
Buzzer Horn;

unsigned long lastSignalTime = 0;

void setup() {
  Serial.begin(115200);
  
  // Attach GPIO
  Receiv.attachGPIO();

  // Attach Motor
  Motor.attachMotor(ENA, ENB, IN1, IN2, IN3, IN4);

  // Get MAC Address
  Recv.getMACAddress();

  // Initialize ESP-NOW and Receive Data
  Recv.ESPNOW_setup_receive();
  
  // Initialize Failsafe
  lastSignalTime = millis();
}

void loop() {
  
  //Check Fail Safe
  if (!checkFailSafe(lastSignalTime)) {
    Motor.stopMotor(&Car);
  }
  // Handle digital signal to move forward or back ward on left wheels
  Motor.forward_backward(Car.leftSpeed, IN1, IN2);

  // Handle digital signal to move forward or back ward on right wheels
  Motor.forward_backward(Car.rightSpeed, IN3, IN4);

  // Output Motor Speed
  Motor.speedOutput(&Car, 0, 1);

  // Horn Beep Once Press Joystick
  Horn.BeepOnce(&Car,BUZZER);
}



