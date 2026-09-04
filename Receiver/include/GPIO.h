#ifndef GPIO_H
#define GPIO_H

// MOTOR PIN
constexpr int ENA = 17;
constexpr int IN1 = 18;
constexpr int IN2 = 19;
constexpr int IN3 = 21;
constexpr int IN4 = 22;
constexpr int ENB = 23;

// Buzzer Pin
constexpr int BUZZER = 27;

class Pin{
public:
    void attachGPIO();
};
#endif