#include "pwm.h"

// TIM2 PWM���ֳ�ʼ��
// PWM�����ʼ��
// arr���Զ���װֵ
// psc��ʱ��Ԥ��Ƶ��

void TIM2_PWM_Init(u32 arr, u32 psc) {
  //�˲������ֶ��޸�IO������

  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  // TIM2ʱ��ʹ��
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); //ʹ��PORTAʱ��

  GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;          // GPIOA0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;       //���ù���
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //�ٶ�100MHz
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //���츴�����
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       //����
  GPIO_Init(GPIOC, &GPIO_InitStructure);             //��ʼ��PA0

  TIM_TimeBaseStructure.TIM_Prescaler = psc;                  //��ʱ����Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���ģʽ
  TIM_TimeBaseStructure.TIM_Period = arr; //�Զ���װ��ֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //��ʼ����ʱ��2

  //��ʼ��TIM2 Channel1 PWMģʽ
  TIM_OCInitStructure.TIM_OCMode =
      TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM������ȵ���ģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_OCPolarity =
      TIM_OCPolarity_Low;            //�������:TIM����Ƚϼ��Ե�
  TIM_OCInitStructure.TIM_Pulse = 0; //�Ƚϳ�ʼֵ
  TIM_OC3Init(TIM3, &TIM_OCInitStructure); //����Tָ���Ĳ�����ʼ������TIM2OC1

  TIM_OC3PreloadConfig(TIM3,
                       TIM_OCPreload_Enable); //ʹ��TIM2��CCR1�ϵ�Ԥװ�ؼĴ���

  TIM_ARRPreloadConfig(TIM3, ENABLE); // ARPEʹ��

  TIM_Cmd(TIM3, ENABLE);
}

void PWM_Init(void) {
  TIM2_PWM_Init(
      200 - 1,
      8400 -
          1); // 84M/84=1Mhz����Ƶ��,��װ��ֵ1000������PWMƵ��Ϊ 1M/1000=1Khz.
}