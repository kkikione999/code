#ifndef __KEY_H
#define __KEY_H

#include "main.h"

#define RED_LED(x) HAL_GPIO_WritePin(GPIOB, RED_LED_Pin, (GPIO_PinState)x)
#define GREEN_LED(x) HAL_GPIO_WritePin(GPIOB, GREEN_LED_Pin, (GPIO_PinState)x)
#define RED_TOGGLE() HAL_GPIO_TogglePin(GPIOB, RED_LED_Pin)
#define GREEN_TOGGLE() HAL_GPIO_TogglePin(GPIOB, GREEN_LED_Pin)
#define KEY0_Press 0
#define KEY1_Press 1
#define KEY2_Press 2
#define WAKE_UP_Press 3

uint8_t KEY_scan(void){};


#endif
