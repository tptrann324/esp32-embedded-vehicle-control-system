# **PINOUT**

1. **Controller - ESP32 Transmitter**

    
    |   Component  | GPIO |    Function   
    |--------------|------|---------------
    | Joystick VCC | 3.3V | Power Supply         
    | Joystick GND |  GND |   Ground          
    | Joystick VRx | IO34 |  Analog Input 
    | Joystick VRy | IO35 |  Analog Input 
    | Joystick SW  | IO27 | Digital Input 

2. **Car - ESP32 Receiver**
   
    |   Component  | GPIO | Function 
    |--------------|------|----------
    |   L298N ENA  | IO17 | Left PWM Speed & Turn Control
    |   L298N EN1  | IO18 | Left Forward/Backward Direction
    |   L298N EN2  | IO19 | Left Forward/Backward Direction
    |   L298N EN3  | IO21 | Right Forward/Backward Direction
    |   L298N EN4  | IO22 | Right Forward/Backward Direction
    |   L298N ENB  | IO23 | Right PWM Speed & Turn Control
    |   L298N GND  |  GND | Ground
    |   Buzzer +   | IO27 | Power Supply
    |   Buzzer -   |  GND | Ground

3. **L298N**
   
    |     L298N    |    Component   
    |--------------|----------------
    |   L298N 12V  |  AA battery +  
    |   L298N GND  |  AA battery -  
    |   L298N OUT1 | 2 Left Motor + 
    |   L298N OUT2 | 2 Left Motor - 
    |   L298N OUT3 | 2 Left Motor - 
    |   L298N OUT4 | 2 Left Motor + 

****Note: All GND should be connected together***

