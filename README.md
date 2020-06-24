# stm32f4xx_drivers

## SUMMARY

This repository was created in my pursuit to learn how to program using basic embedded development concepts and communication protocols. This code is mainly based on guidence from the Udemy Course [Mastering Microcontroller with Embedded Development](https://www.udemy.com/course/mastering-microcontroller-with-peripheral-driver-development/), however, I have improvised my own code in certain files, either for my own education or because I wanted to improve functionality. General topics covered in this course included: debugging, tranmission and reception of data, interrupts, data sheet review, and some basic electircal concepts/equations. The development in this course focused on drviers for different peripherals, namely: GPIO, SPI, I2C, and USART.

## STRUCTURE

The .c and .h files for these drivers can be found under the drivers/src and drivesr/inc folders. In order to test out the driver files, several main files, found under the src/ folder, were created and tested. Only one of these files at a time should be included in the build. This can be changed through the "Properties" options for a specific file. Many of these exercises required the use of the Arduino Uno R3 board Code for this board was provided by the course, and thus is not included in this repository. That code can be found [here](https://github.com/niekiran/MasteringMCU/tree/master/Resources/Arduino).

More specific instructions will be found in the EXECUTION section, however, this sectoin has not been yet been complete as I want to test downloading this repository and running it from scratch.

### SRC FILES

* **001led_toggle.c** - Toggle an onboard led using a delay
* **002led_button.c** - Toggle an onboard led on a button press
* **003led_button_ext.c** - Toggle an external led on button press
* **004button_interrupt.c** - Toggle an external led on button press using an interrupt
* **005spi_tx_testing.c** - Send string from STM board using SPI Tx code
* **006spi_txonly_arduino.c** - Send string from STM Board to Arduino Slave on button press
* **007spi_cmd_handling.c** - Send commands from STM Board to Arduino Slave on button press
* **007spi_cmd_handling_anon_refactor.c** - Send commands from STM Board to Arduino Slave on button press. This was a personal attempt to refactor the code to be more anonymized
* **008spi_cmd_handling_it.c** - This code wsa not explained in the course. As this was my first introduction to communication intterupts, I wasn't sure what this code was doing. I will need to review this now that I understand more and test it out. It looks like it needs to be edited.
* **008spi_cmd_handling_it_alternate.c** - Code based on another students attempts to test out spi interrupt communication. Used because no explination was made for the previous code. Sends commands [link to code](https://github.com/nemanjadjekic/stm32f446xx_drivers/blob/master/Src/Tests/009_SPI_TxRx_Arduino_IRQ.c)
* **009i2c_master_tx_testing.c** - Sends strings from STM msater to Arduino slave via I2C on button press (in blocking mode)
* **010i2c_master_rx_testing.c** - Sends commands to, then reads string from, Ardino slave from STM master on button press (in blocking mode)
* **011i2c_master_rx_testing_it.c** - Sends commands to, then reads string from, Ardino slave from STM master on button press using interrupts (non-blocking mode)
* **012i2c_slave_tx_string.c** - Receives string on STM slave from Arduino master using interrupts (non-blocking mode). String is limited to 32 bytes. (I feel that the I2C interrupt receive code here is implemented in a lazy way and am planning to refactor).
* **013i2c_slave_tx_string2.c** - Receives string on STM slave from Arduino master using interrupts (non-blocking mode). String is NOT limited to 32 bytes. (I feel that the I2C interrupt receive code here is implemented in a lazy way and am planning to refactor).
* **014usart_tx.c** - Sends string from STM to Arduino via USART in blocking mode on button press
* **015usart_case.c** - Sends 1 of 3 strings from STM to Arduino, then receives the same string from the Arduino with the capitlization switched on button press. Sends data in blocking mode, receives data using interrupts (non-blocking mode).

## SOFTWARE

* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) - Eclipse IDE for STM boards for compiling and downloading code the STM boards
* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) - STM software used for board configuration and generating code.
* [Arduino IDE](https://www.arduino.cc/en/main/software) - Ardunio IDE for compiling and downloading code to Arduino boards
* [Saleae Logic](https://www.saleae.com/downloads/) (Not Required) - Software used with the Saleae Logic Analyzer. Mainly used for debugging

## EQUIPMENT
(Not all equipment is needed for every test file, 
(Aside from the boards, parts do not need to be the ones specifically from the links)
* [STM32F407VG Discovery board](https://www.st.com/en/microcontrollers-microprocessors/stm32f407vg.html)
* [Arduino Uno R3 board](https://store.arduino.cc/usa/arduino-uno-rev3)
* [Jumper Wires](https://www.sparkfun.com/categories/70?filter_option%5Bsubcategory%5D%5B%5D=category_141&filter_price_floor=&filter_price_ceil=) - M/M, M/F, F/F
* [Button](https://www.sparkfun.com/products/9190)
* [Resistors](https://www.sparkfun.com/products/10969)
* [LED](https://www.sparkfun.com/products/11453)
* [Breadboard](https://www.sparkfun.com/categories/302) (not required)
* [Saleae](https://www.saleae.com/?gclid=CjwKCAjwt-L2BRA_EiwAacX32XsoGm0Yp4Q8MC6PGyVUD8ljaMZ1ytSmwZ6YtaiI7lsXhTjVUKWudRoC-qUQAvD_BwE) (not required) - used for debugging

## EXECUTION

*Coming soon*

## NOTES & FINDINGS
### NOTES
1. This repository is likely overly inclusive in terms of files needed (e.g. debuging and configuration files). I will work to thin this out.
    - This code was written in an atttempt to follow course guidlines. With that in mind, I personally disagree with the style in which some of these scripts were coded.

2. I have mode some adjustments and have otherwise commented ares that I think could be improved
3. I plan to edit some of this code to make it more robust. For example, I the I2C Rx interrupt functions should be built out.
    - Once this is done, some of the src files may no longer work, I will do my best to add comments to highlight this.
 ## FINDINGS/LESSONS
 1. *Serial print statements can mess up communication* - This problem occured when I could not get the 006spi_txonly_arduino.c code to work. At this point I did not have a logic analyzer, so I had a lot of trouble determining where the problem was. My initial problem had to due with mismatched CPOL and CPHA values. However, this did not solve my problem. After much debugging (and asking reddit), I learned that the serial print statements I had initially placed in the Arduino code was slowing down the communication so much that it was not sending data when the STM board was expecting to receive data (I was only getting the last letter of the string). Here's the [post](https://www.reddit.com/r/embedded/comments/fkj181/spi_communication_problem/)
 2. *Make sure to check how flags are cleared when using interrupts* - This problem occured when testing the 011i2c_master_rx_testing_it.c code. The test code first sends data, and then receives data (both in non-blocking mode), however, I was getting stuck on the reception part. After reviewing the RM, I realized that the TXE flag (and RXNE), which triggers an interrupt, is cleared when a start condition is generated. In both the I2C_MasterSendDataIT and I2C_MasterReceiveDataIT functions, I was generating the start condition after enablind the interrupts, which was causing a continous interrupt to occur. I did this initially because I thought that it would be better to have all control bits set before starting communication. Hoever, in this situation, the TXE flag was still set after the first send data call, so when I enabled the interrupt control bits, the TXE intterupt was being triggered continuously, even though the application was supposed to be reading data. So even though the Ardunio was sending data, the STM was stuck in an infinite TXE interrupt loop, and RXNE was never being set. I fixed this problem by moving the generate start condition code to *before* the interrupt control bits were enabled, allowing the TXE to be cleared at the proper time. In reflection, perhaps I should clear this when tranmission ends with a dummy write or another method.
