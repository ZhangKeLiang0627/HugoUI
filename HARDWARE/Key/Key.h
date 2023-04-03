#ifndef __KEY_H__
#define __KEY_H__

#define SHORT_PRESS		1	//����
#define LONG_PRESS		2	//����
#define DOUBLE_PRESS 	3	//˫��

typedef struct{
	uint16_t Time_1;				//Time_1�жϳ���ʱ��
	uint16_t Time_2;				//Time_2�ж�˫��ʱ��
	uint8_t FirstPress_Flag;		//��һ�ΰ��±�־
	uint8_t SecondPress_Flag;		//�ڶ��ΰ��±�־
	uint8_t LongPressOpen_Flag;		//�Ƿ�򿪳�����־(1��/0�ر�)
	uint8_t DoublePressOpen_Flag;	//�Ƿ��˫����־(1��/0�ر�)
} Key_Tag;

/*�ײ㺯��*/
void Key_Init(void);

void TIM2_Key_Init(void);

/*Ӧ�ò㺯��*/
uint8_t Key_GetNum(void);
#endif













