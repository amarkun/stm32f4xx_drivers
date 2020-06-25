################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/012i2c_slave_tx_string_alt.c \
../src/syscalls.c 

OBJS += \
./src/012i2c_slave_tx_string_alt.o \
./src/syscalls.o 

C_DEPS += \
./src/012i2c_slave_tx_string_alt.d \
./src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
src/012i2c_slave_tx_string_alt.o: ../src/012i2c_slave_tx_string_alt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -c -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/drivers/inc" -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/012i2c_slave_tx_string_alt.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/syscalls.o: ../src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -c -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/drivers/inc" -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

