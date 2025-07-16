#ifndef KEY_H__
#define KEY_H__

#include "main.h"

#define KEY0_Press 1
#define KEY1_Press 2
#define KEY2_Press 3
#define WAKE_UP_Press 4


uint8_t KEY_scan(void);
#define KEY0_ck        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)           /* ��ȡKEY0���� */
#define KEY1_ck        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)           /* ��ȡKEY1���� */
#define KEY2_ck        HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)           /* ��ȡKEY2���� */
#define WK_UP_ck       HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin)     /* ��ȡWKUP���� */



void key_init(void);                /* ������ʼ������ */
uint8_t key_scan(void);             /* ����ɨ�躯�� */
uint8_t key_Scan(void);             /* ����ɨ�躯�� */

#endif
