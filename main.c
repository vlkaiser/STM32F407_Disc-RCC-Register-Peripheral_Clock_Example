/***************************************************************************************************************************
* This file is subject to the terms and conditions defined in file 'LICENSE.txt', 
* which is part of this source code package. 
*
* Project									: RCC Register Peripheral Clock Enable/Disable Example
* Program Name						: STM32F407_Disc-RCC-Register-Peripheral_Clock_Example
* Author									: vkaiser
* Date Created						: Oct. 03, 2019
* 
* Purpose									: To demonstrate the RCC registers for clocks, and how to enable/disable them for peripherals without CubeMX
*
*														
* MCU											: STM32F407VGT6
* Language								: C
* Hardware Modifications	: N/A
* Debugger								: ST-Link Debugger (on-board)
*
* Repo / Revision History	: https://github.com/vlkaiser/STM32F407_Disc_Test_1
*
* - Special Setup -
* Keil Pack Installer 		: Device Specific DFP
*													:
*		
* Revision History				:
* 	Date				Author			Notes
* 						vkaiser			- Initial commit
*
***************************************************************************************************************************/
#include <stdint.h>	
#include "stm32f407xx.h"                  // Device header
/**************************************************************************************************************************/
/* Main */
int main(void)
{
	RCC_TypeDef *pRCC;						//pointer to clock controller struct
	pRCC = RCC;										//Peripheral definition
	
	pRCC->APB2ENR |= (1 << 8);		//Enable ADC1 clock
	pRCC->AHB1ENR |= (1 << 0);		//Enable GPIOA clock
	
	GPIO_TypeDef *pGPIO;					//pointer to GPIO struct
	pGPIO = GPIOA;								//peripheral definition
		
	ADC_TypeDef *pADC;
	pADC = ADC1;
	
	pADC->CR1 = 0x55;					//Write arbitrary value to arbitrary register 
	pGPIO->BSRR = 0x11;				

	return 0;
}
