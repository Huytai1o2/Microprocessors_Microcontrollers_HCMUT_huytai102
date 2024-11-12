/*
 * seven_segment.c
 *
 *  Created on: Oct 23, 2024
 *      Author: nguye
 */

#include "seven_segment.h"

int index_digit = 0;

void display_num(int number)
{
    // Reset all segments before displaying the new number
    HAL_GPIO_WritePin(GPIOB, a_Pin, 1);  // Inverted: previously 0, now 1
    HAL_GPIO_WritePin(GPIOB, b_Pin, 1);  // Inverted
    HAL_GPIO_WritePin(GPIOB, c_Pin, 1);  // Inverted
    HAL_GPIO_WritePin(GPIOB, d_Pin, 1);  // Inverted
    HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
    HAL_GPIO_WritePin(GPIOB, f_Pin, 1);  // Inverted
    HAL_GPIO_WritePin(GPIOB, g_Pin, 1);  // Inverted

    switch(number)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);  // Inverted: previously 1, now 0
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 1);  // Inverted
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 1);  // Inverted: previously 0, now 1
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, f_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, g_Pin, 1);  // Inverted
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 1);  // Inverted
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, f_Pin, 1);  // Inverted
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, a_Pin, 1);  // Inverted: previously 0, now 1
            HAL_GPIO_WritePin(GPIOB, d_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 1);  // Inverted
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, f_Pin, 1);  // Inverted
            HAL_GPIO_WritePin(GPIOB, g_Pin, 1);  // Inverted
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
            HAL_GPIO_WritePin(GPIOB, e_Pin, 1);  // Inverted
            break;
        default:
            // Handle invalid input (turn on all segments or display error)
            break;
    }
}

void display_4_digit(int index, int number)
{
    // Turn off all digits before selecting the correct one
    HAL_GPIO_WritePin(GPIOA, dig1_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, dig2_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, dig3_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, dig4_Pin, 0);

    switch(index)
    {
        case 0:
            // Enable the first digit
            HAL_GPIO_WritePin(GPIOA, dig1_Pin, 1);
            HAL_GPIO_WritePin(GPIOA, dig2_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig3_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig4_Pin, 0);
            display_num(number); // Display the number on the first digit
            break;
        case 1:
            // Enable the second digit
            HAL_GPIO_WritePin(GPIOA, dig1_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig2_Pin, 1);
            HAL_GPIO_WritePin(GPIOA, dig3_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig4_Pin, 0);
            display_num(number); // Display the number on the second digit
            break;
        case 2:
            // Enable the third digit
            HAL_GPIO_WritePin(GPIOA, dig1_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig2_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig3_Pin, 1);
            HAL_GPIO_WritePin(GPIOA, dig4_Pin, 0);
            display_num(number); // Display the number on the third digit
            break;
        case 3:
            // Enable the fourth digit
            HAL_GPIO_WritePin(GPIOA, dig1_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig2_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig3_Pin, 0);
            HAL_GPIO_WritePin(GPIOA, dig4_Pin, 1);
            display_num(number); // Display the number on the fourth digit
            break;
        default:
            // Handle invalid index (do nothing or turn off all digits)
            break;
    }
}

void updateDigitBuffer(int duration1, int duration2)
{
    // Giả sử duration1 và duration2 đều là số từ 0 đến 99

    // Tách duration1 thành các chữ số riêng lẻ
    int tens1 = duration1 / 10;   // Chữ số hàng chục của duration1
    int ones1 = duration1 % 10;   // Chữ số hàng đơn vị của duration1

    // Tách duration2 thành các chữ số riêng lẻ
    int tens2 = duration2 / 10;   // Chữ số hàng chục của duration2
    int ones2 = duration2 % 10;   // Chữ số hàng đơn vị của duration2

    // Cập nhật fourDigitBuffer
    fourDigitBuffer[0] = tens1;   // Chữ số đầu tiên là hàng chục của duration1
    fourDigitBuffer[1] = ones1;   // Chữ số thứ hai là hàng đơn vị của duration1
    fourDigitBuffer[2] = tens2;   // Chữ số thứ ba là hàng chục của duration2
    fourDigitBuffer[3] = ones2;   // Chữ số thứ tư là hàng đơn vị của duration2
}

void fsm_change_digit()
{
	display_4_digit(index_digit, fourDigitBuffer[index_digit]);

	if (flag[2] == 1)
	{
		index_digit++;
		if (index_digit == 4)
		{
			index_digit = 0;
		}
		setTimer_change_digit(5);
	}
}

