/*
 * traffic_light.c
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#include "timer.h"
#include "traffic_light.h"
#include "i2c-lcd.h"
#include "input_reading.h"


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
//			HAL_GPIO_WritePin(GPIOB, red1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green2_Pin, 1);

			HAL_GPIO_WritePin(Bit11_GPIO_Port, Bit11_Pin, 1);
			HAL_GPIO_WritePin(Bit12_GPIO_Port, Bit12_Pin, 1);
			HAL_GPIO_WritePin(Bit21_GPIO_Port, Bit21_Pin, 1);
			HAL_GPIO_WritePin(Bit22_GPIO_Port, Bit22_Pin, 0);
			updateDigitBuffer(counterLightBuffer[0] - countTemp, counterLightBuffer[2] - countTemp, 0, 0);
			if (countTemp == counterLightBuffer[2])
			{
				state = 1;
				countTemp = 0;
			}
			break;

		case 1:
//			HAL_GPIO_WritePin(GPIOB, red1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);

			HAL_GPIO_WritePin(Bit11_GPIO_Port, Bit11_Pin, 1);
			HAL_GPIO_WritePin(Bit12_GPIO_Port, Bit12_Pin, 1);
			HAL_GPIO_WritePin(Bit21_GPIO_Port, Bit21_Pin, 0);
			HAL_GPIO_WritePin(Bit22_GPIO_Port, Bit22_Pin, 1);
			updateDigitBuffer(counterLightBuffer[1] - countTemp, counterLightBuffer[1] - countTemp, 0, 0);

			if (countTemp == counterLightBuffer[1])
			{
				state = 2;
				countTemp = 0;
			}
			break;

		case 2:
//			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, red2_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);

			HAL_GPIO_WritePin(Bit11_GPIO_Port, Bit11_Pin, 1);
			HAL_GPIO_WritePin(Bit12_GPIO_Port, Bit12_Pin, 0);
			HAL_GPIO_WritePin(Bit21_GPIO_Port, Bit21_Pin, 1);
			HAL_GPIO_WritePin(Bit22_GPIO_Port, Bit22_Pin, 1);

			updateDigitBuffer(counterLightBuffer[2] - countTemp, counterLightBuffer[0] - countTemp, 0, 0);

			if (countTemp == counterLightBuffer[2])
			{
				state = 3;
				countTemp = 0;
			}
			break;

		case 3:
//			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, red2_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
//			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);

			HAL_GPIO_WritePin(Bit11_GPIO_Port, Bit11_Pin, 0);
			HAL_GPIO_WritePin(Bit12_GPIO_Port, Bit12_Pin, 1);
			HAL_GPIO_WritePin(Bit21_GPIO_Port, Bit21_Pin, 1);
			HAL_GPIO_WritePin(Bit22_GPIO_Port, Bit22_Pin, 1);

			updateDigitBuffer(counterLightBuffer[1] - countTemp, counterLightBuffer[1] - countTemp, 0, 0);

			if (countTemp == counterLightBuffer[1])
			{
				state = 0;
				countTemp = 0;
			}
			break;

		default:
			state = 0;
			break;
	}

	if (flag[0] == 1)
	{
		countTemp ++;
		setTimer1(100);
		lcd_clear_display();
	}

	return;
}
