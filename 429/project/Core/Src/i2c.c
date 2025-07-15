/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    i2c.c
  * @brief   This file provides code for the configuration
  *          of the I2C instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2C_HandleTypeDef hi2c2;

/* I2C2 init function */
void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    __HAL_RCC_GPIOH_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PH4     ------> I2C2_SCL
    PH5     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    /* I2C2 clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PH4     ------> I2C2_SCL
    PH5     ------> I2C2_SDA
    */
    HAL_GPIO_DeInit(SCL_GPIO_Port, SCL_Pin);

    HAL_GPIO_DeInit(SDA_GPIO_Port, SDA_Pin);

  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */



//获取SH3001的ID


uint8_t ReadRegister(I2C_HandleTypeDef *hi2c, uint16_t devAddr, uint8_t regAddr) {
    uint8_t txData[1];  // 用于发送寄存器地址
    uint8_t rxData[1];  // 用于接收寄存器值

    // Step 1: 发送从设备地址 + 写标志，并发送寄存器地址
    txData[0] = regAddr;
    if (HAL_I2C_Master_Transmit(hi2c, devAddr, txData, 1, 100) != HAL_OK) {
        // 如果发送失败，返回错误
        return 0xFF; // 表示读取失败
    }

    // Step 2: 重新发送从设备地址 + 读标志，并接收数据
    if (HAL_I2C_Master_Receive(hi2c, devAddr, rxData, 1, 100) != HAL_OK) {
        // 如果接收失败，返回错误
        return 0xFF; // 表示读取失败
    }

    // 返回读取到的寄存器值
    return rxData[0];
}

uint16_t get_ID(void)
{
  uint8_t ID = 0;
  ID = ReadRegister(&hi2c2, SH3001_I2C_ADDR, 0x0F); // 读取ID寄存器
  return ID;
}



/* USER CODE END 1 */
