/*
 * func.h
 *
 *  Created on: Nov 26, 2024
 *      Author: nguye
 */

#ifndef INC_FUNC_H_
#define INC_FUNC_H_

#include "main.h"

void turnREDLED()
{
//	HAL_GPIO_WritePin(GPIOA, red_led_Pin, 1);
//	HAL_GPIO_WritePin(GPIOA, yellow_led_Pin, 0);
//	HAL_GPIO_WritePin(GPIOA, green_led_Pin, 0);

	HAL_GPIO_TogglePin(GPIOA, red_led_Pin);
}

void turnYELLOWLED()
{
//	HAL_GPIO_WritePin(GPIOA, red_led_Pin, 0);
//	HAL_GPIO_WritePin(GPIOA, yellow_led_Pin, 1);
//	HAL_GPIO_WritePin(GPIOA, green_led_Pin, 0);

	HAL_GPIO_TogglePin(GPIOA, yellow_led_Pin);
}

void turnGREENLED()
{
//	HAL_GPIO_WritePin(GPIOA, red_led_Pin, 0);
//	HAL_GPIO_WritePin(GPIOA, yellow_led_Pin, 0);
//	HAL_GPIO_WritePin(GPIOA, green_led_Pin, 1);

	HAL_GPIO_TogglePin(GPIOA, green_led_Pin);
}

void turnRED()
{
	HAL_GPIO_TogglePin(GPIOA, red2_led_Pin);
}

void turnGreen()
{
	HAL_GPIO_TogglePin(GPIOA, green2_led_Pin);
}

#endif /* INC_FUNC_H_ */
