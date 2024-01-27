/*
 * 018usart_testing.c
 *
 *  Created on: Sep 3, 2023
 *      Author: ADMIN
 */

// PD2 UART 5 : Rx
// PC12 UART 5 : Tx

#include "stm32f407xx.h"

uint8_t c;
USART_Handle_t uart5_handle;
void UART5_GPIOInits(void){
	GPIO_Handle_t UART5_pins;

	UART5_pins.GPIO_PinConfig.GPIO_PinAltFunMode = 8;
	UART5_pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	UART5_pins.GPIO_PinConfig.GPIO_PinOPType = GPIO_PIN_PU;
	UART5_pins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	UART5_pins.pGPIOx = GPIOD;
	UART5_pins.GPIO_PinConfig.GPIO_PinNumber = 2;
	GPIO_Init(&UART5_pins);

	UART5_pins.pGPIOx = GPIOC;
	UART5_pins.GPIO_PinConfig.GPIO_PinNumber = 12;
	GPIO_Init(&UART5_pins);
}


void UART5_Inits(void){
	uart5_handle.pUSARTx = UART5;
	uart5_handle.USART_Config.USART_Baud = USART_STD_BAUD_9600;
	uart5_handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	uart5_handle.USART_Config.USART_Mode = USART_MODE_TXRX;
	uart5_handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	uart5_handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	uart5_handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;

	USART_Init(&uart5_handle);
}

int main(void){
	UART5_GPIOInits();
	UART5_Inits();
	USART_PeripheralControl(UART5, ENABLE);
	while (1){
		USART_SendData(&uart5_handle, &c, 1);
	}
}
