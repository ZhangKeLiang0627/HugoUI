#ifndef __KEY_H__
#define __KEY_H__

#define SHORT_PRESS		1	//单击
#define LONG_PRESS		2	//长按
#define DOUBLE_PRESS 	3	//双击

typedef struct{
	uint16_t Time_1;				//Time_1判断长按时长
	uint16_t Time_2;				//Time_2判断双击时长
	uint8_t FirstPress_Flag;		//第一次按下标志
	uint8_t SecondPress_Flag;		//第二次按下标志
	uint8_t LongPressOpen_Flag;		//是否打开长按标志(1打开/0关闭)
	uint8_t DoublePressOpen_Flag;	//是否打开双击标志(1打开/0关闭)
} Key_Tag;

/*底层函数*/
void Key_Init(void);

void TIM2_Key_Init(void);

/*应用层函数*/
uint8_t Key_GetNum(void);
#endif













