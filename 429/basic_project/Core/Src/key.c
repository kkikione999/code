#include "key.h"


//����ɨ�躯��
uint8_t KEY_scan(void){
  uint8_t key = 0xFF; //Ĭ��ֵΪ�ް�������
  if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){
    osDelay(10); //������ʱ
    if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){ //�ٴ�ȷ�ϰ���״̬
      key = KEY0_Press; //����0������
    }
  }else if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){
    osDelay(10); //������ʱ
    if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){ //�ٴ�ȷ�ϰ���״̬
      key = KEY1_Press; //����1������
    }
  }else if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET){
    osDelay(10); //������ʱ
    if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET){ //�ٴ�ȷ�ϰ���״̬
      key = KEY2_Press; //����2������
    }
  }else if(HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin) == GPIO_PIN_SET){
    osDelay(10); //������ʱ
    if(HAL_GPIO_ReadPin(WAKE_UP_GPIO_Port, WAKE_UP_Pin) == GPIO_PIN_SET){ //�ٴ�ȷ�ϰ���״̬
      key = WAKE_UP_Press; //���Ѱ���������
    }
  }
  return key;
}
