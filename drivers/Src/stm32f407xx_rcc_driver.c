/*
 * stm32f407xx_rcc_driver.c
 *
 *  Created on: Aug 29, 2023
 *      Author: ADMIN
 */
#include <stm32f407xx_rcc_driver.h>

uint16_t AHB_PreScaler[8] = {2,4,8,16,64,128,256,512};
uint8_t APB_PreScaler[4] = { 2, 4 , 8, 16};

uint32_t RCC_GetPCLK1Value(void){
	uint32_t sysclk,AHBpre,APB1pre;
	uint32_t temp = (RCC->CFGR & 0x3);


	if ( temp == 0){
		sysclk = 16000000;
	}
	else if (temp == 1){
		sysclk = 8000000;
	}
	else if (temp == 2){
		// PLL source clock is selected
		//GetPLLValue();
	}

	temp = (RCC->CFGR >> 4) & 0xF;
	if (temp < 8){
		AHBpre = 1;
	}
	else {
		AHBpre = AHB_PreScaler[temp-8];
	}

	temp = (RCC->CFGR >> 10) & 0x7;
	if (temp < 8){
		APB1pre = 1;
	}
	else {
		APB1pre = APB_PreScaler[temp-4];
	}
}

uint32_t RCC_GetPCLK2Value(void){
	uint32_t sysclk,AHBpre,APB2pre;
	uint32_t temp = (RCC->CFGR & 0x3);


	if ( temp == 0){
		sysclk = 16000000;
	}
	else if (temp == 1){
		sysclk = 8000000;
	}
	else if (temp == 2){
		// PLL source clock is selected
		//GetPLLValue();
	}

	temp = (RCC->CFGR >> 4) & 0xF;
	if (temp < 8){
		AHBpre = 1;
	}
	else {
		AHBpre = AHB_PreScaler[temp-8];
	}

	temp = (RCC->CFGR >> 13) & 0x7;
	if (temp < 8){
		APB2pre = 1;
	}
	else {
		APB2pre = APB_PreScaler[temp-4];
	}
}
