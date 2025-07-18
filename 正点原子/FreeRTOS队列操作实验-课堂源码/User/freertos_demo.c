/**
 ****************************************************************************************************
 * @file        freertos.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.4
 * @date        2022-01-04
 * @brief       FreeRTOS 移植实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 F407电机开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "freertos_demo.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./MALLOC/malloc.h"
/*FreeRTOS*********************************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/******************************************************************************************************/
/*FreeRTOS配置*/

/* START_TASK 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define START_TASK_PRIO         1
#define START_TASK_STACK_SIZE   128
TaskHandle_t    start_task_handler;
void start_task( void * pvParameters );

/* TASK1 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK1_PRIO         3
#define TASK1_STACK_SIZE   128
TaskHandle_t    task1_handler;
void task1( void * pvParameters );


/* TASK2 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK2_PRIO         4
#define TASK2_STACK_SIZE   128
TaskHandle_t    task2_handler;
void task2( void * pvParameters );

/* TASK3 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK3_PRIO         4
#define TASK3_STACK_SIZE   128
TaskHandle_t    task3_handler;
void task3( void * pvParameters );

/* TASK4 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK4_PRIO         2
#define TASK4_STACK_SIZE   128
TaskHandle_t    task4_handler;
void task4( void * pvParameters );
uint8_t Val = 0;

/******************************************************************************************************/
QueueHandle_t key_queue;        /* 小数据句柄 */
QueueHandle_t big_date_queue;   /* 大数据句柄 */
char buff[100] = {"我是一个大数组，大大的数组 124214 uhsidhaksjhdklsadhsaklj"};
/**
 * @brief       FreeRTOS例程入口函数
 * @param       无
 * @retval      无
 */
void freertos_demo(void)
{    
    /* 队列的创建 */
    key_queue = xQueueCreate( 8, sizeof(uint8_t) );
    if(key_queue != NULL)
    {
        printf("key_queue队列创建成功！！\r\n");
    }else printf("key_queue队列创建失败！！\r\n");
    
    big_date_queue = xQueueCreate( 1, sizeof(char *) );
    if(big_date_queue != NULL)
    {
        printf("big_date_queue队列创建成功！！\r\n");
    }else printf("big_date_queue队列创建失败！！\r\n");
    
    xTaskCreate((TaskFunction_t         )   start_task,
                (char *                 )   "start_task",
                (configSTACK_DEPTH_TYPE )   START_TASK_STACK_SIZE,
                (void *                 )   NULL,
                (UBaseType_t            )   START_TASK_PRIO,
                (TaskHandle_t *         )   &start_task_handler );
    vTaskStartScheduler();
}


void start_task( void * pvParameters )
{
    taskENTER_CRITICAL();               /* 进入临界区 */
    xTaskCreate((TaskFunction_t         )   task1,
                (char *                 )   "task1",
                (configSTACK_DEPTH_TYPE )   TASK1_STACK_SIZE,
                (void *                 )   NULL,
                (UBaseType_t            )   TASK1_PRIO,
                (TaskHandle_t *         )   &task1_handler );
                
    xTaskCreate((TaskFunction_t         )   task2,
                (char *                 )   "task2",
                (configSTACK_DEPTH_TYPE )   TASK2_STACK_SIZE,
                (void *                 )   NULL,
                (UBaseType_t            )   TASK2_PRIO,
                (TaskHandle_t *         )   &task2_handler );
               
    xTaskCreate((TaskFunction_t         )   task3,
                (char *                 )   "task3",
                (configSTACK_DEPTH_TYPE )   TASK3_STACK_SIZE,
                (void *                 )   NULL,
                (UBaseType_t            )   TASK3_PRIO,
                (TaskHandle_t *         )   &task3_handler );      
	xTaskCreate((TaskFunction_t         )   task4,
                (char *                 )   "task4",
                (configSTACK_DEPTH_TYPE )   TASK4_STACK_SIZE,
                (void *                 )   NULL,
                (UBaseType_t            )   TASK4_PRIO,
                (TaskHandle_t *         )   &task4_handler );   				
    vTaskDelete(NULL);
    taskEXIT_CRITICAL();                /* 退出临界区 */
}

/* 任务一，实现入队 */
void task1( void * pvParameters )
{
    
    
    BaseType_t   err = 0;
	static uint8_t num = 0;
    while(1) 
    {
        if(Val == KEY0_PRES)
        {
			num ++;
			Val = 0;
            err = xQueueSend( key_queue, &num, 10 );
            if(err != pdTRUE)
            {
                printf("key_queue队列发送失败\r\n");
            }
        }
        vTaskDelay(100);
    }
}

/* 任务二，小数据出队 */
void task2( void * pvParameters )
{
	uint8_t val;
    BaseType_t err = 0;
    while(1)
    {
        if(Val == KEY1_PRES)
		{
			Val = 0;
			err = xQueueReceive( key_queue,&val,10);
			if(err != pdTRUE)
			{
				printf("RECEIEVE key_queue队列读取失败\r\n");
			}else 
			{
				printf("RECEIVE数据：%d\r\n",val);
			}
		}
		vTaskDelay(100);
    }
}

/* 任务三，大数据出队 */
void task3( void * pvParameters )
{
    
	uint8_t val = 0;
    BaseType_t err = 0;
    while(1)
    {
        if(Val == KEY2_PRES)
		{
			Val = 0;
			err = xQueuePeek( key_queue,&val,10);
			if(err != pdTRUE)
			{
				printf("PEEK key_queue队列读取失败\r\n");
			}else 
			{
				printf("PEEK数据：%d\r\n",val);
			}
		}
		vTaskDelay(100);
	}
}

void task4( void * pvParameters )
{
    
    while(1)
    {
        Val = key_scan(0);
		while(Val != 0);
		vTaskDelay(10);
	}
}