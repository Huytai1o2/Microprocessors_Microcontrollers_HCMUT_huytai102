/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define em0_Pin GPIO_PIN_2
#define em0_GPIO_Port GPIOA
#define em1_Pin GPIO_PIN_3
#define em1_GPIO_Port GPIOA
#define dot_Pin GPIO_PIN_4
#define dot_GPIO_Port GPIOA
#define led_red_Pin GPIO_PIN_5
#define led_red_GPIO_Port GPIOA
#define en0_Pin GPIO_PIN_6
#define en0_GPIO_Port GPIOA
#define en1_Pin GPIO_PIN_7
#define en1_GPIO_Port GPIOA
#define seg0_Pin GPIO_PIN_0
#define seg0_GPIO_Port GPIOB
#define seg1_Pin GPIO_PIN_1
#define seg1_GPIO_Port GPIOB
#define seg2_Pin GPIO_PIN_2
#define seg2_GPIO_Port GPIOB
#define row2_Pin GPIO_PIN_10
#define row2_GPIO_Port GPIOB
#define row3_Pin GPIO_PIN_11
#define row3_GPIO_Port GPIOB
#define row4_Pin GPIO_PIN_12
#define row4_GPIO_Port GPIOB
#define row5_Pin GPIO_PIN_13
#define row5_GPIO_Port GPIOB
#define row6_Pin GPIO_PIN_14
#define row6_GPIO_Port GPIOB
#define row7_Pin GPIO_PIN_15
#define row7_GPIO_Port GPIOB
#define en2_Pin GPIO_PIN_8
#define en2_GPIO_Port GPIOA
#define en3_Pin GPIO_PIN_9
#define en3_GPIO_Port GPIOA
#define em2_Pin GPIO_PIN_10
#define em2_GPIO_Port GPIOA
#define em3_Pin GPIO_PIN_11
#define em3_GPIO_Port GPIOA
#define em4_Pin GPIO_PIN_12
#define em4_GPIO_Port GPIOA
#define em5_Pin GPIO_PIN_13
#define em5_GPIO_Port GPIOA
#define em6_Pin GPIO_PIN_14
#define em6_GPIO_Port GPIOA
#define em7_Pin GPIO_PIN_15
#define em7_GPIO_Port GPIOA
#define seg3_Pin GPIO_PIN_3
#define seg3_GPIO_Port GPIOB
#define seg4_Pin GPIO_PIN_4
#define seg4_GPIO_Port GPIOB
#define seg5_Pin GPIO_PIN_5
#define seg5_GPIO_Port GPIOB
#define seg6_Pin GPIO_PIN_6
#define seg6_GPIO_Port GPIOB
#define row0_Pin GPIO_PIN_8
#define row0_GPIO_Port GPIOB
#define row1_Pin GPIO_PIN_9
#define row1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
