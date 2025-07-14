#include "key.h"


//按键扫描函数
uint8_t KEY_scan(void){
  uint8_t key = 0xFF; //默认值为无按键按下
  if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){
    osDelay(10); //消抖延时
    if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){ //再次确认按键状态
      key = KEY0_Press; //按键0被按下
    }
  }else if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){
    osDelay(10); //消抖延时
    if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){ //再次确认按键状态
      key = KEY1_Press; //按键1被按下
    }
  }else if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET){
    osDelay(10); //消抖延时
    if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET){ //再次确认按键状态
      key = KEY2_Press; //按键2被按下
    }
  }else if(HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin) == GPIO_PIN_SET){
    osDelay(10); //消抖延时
    if(HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin) == GPIO_PIN_SET){ //再次确认按键状态
      key = WAKE_UP_Press; //唤醒按键被按下
    }
  }
  return key;
}
