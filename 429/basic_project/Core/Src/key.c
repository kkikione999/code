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



/**
 * @brief       ����ɨ�躯��
 * @note        �ú�������Ӧ���ȼ�(ͬʱ���¶������): WK_UP > KEY2 > KEY1 > KEY0!!
 * @param       mode:0 / 1, ���庬������:
 *   @arg       0,  ��֧��������(���������²���ʱ, ֻ�е�һ�ε��û᷵�ؼ�ֵ,
 *                  �����ɿ��Ժ�, �ٴΰ��²Ż᷵��������ֵ)
 *   @arg       1,  ֧��������(���������²���ʱ, ÿ�ε��øú������᷵�ؼ�ֵ)
 * @retval      ��ֵ, ��������:
 *              KEY0_PRES, 1, KEY0����
 *              KEY1_PRES, 2, KEY1����
 *              KEY2_PRES, 3, KEY2����
 *              WKUP_PRES, 4, WKUP����
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;  /* �������ɿ���־ */
    uint8_t keyval = 0;

    if (mode) key_up = 1;       /* ֧������ */

    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))  /* �����ɿ���־Ϊ1, ��������һ������������ */
    {
        osDelay(10);           /* ȥ���� */
        key_up = 0;

        if (KEY0 == 0)  keyval = KEY0_PRES;

        if (KEY1 == 0)  keyval = KEY1_PRES;

        if (KEY2 == 0)  keyval = KEY2_PRES;

        if (WK_UP == 1) keyval = WKUP_PRES;
    }
    else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)         /* û���κΰ�������, ��ǰ����ɿ� */
    {
        key_up = 1;
    }

    return keyval;              /* ���ؼ�ֵ */
}




















