/**
 ****************************************************************************************************
 * @file        key.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       �������� ��������
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� ������ F429������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20220420
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#include "main.h"
#include "key.h"




uint8_t key_scan(void)
{
    static uint8_t keyval = 0;  /* �ϴΰ���ֵ */
    if(KEY0_ck || KEY1_ck || KEY2_ck || WK_UP_ck) {
        osDelay(10);  /* ������ʱ */
        if (KEY0_ck)
        {
            keyval = KEY1_Press;     /* KEY0���� */
        }else if (KEY1_ck)
        {
            keyval = KEY2_Press;     /* KEY1���� */
        }else if (KEY2_ck)
        {
            keyval = KEY2_Press;     /* KEY2���� */
        }else if (WK_UP_ck)
        {
            keyval = WAKE_UP_Press;  /* WKUP���� */
        }
        else
        {
            keyval = 0;             /* û�а������� */
        }
    }
    else keyval = 0;                /* û�а������� */

    return keyval;                  /* ���ؼ�ֵ */
}

uint8_t key_Scan(void)
{
    static uint8_t keyval = 0;  /* �ϴΰ���ֵ */
    if(KEY0_ck || KEY1_ck || KEY2_ck || WK_UP_ck) {
        if(KEY0_ck){
            while (KEY0_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* ������ʱ */
            }
            keyval = KEY0_Press;     /* KEY0���� */
        }
        else if(KEY1_ck){
            while (KEY1_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* ������ʱ */
            }
            keyval = KEY1_Press;     /* KEY1���� */
        }
        else if(KEY2_ck){
            while (KEY2_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* ������ʱ */
            }
            keyval = KEY2_Press;     /* KEY2���� */
        }
        else if(WK_UP_ck){
            while (WK_UP_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* ������ʱ */
            }
            keyval = WAKE_UP_Press;  /* WKUP���� */
        }
    }
    else keyval = 0;                /* û�а������� */

    return keyval;                  /* ���ؼ�ֵ */
}



















