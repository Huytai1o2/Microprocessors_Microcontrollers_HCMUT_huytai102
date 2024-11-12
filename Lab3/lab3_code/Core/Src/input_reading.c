/*
 * input_reading.c
 *
 *  Created on: Oct 22, 2024
 *      Author: nguye
 */

#include "main.h"
#include "input_reading.h"
#include "traffic_light.h"
#include "seven_segment.h"

int setCounter[3] = {0};

// We aim to work with more than one button
#define NO_OF_BUTTONS 3

// Timer interrupt duration is 10ms, so to pass 1 second, we need to jump to the interrupt service routine 100 times
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

// The buffer that the final result is stored at debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

// We define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

// We define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];

// We define a counter for automatically increasing the value after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

static uint16_t pinsButtons[NO_OF_BUTTONS] =
{
		button1_Pin,
		button2_Pin,
		button3_Pin
};

void button_reading(void) {
    for (char i = 0; i < NO_OF_BUTTONS; ++i) {
        debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
        debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, pinsButtons[i]);

        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
            buttonBuffer[i] = debounceButtonBuffer1[i];

            if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
                // If a button is pressed, we start counting
                if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                    counterForButtonPress1s[i]++;
                } else {
                    // The flag is turned on when 1 second has passed since the button is pressed.
                    flagForButtonPress1s[i] = 1;
                    // todo
                }
            } else {
                counterForButtonPress1s[i] = 0;
                flagForButtonPress1s[i] = 0;
            }
        }
    }
}

unsigned char is_button_pressed(uint8_t index) {
    if (index >= NO_OF_BUTTONS) return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
    if (index >= NO_OF_BUTTONS) return 0xff;
    return (flagForButtonPress1s[index] == 1);
}

enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonStates[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};


enum Mode {MODE1, MODE2, MODE3, MODE4};
enum Mode mode = MODE1;


int previous_mode = 1;

void detect_signal_button(enum ButtonState *buttonState, int button_pin)
{
    switch (*buttonState) {
        case BUTTON_RELEASED:
            if (is_button_pressed(button_pin)) {
                *buttonState = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
            }
            break;

        case BUTTON_PRESSED:
            if (!is_button_pressed(button_pin)) {
                *buttonState = BUTTON_RELEASED;
            } else if (is_button_pressed_1s(button_pin)) {
                *buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            }
            break;

        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(button_pin)) {
                *buttonState = BUTTON_RELEASED;
            }
            // TODO: Add functionality here for long press
            break;

        default:
            *buttonState = BUTTON_RELEASED;
    }
}

void fsm_for_input_processing(void) {

	for (int i = 0; i < NO_OF_BUTTONS; i++)
	{
		detect_signal_button(&buttonStates[i], i);  // Pass button state and pin number
	}

    // Handle mode switching
    switch(mode) {
        case MODE1:
            if (counterLightBuffer[0] != counterLightBuffer[1]+counterLightBuffer[2])
            {
            	HAL_GPIO_WritePin(GPIOA, Debug_Pin, 1); // indicate the red led is modified
            	counterLightBuffer[0] = counterLightBuffer[1]+counterLightBuffer[2]; // if green + yellow != red
            																		// make equal
            }

            fsm_traffic_light();

            if (flag[1] == 1)
            {
    			setTimer_blinkly(50);
            }
            previous_mode = 1;
            setTimer_blinkly(50);
            setCounter[0] = counterLightBuffer[0];
            setCounter[1] = counterLightBuffer[1];
            setCounter[2] = counterLightBuffer[2];
            break;

        case MODE2:
        	if (previous_mode == 1)
        	{
        		HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
        	}
        	if (flag[1] == 1)
        	{
    			HAL_GPIO_TogglePin(GPIOB, red1_Pin);
    			HAL_GPIO_TogglePin(GPIOB, red2_Pin);
    			setTimer_blinkly(50);
        	}
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);

			HAL_GPIO_WritePin(GPIOA, Debug_Pin, 0);
			updateDigitBuffer(setCounter[0], 02);

			previous_mode = 2;
            break;

        case MODE3:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
			if (flag[1] == 1)
			{
				HAL_GPIO_TogglePin(GPIOB, yellow1_Pin);
				HAL_GPIO_TogglePin(GPIOB, yellow2_Pin);
    			setTimer_blinkly(50);
			}
			HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);
			updateDigitBuffer(setCounter[1], 03);
			previous_mode = 3;
            break;

        case MODE4:
			HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);
			if (flag[1] == 1)
			{
				HAL_GPIO_TogglePin(GPIOB, green1_Pin);
				HAL_GPIO_TogglePin(GPIOB, green2_Pin);
    			setTimer_blinkly(50);
			}
        	reset_state();

			updateDigitBuffer(setCounter[2], 04);
        	previous_mode = 4;
            break;
    }

    /***********************************Beginning handle button 1*********************************/

    if (buttonStates[0] == BUTTON_PRESSED || buttonStates[0] == BUTTON_PRESSED_MORE_THAN_1_SECOND)
    {

    	if (buttonStates[0] == BUTTON_PRESSED_MORE_THAN_1_SECOND)
    	{
    		if (flag[4] == 1)
			{
				mode ++;
				if (mode == 4) mode = 0;
				setTimer_increasing_num(10);
			}
    	}

    	else
    	{
//			HAL_GPIO_WritePin(GPIOA, Debug_Pin, 1);
    		if (flag[4] == 1)
			{
				mode ++;
				if (mode == 4)
				{
					mode = 0;
//					counterLightBuffer[0] = counter
				};
				setTimer_increasing_num(10);
			}
    	}
    }

    /***********************************Ending handle button 1*********************************/

    /***********************************Beginning handle button 2*********************************/

    if (buttonStates[1] == BUTTON_PRESSED || buttonStates[1] == BUTTON_PRESSED_MORE_THAN_1_SECOND)
	{
		// debug on if button1 pressed

		if (buttonStates[1] == BUTTON_PRESSED_MORE_THAN_1_SECOND)
		{
			if (flag[4] == 1)
			{
				if (mode == 1) setCounter[0] ++;
				else if (mode == 2) setCounter[1] ++;
				else if (mode == 3) setCounter[2] ++;

				//////////////////////////////////////////
				if (setCounter[0] == 100) setCounter[0] = 0;
				else if (setCounter[1] == 100) setCounter[1] = 0;
				else if (setCounter[2] == 100) setCounter[2] = 0;

				setTimer_increasing_num(10);
			}
		}

		else
		{
			if (flag[4] == 1)
			{
				if (mode == 1) setCounter[0] ++;
				else if (mode == 2) setCounter[1] ++;
				else if (mode == 3) setCounter[2] ++;

				//////////////////////////////////////////
				if (setCounter[0] == 100) setCounter[0] = 0;
				else if (setCounter[1] == 100) setCounter[1] = 0;
				else if (setCounter[2] == 100) setCounter[2] = 0;

				setTimer_increasing_num(10);
			}
		}
	}

    else
    {
//        HAL_GPIO_WritePin(GPIOA, Debug_Pin, 0);
    }

    /***********************************Ending handle button 2*********************************/

    /***********************************Beginning handle button 3*********************************/

	if (buttonStates[2] == BUTTON_PRESSED || buttonStates[2] == BUTTON_PRESSED_MORE_THAN_1_SECOND)
	{
		if (flag[4] == 1)
		{
			if (mode == 1) counterLightBuffer[0] = setCounter[0];
			else if (mode == 2) counterLightBuffer[1] = setCounter[1];
			else if (mode == 3) counterLightBuffer[2] = setCounter[2];

			setTimer_increasing_num(5);
		}
	}

	else
	{
//		HAL_GPIO_WritePin(GPIOA, Debug_Pin, 0);
	}

	/***********************************Ending handle button 3*********************************/

    fsm_change_digit();
}




