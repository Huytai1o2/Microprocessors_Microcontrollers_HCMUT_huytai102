/*
 * software.timer.c
 *
 *  Created on: Sep 30, 2024
 *      Author: nguye
 */
#include "software_timer.h"

int counterArr[] = {0,0,0,0};
int cycles = 10;
int flags[] = {0,0,0,0};

int timer0_counter = 0;
int timer0_flag = 0;

void setTimer(int duration){
	timer0_counter = duration /cycles;
	timer0_flag = 0;
}

void setTimer0(int duration)
{
	counterArr[0] = duration / cycles;
	flags[0] = 0;
}

void setTimer1(int duration)
{
	counterArr[1] = duration / cycles;
	flags[1] = 0;
}

void setTimer3(int duration)
{
	counterArr[3] = duration / cycles;
	flags[3] = 0;
}

void timerRun(){
	timer0_counter --;
    counterArr[0]--;
    counterArr[1]--;
    counterArr[3]--;

    if (timer0_counter == 0)
    {
    	timer0_flag = 1;
    }

    if (counterArr[0] == 0)
    {
        flags[0] = 1;
    }

    if (counterArr[1] == 0)
    {
        flags[1] = 1;
    }
    if (counterArr[3] == 0)
    {
    	flags[3] = 1;
    }
}
