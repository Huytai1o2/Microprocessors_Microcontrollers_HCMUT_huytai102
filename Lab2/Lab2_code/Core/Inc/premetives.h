/*
 * premetives.h
 *
 *  Created on: Oct 1, 2024
 *      Author: nguye
 */

#ifndef INC_PREMETIVES_H_
#define INC_PREMETIVES_H_

const int MAX_LED_MATRIX = 8;

uint8_t matrix_buffer[8] = {
    0x3C,  // 00111100 -> Hàng 1
    0x66,  // 01100110 -> Hàng 2
    0xC3,  // 11000011 -> Hàng 3
    0xC3,  // 11000011 -> Hàng 4
    0xFF,  // 11111111 -> Hàng 5
    0xC3,  // 11000011 -> Hàng 6
    0xC3,  // 11000011 -> Hàng 7
    0xC3   // 11000011 -> Hàng 8
};


#endif /* INC_PREMETIVES_H_ */
