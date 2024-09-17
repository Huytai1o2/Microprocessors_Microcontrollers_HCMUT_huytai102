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
#define s4_Pin GPIO_PIN_1
#define s4_GPIO_Port GPIOA
#define s5_Pin GPIO_PIN_2
#define s5_GPIO_Port GPIOA
#define s6_Pin GPIO_PIN_3
#define s6_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_4
#define LED_1_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define LED_YELLOW_Pin GPIO_PIN_6
#define LED_YELLOW_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOA
#define led1_Pin GPIO_PIN_0
#define led1_GPIO_Port GPIOB
#define led2_Pin GPIO_PIN_1
#define led2_GPIO_Port GPIOB
#define led3_Pin GPIO_PIN_2
#define led3_GPIO_Port GPIOB
#define led11_Pin GPIO_PIN_10
#define led11_GPIO_Port GPIOB
#define led12_Pin GPIO_PIN_11
#define led12_GPIO_Port GPIOB
#define seg1_Pin GPIO_PIN_8
#define seg1_GPIO_Port GPIOA
#define seg2_Pin GPIO_PIN_9
#define seg2_GPIO_Port GPIOA
#define seg3_Pin GPIO_PIN_10
#define seg3_GPIO_Port GPIOA
#define seg4_Pin GPIO_PIN_11
#define seg4_GPIO_Port GPIOA
#define seg5_Pin GPIO_PIN_12
#define seg5_GPIO_Port GPIOA
#define seg6_Pin GPIO_PIN_13
#define seg6_GPIO_Port GPIOA
#define seg7_Pin GPIO_PIN_14
#define seg7_GPIO_Port GPIOA
#define LED_12_Pin GPIO_PIN_15
#define LED_12_GPIO_Port GPIOA
#define led4_Pin GPIO_PIN_3
#define led4_GPIO_Port GPIOB
#define led5_Pin GPIO_PIN_4
#define led5_GPIO_Port GPIOB
#define led6_Pin GPIO_PIN_5
#define led6_GPIO_Port GPIOB
#define led7_Pin GPIO_PIN_6
#define led7_GPIO_Port GPIOB
#define led8_Pin GPIO_PIN_7
#define led8_GPIO_Port GPIOB
#define led9_Pin GPIO_PIN_8
#define led9_GPIO_Port GPIOB
#define led10_Pin GPIO_PIN_9
#define led10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
