/*
 * seven_segment.h
 *
 *  Created on: Oct 23, 2024
 *      Author: nguye
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include "main.h"
#include "traffic_light.h"
#include "timer.h"

void updateDigitBuffer(int duration1, int duration2);
void display_num(int numbers);
void display_4_digit(int index, int number);


#endif /* INC_SEVEN_SEGMENT_H_ */
