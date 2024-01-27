/*
 * 002led_button.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ADMIN
 */


#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

void delay(){
	for (uint32_t i = 0; i<500000;i++){

	}
}
int main(void){
	GPIO_Handle_t gpioLed;
	gpioLed.pGPIOx = GPIOA;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOA_PCLK_EN();
	GPIO_Init(&gpioLed);


	GPIO_Handle_t gpioButton;
	gpioButton.pGPIOx = GPIOA;
	gpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	gpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	gpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOA_PCLK_EN();
	GPIO_Init(&gpioButton);

	while(1){
//		if(GPIO_ReadFromInputPin(GPIOA, 0)){
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
			delay();
//		}
	}
	return 0;
}
