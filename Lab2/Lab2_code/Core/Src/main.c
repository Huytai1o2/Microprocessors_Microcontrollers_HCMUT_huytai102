/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "functions.h"
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  display7seg(0, 0);
  HAL_TIM_Base_Start_IT(&htim2);

  int index = 0;
  int hour = 12, min = 38, sec = 55;
  int TIMEstate = 0;
  int index_matrix = 0;
  int count_dot = 0;
  setTimer1(250);
  int bufferClock[4] = {0,0,0,0};
  updateClockBuffer(bufferClock, hour, min, sec);
  display7seg(0, bufferClock[0]);
  index++;


  setTimer3(20);

//  setTimer(1000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  setTimer(1000);
  while (1)
  {
///////////////////////////////////////////////////////////////begin of exercise 6////////////////////////////////////////////////////////////////////
//
//	if(timer0_flag == 1){
//		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//		setTimer0(2000);
//	  }
//
///////////////////////////////////////////////////////////////begin of exercise 6////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////begin of exercise 7-8////////////////////////////////////////////////////////////////////
//
//	  if (count_dot == 2)
//	  {
//		  // LED & DOT
//		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//		  count_dot = 0;
//	  }
//
//
//	  if (flags[1] == 1)
//	  {
//		  clearLED();
//		  display7seg(index, bufferClock[index]);
//		  index++;
//		  count_dot++;
//		  setTimer1(250);
//	  }
//
//	  switch(TIMEstate)
//	  {
//		  case 0:
//			  sec++;
//			  setTimer0(1000);
//			  TIMEstate = 1;
//			  break;
//		  case 1:
//			  if (flags[0] == 1)
//			  {
//				  if (sec >= 60)
//				  {
//					  sec = 0;
//					  min++;
//				  }
//				  if (min >= 60)
//				  {
//					  min = 0;
//					  hour++;
//				  }
//				  if (hour >= 24)
//				  {
//					  hour = 0;
//				  }
//				  TIMEstate = 0;
//			  }
//			  break;
//	  }
//
//	  updateClockBuffer(bufferClock, hour, min, sec);
//
//	  if (index >= 4) index = 0;


/////////////////////////////////////////////////////////////end of exercise 7-8////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////begin of exercise 9-10////////////////////////////////////////////////////////////////////

	  if (flags[3] == 1)
	  {
		  updateLEDMatrix(index_matrix);
		  index_matrix ++;
		  setTimer3(20);
	  }
	  if (index_matrix >= 8 )
	  {
//		  shiftLeft(matrix_buffer);
		  index_matrix = 0;
	  }


/////////////////////////////////////////////////////////////begin of exercise 9-10////////////////////////////////////////////////////////////////////
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, em0_Pin|em1_Pin|dot_Pin|led_red_Pin
                          |en0_Pin|en1_Pin|en2_Pin|en3_Pin
                          |em2_Pin|em3_Pin|em4_Pin|em5_Pin
                          |em6_Pin|em7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, seg0_Pin|seg1_Pin|seg2_Pin|row2_Pin
                          |row3_Pin|row4_Pin|row5_Pin|row6_Pin
                          |row7_Pin|seg3_Pin|seg4_Pin|seg5_Pin
                          |seg6_Pin|row0_Pin|row1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : em0_Pin em1_Pin dot_Pin led_red_Pin
                           en0_Pin en1_Pin en2_Pin en3_Pin
                           em2_Pin em3_Pin em4_Pin em5_Pin
                           em6_Pin em7_Pin */
  GPIO_InitStruct.Pin = em0_Pin|em1_Pin|dot_Pin|led_red_Pin
                          |en0_Pin|en1_Pin|en2_Pin|en3_Pin
                          |em2_Pin|em3_Pin|em4_Pin|em5_Pin
                          |em6_Pin|em7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : seg0_Pin seg1_Pin seg2_Pin row2_Pin
                           row3_Pin row4_Pin row5_Pin row6_Pin
                           row7_Pin seg3_Pin seg4_Pin seg5_Pin
                           seg6_Pin row0_Pin row1_Pin */
  GPIO_InitStruct.Pin = seg0_Pin|seg1_Pin|seg2_Pin|row2_Pin
                          |row3_Pin|row4_Pin|row5_Pin|row6_Pin
                          |row7_Pin|seg3_Pin|seg4_Pin|seg5_Pin
                          |seg6_Pin|row0_Pin|row1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

///////////////////////////////////////////// begin of ex1///////////////////////////////////////////////////////////
//int counter = 100, nth = 0;
//int buffer[2] = {1, 2};
//
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim) {
//    counter--;
//    if (counter == 50 || counter == 0) {
//        if (counter == 0) {
//            counter = 100;
//            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Toggle GPIOA PIN 5
//        }
//        // Alternate between 0 and 1 for 'nth'
//        nth = (nth == 0) ? 1 : 0;
//
//        clearLED();  // Clear current display
//
//        // Display the value on the 7-segment display
//        display7seg(nth, buffer[nth]);
//    }
//}
////////////////////////////////////////////// end of ex1////////////////////////////////////////////////////////////

/////////////////////////////////////////////// begin of ex2///////////////////////////////////////////////////////////
//int counter = 100, idx = 0;
//int buffer[4] = {1, 2, 3, 0};
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//	counter--;
//
//	if (counter == 50 || counter == 0) {
//		if (counter == 0) {
//			counter = 100;
//			HAL_GPIO_TogglePin(GPIOA, led_red_Pin | dot_Pin);
//		}
//
//		clearLED();
//		display7seg(idx, buffer[idx]);
//
//		idx = (idx + 1) % 4;
//	}
//}
////////////////////////////////////////////////// end of ex2////////////////////////////////////////////////////////////

///////////////////////////////////////////// begin of ex3///////////////////////////////////////////////////////////
//int counter = 100, idx = 0;
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//	counter--;
//
//	if (counter == 50 || counter == 0) {
//		if (counter == 0) {
//			counter = 100;
//			HAL_GPIO_TogglePin(GPIOA, led_red_Pin | dot_Pin);
//		}
//
////		clearLED();
//		update7SEG(idx);
//
//		idx = (idx + 1) % 4;
//	}
//}
//////////////////////////////////////////////// end of ex3////////////////////////////////////////////////////////////

/////////////////////////////////////////////// begin of ex4///////////////////////////////////////////////////////////
//
///*
// * inorder to display 1hz for all 4 leds, which means each leds should bright within 250ms
// */
//int counter = 50, idx = 0;
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//	counter--;
//
//	if (counter == 25 || counter == 0) {
//		if (counter == 0) {
//			counter = 50;
//			HAL_GPIO_TogglePin(GPIOA, led_red_Pin | dot_Pin);
//		}
//
////		clearLED();
//
//		idx++;
//
//		if (idx >=4)
//		{
//			idx = 0;
//			update7SEG(idx);
//		}
//
//		else update7SEG(idx);
//	}
//}
////////////////////////////////////////////////// end of ex4////////////////////////////////////////////////////////////

///////////////////////////////////////////////// begin of ex5///////////////////////////////////////////////////////////
//
///*
// * inorder to display 1hz for all 4 leds, which means each leds should bright within 250ms
// */
//int counter = 50, idx = 0;
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//	counter--;
//	if (idx >=4)
//	{
//		idx = 0;
//		display7seg(0, clock_buffer[0]);
//	}
//
//	if (counter == 25 || counter == 0) {
//		if (counter == 0) {
//			counter = 50;
//			HAL_GPIO_TogglePin(GPIOA, led_red_Pin | dot_Pin);
//		}
//
////		clearLED();
//
//		idx++;
//		display7seg(idx, clock_buffer[idx]);
//	}
//}
//////////////////////////////////////////////////// end of ex5////////////////////////////////////////////////////////////

/////////////////////////////////////////////// begin of ex6-10///////////////////////////////////////////////////////////

/*
 * inorder to display 1hz for all 4 leds, which means each leds should bright within 250ms
 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timerRun();
}

////////////////////////////////////////////////// end of ex6-10////////////////////////////////////////////////////////////


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
