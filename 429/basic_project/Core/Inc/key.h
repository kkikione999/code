#ifndef KEY_H__
#define KEY_H__

#include "main.h"

#define RED_LED(x) HAL_GPIO_WritePin(GPIOB, RED_LED_Pin, (GPIO_PinState)x)
#define GREEN_LED(x) HAL_GPIO_WritePin(GPIOB, GREEN_LED_Pin, (GPIO_PinState)x)
#define RED_TOGGLE() HAL_GPIO_TogglePin(GPIOB, RED_LED_Pin)
#define GREEN_TOGGLE() HAL_GPIO_TogglePin(GPIOB, GREEN_LED_Pin)
#define KEY0_Press 0
#define KEY1_Press 1
#define KEY2_Press 2
#define WAKE_UP_Press 3

uint8_t KEY_scan(void);
#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)     /* 读取KEY0引脚 */
#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)     /* 读取KEY1引脚 */
#define KEY2        HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY0_Pin)     /* 读取KEY2引脚 */
#define WK_UP       HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin)     /* 读取WKUP引脚 */


#define KEY0_PRES    1              /* KEY0按下 */
#define KEY1_PRES    2              /* KEY1按下 */
#define KEY2_PRES    3              /* KEY2按下 */
#define WKUP_PRES    4              /* KEY_UP按下(即WK_UP) */

void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(uint8_t mode);     /* 按键扫描函数 */

#endif
