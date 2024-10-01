/*
 * functions.h
 *
 *  Created on: Sep 30, 2024
 *      Author: nguye
 */

#ifndef INC_FUNCTIONS_H_
#define INC_FUNCTIONS_H_

#include "main.h"
#include "premetives.h"

int clock_buffer[] = {0,0,0,0};

const uint8_t segmentMap[10] = {
	0b11000000, // 0 (ngược lại của 0b00111111)
	0b11111001, // 1 (ngược lại của 0b00000110)
	0b10100100, // 2 (ngược lại của 0b01011011)
	0b10110000, // 3 (ngược lại của 0b01001111)
	0b10011001, // 4 (ngược lại của 0b01100110)
	0b10010010, // 5 (ngược lại của 0b01101101)
	0b10000010, // 6 (ngược lại của 0b01111101)
	0b11111000, // 7 (ngược lại của 0b00000111)
	0b10000000, // 8 (ngược lại của 0b01111111)
	0b10010000  // 9 (ngược lại của 0b01101111)
};

void display7seg(int nth, int value) {

	if (nth == 1)
	{
	    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
	}
	else if (nth == 0)
	{
	    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
	}
	else if (nth == 2)
	{
	    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
	}
	else if (nth == 3)
	{
	    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_RESET);
	}


    uint8_t segments = segmentMap[value];  // Get segment pattern for the value

    // Assuming 7-segment pins are connected to GPIOB Pins 0-6
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void clearLED() {
    // Turn off all segments (assuming GPIOB pins 0-6 control the segments)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 |
                      GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_PIN_RESET);
}

void clearEnableVsLED()
{
	HAL_GPIO_WritePin(GPIOA, en0_Pin | en1_Pin | en2_Pin | en3_Pin, GPIO_PIN_SET);
	clearLED();
}

void update7SEG(int index)
{
	int led_buffer [4] = {1 , 2 , 3 , 4};
	clearEnableVsLED();
	display7seg(index, led_buffer[index]);
}



void updateClockBuffer(int *clock_buffer, int hour, int min, int second) {
	clock_buffer[0] = hour / 10;
	clock_buffer[1] = hour % 10;
	clock_buffer[2] = min / 10;
	clock_buffer[3] = min % 10;
}

void clockDigit()
{
	int hour = 15, minute = 8, second = 50;

	while (1) {
	    second++;

	    if (second >= 60) {
	        second = 0;
	        minute++;
	    }

	    if (minute >= 60) {
	        minute = 0;
	        hour++;
	    }

	    if (hour >= 24) {
	        hour = 0;
	    }

	    updateClockBuffer(clock_buffer, hour, minute, second);
	    HAL_Delay(1000);
	}
}

void dis7seg(int value)
{
	uint8_t segments = segmentMap[value];  // Get segment pattern for the value

	// Assuming 7-segment pins are connected to GPIOB Pins 0-6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}


void setRow(int row)
{
    HAL_GPIO_WritePin(GPIOB, row0_Pin, (row == 0)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row1_Pin, (row == 1)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row2_Pin, (row == 2)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row3_Pin, (row == 3)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row4_Pin, (row == 4)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row5_Pin, (row == 5)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row6_Pin, (row == 6)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, row7_Pin, (row == 7)? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setColumn(int value)
{
    HAL_GPIO_WritePin(GPIOA, em0_Pin, (value & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em1_Pin, (value & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em2_Pin, (value & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em3_Pin, (value & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em4_Pin, (value & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em5_Pin, (value & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em6_Pin, (value & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, em7_Pin, (value & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void shiftLeft(uint8_t matrix_buffer[8])
{
	for (int i = 0; i < 8; i++) {
		// Lấy bit ngoài cùng bên trái (bit thứ 7)
		uint8_t leftBit = (matrix_buffer[i] & 0x80) >> 7;

		// Dịch trái toàn bộ hàng và nối bit ngoài cùng bên trái vào bên phải
		matrix_buffer[i] = (matrix_buffer[i] << 1) | leftBit;
	}
}

void updateLEDMatrix(int index)
{
		setRow(index);
		setColumn(matrix_buffer[index]);
}

#endif /* INC_FUNCTIONS_H_ */
