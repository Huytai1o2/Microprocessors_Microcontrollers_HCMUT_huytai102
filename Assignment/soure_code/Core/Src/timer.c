/*
 * timer.c
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#include "timer.h"
#include "stm32f1xx.h"

counterLightBuffer[3] = {10, 3, 7};
//counterRed = 5;
//counterYellow = 2;
//counterGreen = 3;
flag[5] = {0};
counterTime[5] = {0 ,0 ,0};

void setTimer1(int duration)
{
	counterTime[0] = duration;
	flag[0] = 0;
}

void setTimer_increasing_num(int duration)
{
	counterTime[4] = duration;
	flag[4] = 0;
}

void setTimer_blinkly(int duration)
{
	counterTime[1] = duration;
	flag[1] = 0;
}

void setTimer_change_digit(int duration)
{
	counterTime[2] = duration;
	flag[2] = 0;
}

void timerRun()
{
	counterTime[0] --;
	counterTime[1] --;
	counterTime[2] --;
	counterTime[4] --;
	if (counterTime[0] == 0)
	{
		flag[0] = 1;
	}

	if (counterTime[1] == 0)
	{
		flag[1] = 1;
	}

	if (counterTime[2] == 0)
	{
		flag[2] = 1;
	}

	if (counterTime[4] == 0)
	{
		flag[4] = 1;
	}
}
