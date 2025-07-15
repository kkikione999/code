/**
 ****************************************************************************************************
 * @file        key.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       按键输入 驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 阿波罗 F429开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20220420
 * 第一次发布
 *
 ****************************************************************************************************
 */

#include "main.h"
#include "key.h"




uint8_t key_scan(void)
{
    static uint8_t keyval = 0;  /* 上次按键值 */
    if(KEY0_ck || KEY1_ck || KEY2_ck || WK_UP_ck) {
        osDelay(10);  /* 消抖延时 */
        if (KEY0_ck)
        {
            keyval = KEY1_Press;     /* KEY0按下 */
        }else if (KEY1_ck)
        {
            keyval = KEY2_Press;     /* KEY1按下 */
        }else if (KEY2_ck)
        {
            keyval = KEY2_Press;     /* KEY2按下 */
        }else if (WK_UP_ck)
        {
            keyval = WAKE_UP_Press;  /* WKUP按下 */
        }
        else
        {
            keyval = 0;             /* 没有按键按下 */
        }
    }
    else keyval = 0;                /* 没有按键按下 */

    return keyval;                  /* 返回键值 */
}

uint8_t key_Scan(void)
{
    static uint8_t keyval = 0;  /* 上次按键值 */
    if(KEY0_ck || KEY1_ck || KEY2_ck || WK_UP_ck) {
        if(KEY0_ck){
            while (KEY0_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* 消抖延时 */
            }
            keyval = KEY0_Press;     /* KEY0按下 */
        }
        else if(KEY1_ck){
            while (KEY1_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* 消抖延时 */
            }
            keyval = KEY1_Press;     /* KEY1按下 */
        }
        else if(KEY2_ck){
            while (KEY2_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* 消抖延时 */
            }
            keyval = KEY2_Press;     /* KEY2按下 */
        }
        else if(WK_UP_ck){
            while (WK_UP_ck)
            {
                osDelay(pdMS_TO_TICKS(1));  /* 消抖延时 */
            }
            keyval = WAKE_UP_Press;  /* WKUP按下 */
        }
    }
    else keyval = 0;                /* 没有按键按下 */

    return keyval;                  /* 返回键值 */
}



















