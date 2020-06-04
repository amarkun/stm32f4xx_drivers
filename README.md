# stm32f4xx_drivers

#SUMMARY

This repository was created in my pursuit to learn how to program using basic embedded development concepts and communication protocols. This code is mainly based on guidence from the Udemy Course [Mastering Microcontroller with Embedded Development](https://www.udemy.com/course/mastering-microcontroller-with-peripheral-driver-development/), however, I have improvised my own code in certain files, either for my own education or because I wanted to improve functionality. General topics covered in this course included: debugging, tranmission and reception of data, interrupts, data sheet review, and some basic electircal concepts/equations. The development in this course focused on drviers for different peripherals, namely: GPIO, SPI, I2C, and USART.

#STRUCTURE

The .c and .h files for these drivers can be found under the drivers/src and drivesr/inc folders. In order to test out the driver files, several main files, found under the src/ folder, were created and tested. Only one of these files at a time should be included in the build. This can be changed through the "Properties" options for a specific file. Many of these exercises required the use of the Arduino Uno R3 board Code for this board was provided by the course, and thus is not included in this repository.

More specific instructions will be found in the EXECUTION section, however, this sectoin has not been yet been complete as I want to test downloading this repository and running it from scratch.



#SOFTWARE

* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) - Eclipse IDE for STM boards for compiling and downloading code the STM boards
* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) - STM software used for board configuration and generating code.
* [Arduino IDE](https://www.arduino.cc/en/main/software) - Ardunio IDE for compiling and downloading code to Arduino boards
* [Saleae Logic](https://www.saleae.com/downloads/) (Not Required) - Software used with the Saleae Logic Analyzer. Mainly used for debugging

#EQUIPMENT

(Aside from the boards, parts do not need to be the ones specifically from the links)
* [STM32F407VG Discovery board](https://www.st.com/en/microcontrollers-microprocessors/stm32f407vg.html)
* [Arduino Uno R3 board](https://store.arduino.cc/usa/arduino-uno-rev3)
* (Jumper Wires)[https://www.sparkfun.com/categories/70?filter_option%5Bsubcategory%5D%5B%5D=category_141&filter_price_floor=&filter_price_ceil=] - M/M, M/F, F/F
* [Button](https://www.sparkfun.com/products/9190)
* [Resistors](https://www.sparkfun.com/products/10969)
* [LED](https://www.sparkfun.com/products/11453)
* [Breadboard](https://www.sparkfun.com/categories/302) (not required)
* [Saleae](https://www.saleae.com/?gclid=CjwKCAjwt-L2BRA_EiwAacX32XsoGm0Yp4Q8MC6PGyVUD8ljaMZ1ytSmwZ6YtaiI7lsXhTjVUKWudRoC-qUQAvD_BwE) (not required) - used for debugging

#EXECUTION

*Coming soon*

#NOTES & FINDINGS
##NOTES
1. This repository is likely overly inclusive in terms of files needed (e.g. debuging and configuration files). I will work to thin this out.
    - This code was written in an atttempt to follow course guidlines. With that in mind, I personally disagree with the style in which some of these scripts were coded.

2. I have mode some adjustments and have otherwise commented ares that I think could be improved
3. I plan to edit some of this code to make it more robust. For example, I the I2C Rx interrupt functions should be built out.
    - Once this is done, some of the src files may no longer work, I will do my best to add comments to highlight this.
 #FINDNIGS
