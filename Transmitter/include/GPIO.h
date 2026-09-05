#ifndef GPIO_H
#define GPIO_H

// GPIO
constexpr int xPin = 34;
constexpr int yPin = 35;
constexpr int BUTTON = 27;

class Pin {
public:
    void attachGPIO();
};
#endif
