/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define PAD_J9010_Pin GPIO_PIN_0
#define PAD_J9010_GPIO_Port GPIOD
#define MBR3108_INT_Pin GPIO_PIN_4
#define MBR3108_INT_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOD
#define REGULATOR_BLUETOOTH_Pin GPIO_PIN_5
#define REGULATOR_BLUETOOTH_GPIO_Port GPIOD
#define REGULATOR_WLAN_Pin GPIO_PIN_6
#define REGULATOR_WLAN_GPIO_Port GPIOD
#define CHIP_SELECT_WLAN_Pin GPIO_PIN_5
#define CHIP_SELECT_WLAN_GPIO_Port GPIOE
#define REGULATOR_GPS_Pin GPIO_PIN_9
#define REGULATOR_GPS_GPIO_Port GPIOB
#define CTRL_VBAT_Pin GPIO_PIN_4
#define CTRL_VBAT_GPIO_Port GPIOE
#define REGULATOR_DISPLAY_Pin GPIO_PIN_8
#define REGULATOR_DISPLAY_GPIO_Port GPIOB
#define WIFI_EN_Pin GPIO_PIN_3
#define WIFI_EN_GPIO_Port GPIOE
#define LIS2DH_INT1_Pin GPIO_PIN_6
#define LIS2DH_INT1_GPIO_Port GPIOE
#define PAD_J9005_Pin GPIO_PIN_9
#define PAD_J9005_GPIO_Port GPIOA
#define PAD_J9006_Pin GPIO_PIN_8
#define PAD_J9006_GPIO_Port GPIOA
#define MODEM_RESET_N_Pin GPIO_PIN_9
#define MODEM_RESET_N_GPIO_Port GPIOC
#define PAD_J9008_Pin GPIO_PIN_7
#define PAD_J9008_GPIO_Port GPIOC
#define MODEM_POWER_ON_Pin GPIO_PIN_8
#define MODEM_POWER_ON_GPIO_Port GPIOC
#define SSD1309_CMDDATA_Pin GPIO_PIN_15
#define SSD1309_CMDDATA_GPIO_Port GPIOD
#define PAD_J9007_Pin GPIO_PIN_2
#define PAD_J9007_GPIO_Port GPIOC
#define HWWDG_DONE_Pin GPIO_PIN_6
#define HWWDG_DONE_GPIO_Port GPIOC
#define SSD1309_RESET_Pin GPIO_PIN_13
#define SSD1309_RESET_GPIO_Port GPIOD
#define CHIP_SELECT_SDCARD_Pin GPIO_PIN_12
#define CHIP_SELECT_SDCARD_GPIO_Port GPIOD
#define HWWDG_WAKE_Pin GPIO_PIN_1
#define HWWDG_WAKE_GPIO_Port GPIOC
#define CHIP_SELECT_DISPLAY_Pin GPIO_PIN_14
#define CHIP_SELECT_DISPLAY_GPIO_Port GPIOD
#define PWR_SWITCH_CAPSENSE_9AXIS_Pin GPIO_PIN_12
#define PWR_SWITCH_CAPSENSE_9AXIS_GPIO_Port GPIOB
#define HTS221_INT_Pin GPIO_PIN_10
#define HTS221_INT_GPIO_Port GPIOE
#define MAX44009_INT_Pin GPIO_PIN_0
#define MAX44009_INT_GPIO_Port GPIOB
#define REGULATOR_SDCARD_Pin GPIO_PIN_10
#define REGULATOR_SDCARD_GPIO_Port GPIOD
#define LSM9DS1_DRDY_M_Pin GPIO_PIN_15
#define LSM9DS1_DRDY_M_GPIO_Port GPIOE
#define LSM9DS1_DEN_AG_Pin GPIO_PIN_13
#define LSM9DS1_DEN_AG_GPIO_Port GPIOE
#define PWR_SWITCH_VBAT_ADC_Pin GPIO_PIN_1
#define PWR_SWITCH_VBAT_ADC_GPIO_Port GPIOB
#define LSM9DS1_INT_M_Pin GPIO_PIN_14
#define LSM9DS1_INT_M_GPIO_Port GPIOE
#define LSM9DS1_INT1_AG_Pin GPIO_PIN_11
#define LSM9DS1_INT1_AG_GPIO_Port GPIOE
#define WIFI_INT_Pin GPIO_PIN_7
#define WIFI_INT_GPIO_Port GPIOE
#define BQ24251_CE_Pin GPIO_PIN_4
#define BQ24251_CE_GPIO_Port GPIOC
#define LSM9DS1_INT2_AG_Pin GPIO_PIN_12
#define LSM9DS1_INT2_AG_GPIO_Port GPIOE
#define LPS25H_PRES_INT_Pin GPIO_PIN_9
#define LPS25H_PRES_INT_GPIO_Port GPIOE
#define LIS2DH_INT2_Pin GPIO_PIN_8
#define LIS2DH_INT2_GPIO_Port GPIOE
#define BQ24251_STAT_Pin GPIO_PIN_5
#define BQ24251_STAT_GPIO_Port GPIOC

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
