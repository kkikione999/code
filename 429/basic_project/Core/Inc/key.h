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
#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)     /* ��ȡKEY0���� */
#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)     /* ��ȡKEY1���� */
#define KEY2        HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY0_Pin)     /* ��ȡKEY2���� */
#define WK_UP       HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin)     /* ��ȡWKUP���� */


#define KEY0_PRES    1              /* KEY0���� */
#define KEY1_PRES    2              /* KEY1���� */
#define KEY2_PRES    3              /* KEY2���� */
#define WKUP_PRES    4              /* KEY_UP����(��WK_UP) */

void key_init(void);                /* ������ʼ������ */
uint8_t key_scan(uint8_t mode);     /* ����ɨ�躯�� */

#endif
