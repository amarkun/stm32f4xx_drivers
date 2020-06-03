# stm32f4xx_drivers

**NOTES**
- This repository is likely overly inclusive in terms of files needed (e.g. debuging and configuration files). I will work to thin this out.
- This code was written in an atttempt to follow course guidlines. With that in mind, I personally disagree with the style in which some of these scripts were coded.
   *I have mode some adjustments and have otherwise commented ares that I think could be improved
- I plan to edit some of this code to make it more robust. For example, I the I2C Rx interrupt functions should be built out.
    *Once this is done, some of the src files may no longer work, I will do my best to add comments to highlight this.

**Sofware**
STM32CubeIDE
STM32CubeMX
Arduino IDE
Saleae Logic

**EQUIPMENT**
(This will be updated with more specifics)
STM32F407VG Discovery board
Arduino Uno R3 board
Breadboard (not required)
Jumper wires
Saleae (not required)
Button
Resistors
LED

**SUMMARY**
Drivers and testing code based on the Udemy Mastering Microcontroller with Embedded Driver Development course.

This code is based on guidence from the Udemy Course [Mastering Microcontroller with Embedded Development](https://www.udemy.com/course/mastering-microcontroller-with-peripheral-driver-development/)

The course focused on the development and understanding of drviers for different peripherals, namely: GPIO, SPI, I2C, and USART.
The .c and .h files for these drivers can be found under the drivers/src and drivesr/inc folders.

In order to test out the driver files, several main files, found under the src/ folder, were created and tested.
Only one of these files at a time should be included in the build.
Many of these exercises required the use of the Arduino Uno R3 board.
Code for this board was provided by the course, and thus is not included in this repository.
