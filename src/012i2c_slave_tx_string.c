/*
 * 012i2c_slave_tx_string.c
 *
 *  Created on: May 25, 2020
 *      Author: Adam
 */

//TODO: Once the driver code is modified correctly with the slave send and receive (and IT versions),
//		this code will not longer function

#include <stdio.h>
#include <string.h>
#include "stm32f407xx.h"


/*
 * PB6 --> I2C_SCL
 * PB9 --> I2C_SDA
 * ALT Function mode: 4
 */


//STM defines these here as "global variables"
I2C_Handle_t hI2C1;
GPIO_Handle_t I2Cpins;
GPIO_Handle_t GpioBtn;
uint8_t MESSAGE[32] = "STM32 Slave mode testing..";
uint32_t MESSAGE_LEN = strlen((char*)MESSAGE);


void I2C_GPIO_Setup(void);
void GPIO_ButtonInit(void);
void I2C_Setup(void);

void delay(int time){
	for(uint32_t i=0; i<time; i++);
}

#define SLAVE_ADDR	0x68
#define My_ADDR SLAVE_ADDR

#define COMMAND_READ_LENGTH		0x51
#define COMMAND_READ_DATA		0x52



//NOTE: mishandling if TXE is not cleared, but I2C_MasterReceiveDataIT is not set
int main(void) {
	uint8_t messageLength;

	printf("Hello World\n");
	//initizalize button
	GPIO_ButtonInit();

	//This function is used to initialize the gpio pins to behave as I2C pins
	I2C_GPIO_Setup();

	//This function is used to initialize the SPI peripheral
	I2C_Setup();

	//I2C IRQ Configurations
	I2C_IRQInterruptConfig(IRQ_NO_I2C1_EV, ENABLE);
	I2C_IRQInterruptConfig(IRQ_NO_I2C1_ER, ENABLE);

	//must enable interrupt control bits
	I2C_SlaveControlCallbackEvents(hI2C1.pI2Cx, ENABLE);

	//Course uses the PeripheralControl function to enable I2C here, but I implemented this in the read and write functions
	//course also enables acking here, but I do this in the receive function to match the STM code

}

void I2C_GPIO_Setup(void) {

	I2Cpins.pGPIOx = GPIOB;
	I2Cpins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	I2Cpins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	I2Cpins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_OD;
	I2Cpins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
	I2Cpins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//SCL
	I2Cpins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	GPIO_Init(&I2Cpins);

	//SDL
	//changed from pin 9 because of little glitch (not sure if this is happening on my board, but changing anyway)
	I2Cpins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	GPIO_Init(&I2Cpins);


}
void GPIO_ButtonInit(void){

	// configure button
	//Set up PA0 to be an input for the button press
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioBtn);
}
void I2C_Setup(void){
	hI2C1.pI2Cx = I2C1;
	hI2C1.I2C_Config.I2C_SCLSpeed = I2C_SCL_SPEED_SM;
	hI2C1.I2C_Config.I2C_DeviceAddress = MY_ADDR;
	hI2C1.I2C_Config.I2C_ACKControl = I2C_ACK_ENABLE;
	hI2C1.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;

	I2C_Init(&hI2C1);
}

void I2C1_EV_IRQHandler(void){
	I2C_EV_IRQHandling(&hI2C1);
}

void I2C1_ER_IRQHandler(void){
	I2C_ER_IRQHandling(&hI2C1);
}


//TODO: Modify this code so the transfer of data does not occur here, but in the driver code
//		I think this will consist of changing the slave functions to it functions
void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle, uint8_t appEvent){
	//NOTE: wouldn't a better way to send the data to be to have a length?
	// and shouldn't this be implemented in the driver code?
	static uint8_t commandCode = 0;
	static uint8_t count = 0;

	switch(appEvent)
	{
	case I2C_EV_DATA_REQ:
		//Master wants some data. Slave has to send it
		if(commandCode == 0x51)
		{
			//send the length information to the master
			//NOTE: course code uses strlen function here, but I don't think that should be used during it handling
			I2C_SlaveSendData(pI2CHandle->pI2Cx, MESSAGE_LEN);
		} else if (commandCode == 0x52)
		{
			//send the contents of MESSAGE
			I2C_SlaveSendData(pI2CHandle->pI2Cx, MESSAGE[count++]);
		}
		break;
	case I2C_EV_DATA_RCV:
		//Data is waiting for the slave to read. Slave has to read it
		COMMAND_CODE = I2C_SlaveReceiveData(pI2CHandle->pI2Cx);
		break;
	case I2C_EV_TX_CMPLT:
		printf("Tx is completed\n");
		break;
	case I2C_EV_RX_CMPLT:
		printf("Rx is completed\n");
		rxCmplt = SET;
		break;
	case I2C_EV_STOP:
		//This happens only during slave reception.
		//Master has ended the I2C communication with the slave.
		break;
	case I2C_ER_BERR:
		//occurs when a start or stop condition happens in a place it shouldn't
		printf("Error: Bus error\n");
		I2C_CloseSendData(&hI2C1);
		I2C_CloseReceiveData(&hI2C1);
		if(I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_SR2, I2C_FLAG_MSL)){
			//master mode
			I2C_GenerateStopCondition(hI2C1.pI2Cx);
		}
		while(1);
		break;
	case I2C_ER_ARLO:
		//In master mode, occurs when arbitration is lost to another master
		printf("Error: Arbitration lost\n");
		I2C_CloseSendData(&hI2C1);
		I2C_CloseReceiveData(&hI2C1);
		I2C_GenerateStopCondition(hI2C1.pI2Cx);
		while(1);
		break;
	case I2C_ER_AF:
		//This happens only during slave txing
		//Master has sent the NACK, so slave should stop sending more data
		//invalidate command code
		commandCode = 0xff;
		cnt = 0;
		break;
	case I2C_ER_OVR:
		//In master mode, occurs when data overrun in reception or transmission
		printf("Error: Overrun error\n");
		I2C_CloseSendData(&hI2C1);
		I2C_CloseReceiveData(&hI2C1);
		I2C_GenerateStopCondition(hI2C1.pI2Cx);
		while(1);
		break;
	case I2C_ER_TIMEOUT:
		//SCL remaind low for 25ms
		//or in master mode: cumulative clock low extend time more than 10ms (Tlow:mext)
		//or in slave mode: cumulative clock low extend time more than 25ms (Tlow:mext)
		//In master mode: stop condition sent by hardware
		//In slave mode: slave reset communication and lines are released
		printf("Error: Communication Timeout\n");
		I2C_CloseSendData(&hI2C1);
		I2C_CloseReceiveData(&hI2C1);
		while(1);
		break;
	default:
		printf("Something unexpected happened\n");
		while(1);
	}
}
