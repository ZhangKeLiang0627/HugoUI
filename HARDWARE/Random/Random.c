#include "sys.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BEEPER.h"

uint32_t Time_ms = 0;	//�������

/**
  * @brief ��ʼ��TIM4(�Ѿ����ú����ȼ���) 
  * @param  ARR(��װ��ֵ��//PSC(Ԥ��Ƶֵ)
  * @retval ��
  */
void TIM4_Random_Init(uint16_t ARR, uint16_t PSC)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruture;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_TimeBaseInitStruture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruture.TIM_Period = ARR;	//ARR = 10000 - 1	//1ms
	TIM_TimeBaseInitStruture.TIM_Prescaler = PSC;//RSC = 10 - 1
	TIM_TimeBaseInitStruture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruture);

	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);

	TIM_Cmd(TIM4, ENABLE);
}

/**
  * @brief ����һ��0��100�������
  * @param  ��
  * @retval ��������õ��������
  */
uint32_t RandomCreate(void)
{
	uint32_t Num = 0;
	
	srand(Time_ms);
	
	Num = rand() % 1000;		//����һ��0��100�������//�ĳ�1000��
	
	return Num;
}

/**
  * @brief �ٲ���һ��0��1000�������
  * @param  Number��srand������
  * @retval ��������õ��������
  */
uint32_t RandomCreateAgain(uint16_t Number)
{
	uint32_t Num = 0;
	srand(Number);
	Num = rand() % 1000;
	
	return Num;
}


/**
  * @brief TIM4�жϣ�ms��������
  * @param  ��
  * @retval ��
  */
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		Beeper_Proc();
		
		Time_ms ++;
	}
}




