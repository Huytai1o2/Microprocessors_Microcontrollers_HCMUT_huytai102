/*
 * traffic_light.h
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "timer.h"
#include "variables.h"
#include "seven_segment.h"

extern int fourDigitBuffer[4];

void reset_state();
void fsm_traffic_light();


#endif /* INC_TRAFFIC_LIGHT_H_ */
