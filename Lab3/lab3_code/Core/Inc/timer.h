/*
 * timer.h
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int counterLightBuffer[3];
extern int flag[5];
extern int counterTime[5];
//extern int counterRed;
//extern int counterYellow;
//extern int counterGreen;

void setTimer1(int duration);
void setTimer_blinkly(int duration);
void setTimer_increasing_num(int duration);
void setTimer_change_digit(int duration);
void timerRun();

#endif /* INC_TIMER_H_ */
