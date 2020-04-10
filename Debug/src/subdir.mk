################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/008spi_cmd_handling_it_alternate.c 

OBJS += \
./src/008spi_cmd_handling_it_alternate.o 

C_DEPS += \
./src/008spi_cmd_handling_it_alternate.d 


# Each subdirectory must supply rules for building sources it contributes
src/008spi_cmd_handling_it_alternate.o: ../src/008spi_cmd_handling_it_alternate.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -c -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/drivers/inc" -I"D:/Adam/Documents/Udemy/MasteringMicrocontrollerM1/CubeIDE/Workspace/stm32f4xx_drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/008spi_cmd_handling_it_alternate.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

