#include "BEEPER.h"
#include "stm32f4xx.h"                  // Device header
#include "Random.h"
#include "math.h"

/*����Beeper��handle*/
BEEPER_Tag Beeper0;

/*C4-B8��������Ӧ��Ƶ�ʴ�С*/
const uint16_t MusicNoteFrequency[] = {
//rest_note
    0,
//   C    C#   D   Eb    E    F    F#   G    G#   A   Bb    B
    262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
    523, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 988,
    1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
    2093, 2218, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
    4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902,
//check_note
    0,
};

/*ȫ��TONE�ṹ��ָ�룬���ڶ�ʱ��TIM4�жϺ�����*/
TONE *MySound = NULL;

/*����*/
TONE BEEPER_KEYPRESS[] ={
{NOTE_C6, 50},
{CHECK_NOTE, 0},//���λ
};

TONE BEEPER_TRITONE[] ={
{NOTE_B5, 50},
{NOTE_D6, 50},
{NOTE_F6, 50},
{CHECK_NOTE, 0},//���λ
};

TONE BEEPER_WARNING[] ={
{NOTE_F4, 50},
{REST_NOTE, 50},
{NOTE_F4, 50},
{CHECK_NOTE, 0},//���λ
};



TONE BEEP1[] = {
{NOTE_C5, 110},
{REST_NOTE, 20},//��ֹ��
{NOTE_C5, 110},
{REST_NOTE, 20},
{NOTE_G5, 110},
{REST_NOTE, 20},
{NOTE_G5, 110},
{REST_NOTE, 20},
{NOTE_A5, 110},
{REST_NOTE, 20},
{NOTE_A5, 110},
{REST_NOTE, 20},
{NOTE_G5, 220},
{REST_NOTE, 20},
{NOTE_F6, 110},
{REST_NOTE, 20},
{NOTE_F6, 110},
{REST_NOTE, 20},
{NOTE_E7, 110},
{REST_NOTE, 20},
{NOTE_E7, 110},
{REST_NOTE, 20},
{NOTE_D8, 110},
{REST_NOTE, 20},
{NOTE_D8, 110},
{REST_NOTE, 20},
{NOTE_C4, 220},
{CHECK_NOTE, 0},//���λ
};



TONE BEEP2[] = {
    {REST_NOTE, 200},
    {REST_NOTE, 200},
    {REST_NOTE, 200},
    {NOTE_C5, 100},
    {NOTE_B4, 100},

    {NOTE_A4, 200},
    {NOTE_E5, 400},
    {NOTE_C5, 100},
    {NOTE_A4, 100},

    {NOTE_B4, 200},
    {NOTE_F5, 200},
    {NOTE_E5, 100},
    {NOTE_D5, 300},

    {NOTE_C5, 100},
    {NOTE_D5, 100},
    {NOTE_C5, 100},
    {NOTE_D5, 100},
    {NOTE_E5, 200},
    {NOTE_C5, 100},
    {NOTE_B4, 100},

    {NOTE_A4, 200},
    {NOTE_D5, 200},
    {NOTE_C5, 100},
    {NOTE_B4, 100},
    {REST_NOTE, 100},
    {NOTE_A4, 50},
    {NOTE_B4, 50},

    {NOTE_C5, 200},
    {NOTE_A4, 200},
    {NOTE_E5, 200},
    {NOTE_C5, 200},

    {NOTE_D5, 200},
    {NOTE_A5, 200},
    {NOTE_G5, 200},
    {NOTE_F5, 100},
    {NOTE_E5, 50},
    {NOTE_D5, 50},

    {NOTE_E5, 800},

    {CHECK_NOTE, 0},//���λ
};


void TIM1_PWM_Init(u16 arr)
{
    /*��ʼ���ṹ��*/
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    /*����rccʱ��*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    /*��ʼ��TIM1*/
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = arr - 1;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 10 - 1;//ʹ��Ƶ��ʣ��10000kHz
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	// TIM_ARRPreloadConfig(TIM1, ENABLE);
	
    /*TIM1����PWMģʽ*/
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = arr/2;//ռ�ձ�
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);

    TIM_CtrlPWMOutputs(TIM1, ENABLE);

    TIM_Cmd(TIM1, DISABLE);//�ȹص���ֹ�������ֽ�
}

void Beeper_Init(void)
{
    /*��ʼ���ṹ��*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /*����rccʱ��*/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /*��ʼ��PA8-TIM1_CH1*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);

    /*��ʼ����ʱ��TIM1*/
    TIM1_PWM_Init(370);

    /* BEEPERʹ�ܱ�־λ */
    Beeper0.Beeper_Enable = 1;

    Beeper0.Sound_Loud = 0;

}

/*�����Ӧ��Ԥ��װֵARR��psc = 10 - 1��//��10000kHz / ����Ƶ��*/
uint16_t Set_Musical_Note(uint16_t frq)
{
    /*��ֹ��ֹ��ʱ�������ֽ�*/
    if(frq == 0) return 0;
    float temp = 0;
    temp = 10000000.0f / (float)frq;
    return (uint16_t)temp;
}


/**
  * @brief Beeper��Ӧ�ò㺯��
  * @param  TONE *Sound ����ṹ������
  * @retval ��
  */
void Beeper_Perform(TONE *Sound)
{
    /*�ñ������ڼ���ṹ������ĳ���*/
    uint16_t Note_Length;
    TIM_Cmd(TIM1, DISABLE);
    
    /*��ȫ�ֽṹ��ָ��ָ���������*/
    MySound = Sound;

    /*ͨ��Ѱ�Ҽ��λCHECK_NOTE�����㴫��Ľṹ�峤��//��Ϊsizeof���ڱ�������ɵ���������û����*/
    for(Note_Length = 0; MySound[Note_Length].Note != CHECK_NOTE; Note_Length++);
    
    /*���賤�ȴ�С*/
    Beeper0.Sound_Size = Note_Length;
    /*������������*/
    Beeper0.Beep_Play_Schedule = 0;
    /*����������ʹ�ܱ�־λ*/
    Beeper0.Beeper_Set_Flag = 1;

}

/* ����1ms��ʱ���жϽ���ѭ�� */
void Beeper_Proc(void)
{
    /*�ж��Ƿ����*/
    if(Beeper0.Beeper_Continue_Flag && Beeper0.Beeper_Enable)
    {
        /*�ж�����������û*/
        if(Beeper0.Beep_Play_Schedule < Beeper0.Sound_Size)
        {
            /*��Ԥ��װ��ֵ��ֵ���ı�����*/
            TIM1->ARR = (uint16_t)Set_Musical_Note(MusicNoteFrequency[MySound[Beeper0.Beep_Play_Schedule].Note]);
            /*��PWMռ�ձȸ�ֵ���ı�����*/
            TIM1->CCR1 =(uint16_t)TIM1->ARR/(100 - Beeper0.Sound_Loud);
            /*ʱ�����1ms*/
            Beeper0.Beeper_Count --;
            TIM_Cmd(TIM1, ENABLE);
        }
        /*ʧ�ܷ���������ձ�־λ*/
        else {TIM_Cmd(TIM1,DISABLE); Beeper0.Beeper_Continue_Flag = 0;} 
        /*�����������˼�����count = 65535ʱ����˼������ʱ�����ˣ��������������*/
        if(!(Beeper0.Beeper_Count < 65535))
        {
            /*�������ߵ���һ������*/
            Beeper0.Beep_Play_Schedule ++;
            /*��ֵ�µ���ʱ���ȸ�count*/
            Beeper0.Beeper_Count = MySound[Beeper0.Beep_Play_Schedule].Delay;
        }
    }else TIM_Cmd(TIM1,DISABLE);
    /*�ж��Ƿ���������*///�о��ⲽ��̫��Ҫ��//����ȱһ����
    if(Beeper0.Beeper_Set_Flag && Beeper0.Beeper_Enable)
    {
        /*����ձ�־λ*/
        Beeper0.Beeper_Set_Flag = 0;
        /*�ж��������Ƿ�Ϊ��//�ⲽ�����õ�������־λ���жϣ�������������������*/
        if(Beeper0.Beep_Play_Schedule == 0) 
        {
            /*����������������־λ*/
            Beeper0.Beeper_Continue_Flag = 1;
            Beeper0.Beeper_Count = MySound[Beeper0.Beep_Play_Schedule].Delay;
        }
    }
}











