///*
// * 010i2c_master_tx_testing.c
// *
// *  Created on: Aug 15, 2023
// *      Author: ADMIN
// */
//
//
//#include<stdio.h>
//#include<string.h>
//#include "stm32f407xx.h"
//
//#define SLAVE_ADDR  0x68
//I2C_Handle_t I2C1handle;
//uint8_t buffer[] = "Xin chao toi ten la THA";
//
//void delay(void)
//{
//	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
//}
//
///*
// * PB8 --> I2C1_SCL
// * PB9 --> I2C1_SDA
// * ALT function mode : 4
// */
//
//void I2C1_GPIOInits(void)
//{
//	GPIO_Handle_t I2CPins;
//
//	I2CPins.pGPIOx = GPIOB;
//	I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
//	I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
//	I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
//	I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
//	I2CPins.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_FAST;
//
//	I2CPins.GPIO_PinConfig.GPIO_PinNumber = 8;
//	GPIO_Init(&I2CPins);
//
//	I2CPins.GPIO_PinConfig.GPIO_PinNumber = 9;
//	GPIO_Init(&I2CPins);
//}
//
//void I2C1_Inits(void)
//{
//	I2C1handle.pI2Cx = I2C1;
//	I2C1handle.I2C_Config.I2C_AckControl = I2C_ACK_ENABLE;
//	I2C1handle.I2C_Config.I2C_DeviceAddress = 0x61;
//	I2C1handle.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;
//	I2C1handle.I2C_Config.I2C_SCLSpeed    = I2C_SCL_SPEED_SM;
//
//	I2C_Init(&I2C1handle);
//}
//
//void GPIO_ButtonInit(void)
//{
//	GPIO_Handle_t GPIOBtn;
//
//	//this is btn gpio configuration
//	GPIOBtn.pGPIOx = GPIOA;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
//	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
//
//	GPIO_Init(&GPIOBtn);
//
//}
//
//int main(void){
//	GPIO_ButtonInit();
//	I2C1_GPIOInits();
//	I2C1_Inits();
//	I2C_PeripheralControl(I2C1, ENABLE);
//
//	while (1){
//		while (!GPIO_ReadFromInputPin(GPIOB, 0));
//		I2C_MasterSendData(&I2C1handle, buffer, strlen((char*)buffer), SLAVE_ADDR,0);
//	}
//}
/*
 * 010i2c_master_tx_testing.c
 *
 *  Created on: Feb 24, 2019
 *      Author: admin
 */


#include<stdio.h>
#include<string.h>
#include "stm32f407xx.h"

extern void initialise_monitor_handles();
#define MY_ADDR 0x61;

#define SLAVE_ADDR  0x68

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

I2C_Handle_t I2C1Handle;

//some data
uint8_t rcv_buf[32];
/*
 * PB6-> SCL
 * PB9 or PB7 -> SDA
 */

void I2C1_GPIOInits(void)
{
	GPIO_Handle_t I2CPins;

	I2CPins.pGPIOx = GPIOB;
	I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	/*
	 * Note : In the below line use GPIO_NO_PUPD option if you want to use external pullup resistors, then you have to use 3.3K pull up resistors
	 * for both SDA and SCL lines
	 */
	I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	I2CPins. GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//scl
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GPIO_Init(&I2CPins);


	//sda
	//Note : since we found a glitch on PB9 , you can also try with PB7
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;

	GPIO_Init(&I2CPins);


}

void I2C1_Inits(void)
{
	I2C1Handle.pI2Cx = I2C1;
	I2C1Handle.I2C_Config.I2C_AckControl = I2C_ACK_ENABLE;
	I2C1Handle.I2C_Config.I2C_DeviceAddress = MY_ADDR;
	I2C1Handle.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;
	I2C1Handle.I2C_Config.I2C_SCLSpeed = I2C_SCL_SPEED_SM;

	I2C_Init(&I2C1Handle);

}

void GPIO_ButtonInit(void)
{
	GPIO_Handle_t GPIOBtn;

	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GPIOBtn);

}


int main(void)
{
	uint8_t command = 0x51;
	uint8_t len;

	initialise_monitor_handles();

	printf("Application is running\n");

	GPIO_ButtonInit();
	I2C1_GPIOInits();
	I2C1_Inits();
	I2C_PeripheralControl(I2C1,ENABLE);
	I2C_ManageAcking(I2C1Handle.pI2Cx, ENABLE);

	while(1)
	{
		while( ! GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) );
		delay();
		I2C_MasterSendData(&I2C1Handle,&command,1, SLAVE_ADDR, 1);
		I2C_MasterReceiveData(&I2C1Handle,&len,1, SLAVE_ADDR, 1);
		command = 0x52;
		I2C_MasterSendData(&I2C1Handle,&command,1, SLAVE_ADDR, 1);
		I2C_MasterReceiveData(&I2C1Handle,rcv_buf,len, SLAVE_ADDR, 0);
		rcv_buf[len+1] = '\0';
		printf("Data : %s",rcv_buf);
	}
}
