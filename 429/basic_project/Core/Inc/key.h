#ifndef KEY_H__
#define KEY_H__

#include "main.h"

#define KEY0_Press 1
#define KEY1_Press 2
#define KEY2_Press 3
#define WAKE_UP_Press 4


uint8_t KEY_scan(void);
#define KEY0_ck        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)           /* 读取KEY0引脚 */
#define KEY1_ck        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)           /* 读取KEY1引脚 */
#define KEY2_ck        HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)           /* 读取KEY2引脚 */
#define WK_UP_ck       HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin)     /* 读取WKUP引脚 */



void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(void);             /* 按键扫描函数 */
uint8_t key_Scan(void);             /* 按键扫描函数 */

#endif
