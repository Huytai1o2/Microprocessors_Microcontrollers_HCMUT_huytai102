/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2024
 *      Author: nguye
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int counterArr[4];
extern int cycles;

extern int timer0_counter;
extern int timer0_flag;

void setTimer(int duration);
void timer_run();

extern int flags[4];

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer3(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
