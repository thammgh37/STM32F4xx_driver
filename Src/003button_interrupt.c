/*
 * 003button_interrupt.c
 *
 *  Created on: Aug 2, 2023
 *      Author: ADMIN
 */


#include <stm32f407xx.h>
#include  <string.h>

void delay(){
	for(uint32_t i=0 ; i<500000/2;i++){

	}
}
int main(void){
	GPIO_Handle_t GpioLed;
	GPIO_Handle_t GpioButton;
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GpioButton,0,sizeof(GpioButton));

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&GpioLed);

	GpioButton.pGPIOx = GPIOA;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RT;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&GpioButton);

	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);
	while(1);
}

void EXTI0_IRQHandler(){
	delay();
	GPIO_IRQHandling(0);
	GPIO_ToggleOutputPin(GPIOD, 13);
}
