/*
 * exercise1.h
 *
 *  Created on: Sep 9, 2024
 *      Author: nguye
 */

#ifndef INC_LAB1_H_
#define INC_LAB1_H_

#include "main.h"

void exercise1()
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_Delay(2000);
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

void exercise2()
{
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	HAL_Delay(5000);
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_Delay(3000);
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	HAL_Delay(2000);
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}

void exercise3()
{
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
	HAL_GPIO_TogglePin(led7_GPIO_Port, led7_Pin);
	HAL_GPIO_TogglePin(led6_GPIO_Port, led6_Pin);
	HAL_GPIO_TogglePin(led12_GPIO_Port, led12_Pin);
	HAL_Delay(3000);

	HAL_GPIO_TogglePin(led6_GPIO_Port, led6_Pin);
	HAL_GPIO_TogglePin(led12_GPIO_Port, led12_Pin);
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
	HAL_GPIO_TogglePin(led11_GPIO_Port, led11_Pin);
	HAL_Delay(2000);

	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
	HAL_GPIO_TogglePin(led7_GPIO_Port, led7_Pin);
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
	HAL_GPIO_TogglePin(led11_GPIO_Port, led11_Pin);
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
	HAL_GPIO_TogglePin(led10_GPIO_Port, led10_Pin);
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
	HAL_GPIO_TogglePin(led9_GPIO_Port, led9_Pin);
	HAL_Delay(3000);

	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
	HAL_GPIO_TogglePin(led9_GPIO_Port, led9_Pin);
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
	HAL_GPIO_TogglePin(led8_GPIO_Port, led8_Pin);
	HAL_Delay(2000);

	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
	HAL_GPIO_TogglePin(led8_GPIO_Port, led8_Pin);
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
	HAL_GPIO_TogglePin(led10_GPIO_Port, led10_Pin);
}



void exercise4()
{
	int counter = 0;
	while (1)
	{
		display7SEG(counter,0);
		HAL_Delay(1000);

		counter ++;
		if (counter >= 10) counter = 0;
	}
}

void display7SEG(int num, int num2)
{
	uint8_t segMap[] =
	{
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111  // 9
	};

	GPIO_TypeDef *port = seg1_GPIO_Port;

	uint16_t gpio_pin[] =
	{
		seg1_Pin,
		seg2_Pin,
		seg3_Pin,
		seg4_Pin,
		seg5_Pin,
		seg6_Pin,
		seg7_Pin,
	};

	uint16_t gpio_pin2[] =
	{
		LED_RED_Pin,
		LED_YELLOW_Pin,
		LED_GREEN_Pin,
		s4_Pin,
		s5_Pin,
		s6_Pin,
		LED_1_Pin
	};

	if (num > 9 || num < 0)
	{
		return;
	}

	else
	{
		uint8_t segment = segMap[num];
		uint8_t segment2 = segMap[num2];
		for(int i = 0; i < 7; i++)
		{
			HAL_GPIO_WritePin(port, gpio_pin[i], (segment & (1 << i))? RESET : SET);
			HAL_GPIO_WritePin(port, gpio_pin2[i], (segment2 & (1 << i))? RESET : SET);
		}
	}
	HAL_Delay(1000);
}

void exercise5()
{
	int counter1, counter2 = 0;
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
	HAL_GPIO_TogglePin(led7_GPIO_Port, led7_Pin);
	HAL_GPIO_TogglePin(led6_GPIO_Port, led6_Pin);
	HAL_GPIO_TogglePin(led12_GPIO_Port, led12_Pin);
	counter1 = 3; counter2 = 5;
	for (int i = 3; i > 0; i--)
	{
		display7SEG(counter1,counter2);
		counter1 --;
		counter2 --;
	}

	HAL_GPIO_TogglePin(led6_GPIO_Port, led6_Pin);
	HAL_GPIO_TogglePin(led12_GPIO_Port, led12_Pin);
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
	HAL_GPIO_TogglePin(led11_GPIO_Port, led11_Pin);
	counter1 = 2; counter2 = 2;
	for (int i = 2; i > 0; i--)
	{
		display7SEG(counter1,counter2);
		counter1 --;
		counter2 --;
	}

	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
	HAL_GPIO_TogglePin(led7_GPIO_Port, led7_Pin);
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
	HAL_GPIO_TogglePin(led11_GPIO_Port, led11_Pin);
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
	HAL_GPIO_TogglePin(led10_GPIO_Port, led10_Pin);
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
	HAL_GPIO_TogglePin(led9_GPIO_Port, led9_Pin);
	counter1 = 5; counter2 = 3;
	for (int i = 3; i > 0; i--)
	{
		display7SEG(counter1,counter2);
		counter1 --;
		counter2 --;
	}

	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
	HAL_GPIO_TogglePin(led9_GPIO_Port, led9_Pin);
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
	HAL_GPIO_TogglePin(led8_GPIO_Port, led8_Pin);
	counter1 = 2; counter2 = 2;
	for (int i = 2; i > 0; i--)
	{
		display7SEG(counter1,counter2);
		counter1 --;
		counter2 --;
	}

	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
	HAL_GPIO_TogglePin(led8_GPIO_Port, led8_Pin);
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
	HAL_GPIO_TogglePin(led10_GPIO_Port, led10_Pin);
}

void setNumberOnClock(int num)
{
	if (num < 0) return;

	GPIO_TypeDef *port = LED_1_GPIO_Port;

	switch (num)
	{
		case 0:
			HAL_GPIO_WritePin(port, LED_1_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(port, LED_RED_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(port, LED_YELLOW_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(port, LED_GREEN_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(port, seg1_Pin, SET);
			break;
		case 5:
			HAL_GPIO_WritePin(port, seg2_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(port, seg3_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(port, seg4_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(port, seg5_Pin, SET);
			break;
		case 9:
			HAL_GPIO_WritePin(port, seg6_Pin, SET);
			break;
		case 10:
			HAL_GPIO_WritePin(port, seg7_Pin, SET);
			break;
		case 11:
			HAL_GPIO_WritePin(port, LED_12_Pin, SET);
			break;
		default: break;
	}
}

void exercise6()
{
	for (int i = 0; i < 12; i++)
	{
		setNumberOnClock(i);
		HAL_Delay(1000);
	}
}

void clearAllClock()
{
	GPIO_TypeDef *port = LED_1_GPIO_Port;
	uint16_t pins[] =
	{
		LED_1_Pin,
		LED_RED_Pin,
		LED_YELLOW_Pin,
		LED_GREEN_Pin,
		seg1_Pin,
		seg2_Pin,
		seg3_Pin,
		seg4_Pin,
		seg5_Pin,
		seg6_Pin,
		seg7_Pin,
		LED_12_Pin
	};

	for (int i = 0; i < 12; i++)
	{
		HAL_GPIO_WritePin(port, pins[i], RESET);
	}
}

void clearNumberOnClock(int num)
{
	if (num < 0) return;

	GPIO_TypeDef *port = LED_1_GPIO_Port;

	switch (num)
	{
		case 0:
			HAL_GPIO_WritePin(port, LED_1_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(port, LED_RED_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(port, LED_YELLOW_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(port, LED_GREEN_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(port, seg1_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(port, seg2_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(port, seg3_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(port, seg4_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(port, seg5_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(port, seg6_Pin, RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(port, seg7_Pin, RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(port, LED_12_Pin, RESET);
			break;
		default: break;
	}
}

void exercise7()
{
	clearAllClock();
}

void exercise8()
{
	for (int i = 0; i < 12; i++)
	{
		setNumberOnClock(i);
		HAL_Delay(1000);
	}

	clearAllClock();
}

void exercise9()
{
	for (int i = 0; i < 12; i++)
	{
		setNumberOnClock(i);
		HAL_Delay(1000);
	}

	for (int i = 0; i < 12; i++)
	{
		clearNumberOnClock(i);
		HAL_Delay(1000);
	}
}

void exercise10()
{
	int second = 0;
	int hour = 0, minute = 0;
	int counter_min = 0;

	while (1)
	{
		switch (second)
		{
		case 0:
			setNumberOnClock(second);
			if (minute != 11)
			clearNumberOnClock(11);
			second++;
			break;

		default:
			setNumberOnClock(second);

			if (second - 1 != minute && second - 1 != hour)
			{
				clearNumberOnClock(second - 1);
			}
			second++;

			if (second == 12)
			{
				counter_min++;
				if (counter_min == 5)
				{
					minute ++;
					counter_min = 0;
				}
				second = 0;
			}
			break;
		}

		HAL_Delay(50);

		switch (minute)
		{
		case 0:
			setNumberOnClock(minute);
			if (hour != 11)
			clearNumberOnClock(11);
			break;

		default:

			setNumberOnClock(minute);

			if (minute - 1 != hour && minute - 1 != second)
			{
				clearNumberOnClock(minute - 1);
			}

			if (minute == 12)
			{
				++hour;
				second = 0;
				minute = 0;
			}
			break;
		}

		switch (hour)
		{
		case 0:
			setNumberOnClock(hour);
			break;

		default:
			if (minute == 0)
			{
//				HAL_Delay(50000);
			}

			setNumberOnClock(hour);

			if (hour - 1 != minute && hour - 1 != second)
			{
				clearNumberOnClock(hour - 1);
			}

			if (hour == 12)
			{
				clearAllClock();
				hour = 0;
				second = 0;
				minute = 0;
			}
			break;
		}
	}
}

#endif /* INC_LAB1_H_ */
