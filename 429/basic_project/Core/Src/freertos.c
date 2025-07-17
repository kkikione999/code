/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for RED_LED */
osThreadId_t RED_LEDHandle;
const osThreadAttr_t RED_LED_attributes = {
  .name = "RED_LED",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BLUE_LED */
osThreadId_t BLUE_LEDHandle;
const osThreadAttr_t BLUE_LED_attributes = {
  .name = "BLUE_LED",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for uart_receive */
osThreadId_t uart_receiveHandle;
const osThreadAttr_t uart_receive_attributes = {
  .name = "uart_receive",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for KEY */
osThreadId_t KEYHandle;
const osThreadAttr_t KEY_attributes = {
  .name = "KEY",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for ask */
osThreadId_t askHandle;
const osThreadAttr_t ask_attributes = {
  .name = "ask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for ans */
osThreadId_t ansHandle;
const osThreadAttr_t ans_attributes = {
  .name = "ans",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for myQueue */
osMessageQueueId_t myQueueHandle;
const osMessageQueueAttr_t myQueue_attributes = {
  .name = "myQueue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void redLed(void *argument);
void blueLed(void *argument);
void message(void *argument);
void key_ctrl(void *argument);
void asker(void *argument);
void answer(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of myQueue */
  myQueueHandle = osMessageQueueNew (16, sizeof(uint8_t), &myQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of RED_LED */
  RED_LEDHandle = osThreadNew(redLed, NULL, &RED_LED_attributes);

  /* creation of BLUE_LED */
  BLUE_LEDHandle = osThreadNew(blueLed, NULL, &BLUE_LED_attributes);

  /* creation of uart_receive */
  uart_receiveHandle = osThreadNew(message, NULL, &uart_receive_attributes);

  /* creation of KEY */
  KEYHandle = osThreadNew(key_ctrl, NULL, &KEY_attributes);

  /* creation of ask */
  askHandle = osThreadNew(asker, NULL, &ask_attributes);

  /* creation of ans */
  ansHandle = osThreadNew(answer, NULL, &ans_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_redLed */
/**
  * @brief  Function implementing the RED_LED thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_redLed */
void redLed(void *argument)
{
  /* USER CODE BEGIN redLed */
  /* Infinite loop */
  for(;;)
  {
	  RED_TOGGLE();
    osDelay(pdMS_TO_TICKS(1000));
  }
  /* USER CODE END redLed */
}

/* USER CODE BEGIN Header_blueLed */
/**
* @brief Function implementing the BLUE_LED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_blueLed */
void blueLed(void *argument)
{
  /* USER CODE BEGIN blueLed */
  /* Infinite loop */
  for(;;)
  {
	  GREEN_TOGGLE();
    osDelay(pdMS_TO_TICKS(500));
  }
  /* USER CODE END blueLed */
}

/* USER CODE BEGIN Header_message */
/**
* @brief Function implementing the uart_receive thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_message */
void message(void *argument)
{
  /* USER CODE BEGIN message */
  /* Infinite loop */
  char message_buffer[100];
  for(;;)
  {
    //����һ����ѯ���� һ��Ҫ������100���ֽڲŽ���
    // HAL_UART_Receive(&huart1, (uint8_t *)message_buffer, sizeof(message_buffer)-1, HAL_MAX_DELAY);
    // message_buffer[sizeof(message_buffer) - 1] = '\0'; // Ensure null termination
    // printf("Received message: %s\r\n", message_buffer);
    //���������жϽ���
    // HAL_UART_Receive_IT(&huart1, (uint8_t *)message_buffer, sizeof(message_buffer)-1);
    // message_buffer[sizeof(message_buffer) - 1] = '\0'; // Ensure null termination
    // printf("Received message: %s\r\n", message_buffer);
  }
  /* USER CODE END message */
}

/* USER CODE BEGIN Header_key_ctrl */
/**
* @brief Function implementing the KEY thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_key_ctrl */
void key_ctrl(void *argument)
{
  /* USER CODE BEGIN key_ctrl */
  /* Infinite loop */
	uint8_t key = 0;
    while(1)
    {
        key = key_scan();
        if(key == KEY0_Press)
        {
            printf("�������й���task1\r\n");
            osThreadSuspend(RED_LEDHandle);  // ����RED_LED����
           
        }else if(key == KEY1_Press)
        {
            printf("�������лָ�task1\r\n");
            osThreadResume(RED_LEDHandle);   // �ָ�RED_LED����
        }
        else if(key == KEY2_Press)
        {
            printf("����task2\r\n");
            osThreadSuspend(BLUE_LEDHandle); // ����BLUE_LED����
        }
        else if(key == WAKE_UP_Press)
        {
            printf("�������лָ�task2\r\n");
            osThreadResume(BLUE_LEDHandle);  // �ָ�BLUE_LED����
        }
        osDelay(pdMS_TO_TICKS(5)); // ��ʱ100ms
    }
  /* USER CODE END key_ctrl */
}

/* USER CODE BEGIN Header_asker */
/**
* @brief Function implementing the ask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_asker */
void asker(void *argument)
{
  /* USER CODE BEGIN asker */
  uint8_t ask_value = 0;
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    if(key_scan() == WAKE_UP_Press)
    {
      status = osMessageQueuePut(myQueueHandle, &ask_value, 0U, osWaitForever);
      if (status != osOK) {
        printf("asker: queue is full\r\n");
      } else {
        printf("asker: sent = %d\r\n", ask_value);
      }
      ask_value++;
    }
    osDelay(pdMS_TO_TICKS(5));
  }
  /* USER CODE END asker */
}

/* USER CODE BEGIN Header_answer */
/**
* @brief Function implementing the ans thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_answer */
void answer(void *argument)
{
  /* USER CODE BEGIN answer */
  /* Infinite loop */
  osStatus_t status;
  uint8_t received_value;
  for(;;)
  {
    if(key_scan() == KEY2_Press){
      status = osMessageQueueGet(myQueueHandle, &received_value, NULL, osWaitForever);
      if (status == osOK) {
        printf("ans: received = %d\r\n", received_value);
      } else {
        printf("ans: queue is empty\r\n");
      }
    }
    osDelay(pdMS_TO_TICKS(5)); // Simulate processing time
  }
  /* USER CODE END answer */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

