/**
 ****************************************************************************************************
 * @file        btim.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-04-20
 * @brief       基本定时器 驱动代码
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

#include "./BSP/LED/led.h"
#include "./BSP/TIMER/btim.h"
#include "./SYSTEM/usart/usart.h"

TIM_HandleTypeDef g_timx_handle;         /* 定时器参数句柄 */
TIM_HandleTypeDef g_tim7_handle;         /* 定时器参数句柄 */

uint32_t FreeRTOSRunTimeTicks;
/* 时基定时器的初始化 */
void ConfigureTimeForRunTimeStats(void)
{
    btim_timx_int_init(10-1, 90-1);  /* 100倍的系统时钟节拍 */
    FreeRTOSRunTimeTicks = 0;
}

/**
 * @brief       基本定时器TIMX定时中断初始化函数
 * @note
 *              基本定时器的时钟来自APB1,当PPRE1 ≥ 2分频的时候
 *              基本定时器的时钟为APB1时钟的2倍, 而APB1为45M, 所以定时器时钟 = 90Mhz
 *              定时器溢出时间计算方法: Tout = ((arr + 1) * (psc + 1)) / Ft us.
 *              Ft=定时器工作频率,单位:Mhz
 *
 * @param       arr : 自动重装值。
 * @param       psc : 时钟预分频数
 * @retval      无
 */
void btim_timx_int_init(uint16_t arr, uint16_t psc)
{
    g_timx_handle.Instance = BTIM_TIMX_INT;                      /* 定时器x */
    g_timx_handle.Init.Prescaler = psc;                          /* 分频 */
    g_timx_handle.Init.CounterMode = TIM_COUNTERMODE_UP;         /* 递增计数模式 */
    g_timx_handle.Init.Period = arr;                             /* 自动装载值 */
    HAL_TIM_Base_Init(&g_timx_handle);
    
    HAL_TIM_Base_Start_IT(&g_timx_handle);                       /* 使能定时器x和定时器更新中断 */
}

/* TIM7初始化函数 */
void btim_tim7_int_init(uint16_t arr, uint16_t psc)
{
    g_tim7_handle.Instance = BTIM_TIM7_INT;                      /* 定时器x */
    g_tim7_handle.Init.Prescaler = psc;                          /* 分频 */
    g_tim7_handle.Init.CounterMode = TIM_COUNTERMODE_UP;         /* 递增计数模式 */
    g_tim7_handle.Init.Period = arr;                             /* 自动装载值 */
    HAL_TIM_Base_Init(&g_tim7_handle);
    
    HAL_TIM_Base_Start_IT(&g_tim7_handle);                       /* 使能定时器x和定时器更新中断 */
}
/**
 * @brief       定时器底层驱动，开启时钟，设置中断优先级
                此函数会被HAL_TIM_Base_Init()函数调用
 * @param       无
 * @retval      无
 */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == BTIM_TIMX_INT)
    {
        BTIM_TIMX_INT_CLK_ENABLE();                     /* 使能TIMx时钟 */
        HAL_NVIC_SetPriority(BTIM_TIMX_INT_IRQn, 6, 0); /* 抢占6，子优先级0 */
        HAL_NVIC_EnableIRQ(BTIM_TIMX_INT_IRQn);         /* 开启ITMx中断 */
    }
    if(htim->Instance == BTIM_TIM7_INT)
    {
        BTIM_TIM7_INT_CLK_ENABLE();                     /* 使能TIM7时钟 */
        HAL_NVIC_SetPriority(BTIM_TIM7_INT_IRQn, 4, 0); /* 抢占4，子优先级0 */
        HAL_NVIC_EnableIRQ(BTIM_TIM7_INT_IRQn);         /* 开启ITM7中断 */
    }
}

/**
 * @brief       基本定时器TIMX中断服务函数
 * @param       无
 * @retval      无
 */
void BTIM_TIMX_INT_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_timx_handle);  /* 定时器回调函数 */
}

/* TIM7中断服务函数 */
void BTIM_TIM7_INT_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_tim7_handle);  /* 定时器回调函数 */
}

/**
 * @brief       回调函数，定时器中断服务函数调用
 * @param       无
 * @retval      无
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == BTIM_TIMX_INT)
    {
        FreeRTOSRunTimeTicks++;
    }else if(htim->Instance == BTIM_TIM7_INT)
    {
        printf("TIM7优先级为4的正在运行！！！！！\r\n");
    }
}
