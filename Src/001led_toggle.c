/*
 * 001led_toggle.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ADMIN
 */


#include <stm32f407xx.h>

void delay(){
	for (uint32_t i = 0; i<500000;i++){

	}
}
int main(void){
	GPIO_Handle_t gpioLed;
	gpioLed.pGPIOx = GPIOD;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOD_PCLK_EN();
	GPIO_Init(&gpioLed);

	while(1){
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay();
	}
	return 0;
}
