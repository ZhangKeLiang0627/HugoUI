#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h" 	
   	   		   
//IO��������
#define SDA_IN()  {GPIOA->MODER&=~(3<<(12*2));GPIOA->MODER|=0<<12*2;} //PA12����ģʽ
#define SDA_OUT() {GPIOA->MODER&=~(3<<(12*2));GPIOA->MODER|=1<<12*2;} //PA12���ģʽ
//IO��������	 
#define IIC_SCL    PBout(1)  //SCL
#define IIC_SDA    PAout(12) //SDA	 
#define READ_SDA   PAin(12)  //����SDA 

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















