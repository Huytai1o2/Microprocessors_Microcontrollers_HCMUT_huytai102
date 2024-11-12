/*
 * traffic_light.c
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#include "timer.h"
#include "traffic_light.h"

fourDigitBuffer[4] = {0};
int state = 0;
int countTemp = 0;
int index = 1;

void reset_state()
{
	state = 0;
	countTemp = 0;
	index = 1;
	setTimer1(100);
}

void fsm_traffic_light()
{
	switch (state)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 1);
			if (countTemp == counterLightBuffer[2])
			{
				state = 1;
				countTemp = 0;
			}
			updateDigitBuffer(counterLightBuffer[0] - countTemp, counterLightBuffer[2] - countTemp);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);
			if (countTemp == counterLightBuffer[1])
			{
				state = 2;
				countTemp = 0;
			}
			updateDigitBuffer(counterLightBuffer[1] - countTemp, counterLightBuffer[1] - countTemp);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);
			if (countTemp == counterLightBuffer[2])
			{
				state = 3;
				countTemp = 0;
			}
			updateDigitBuffer(counterLightBuffer[2] - countTemp, counterLightBuffer[0] - countTemp);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);
			if (countTemp == counterLightBuffer[1])
			{
				state = 0;
				countTemp = 0;
			}
			updateDigitBuffer(counterLightBuffer[1] - countTemp, counterLightBuffer[1] - countTemp);
			break;

		default:
			state = 0;
			break;
	}

	if (flag[0] == 1)
	{
		countTemp ++;
		setTimer1(100);
	}

	return;
}