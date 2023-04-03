#include "stm32f4xx.h"                  // Device header
#include "SHT30.h"
#include "myiic.h"

#define Write 0
#define Read  1


float Humiture[4];
u8 Humiture_buff[20];

//温湿度获取函数
//u8 addr SHT30的从机地址（0x44）
void SHT30_Read_Value(u8 addr)
{
    u16 tem, hum;
    u16 buff[6];
    float Temperature = 0.0f, Humidity = 0.0f;

    IIC_Start();
    IIC_Send_Byte(addr<<1 | Write);
    IIC_Wait_Ack();
    IIC_Send_Byte(0X2C);
    IIC_Wait_Ack();
    IIC_Send_Byte(0X06);
    IIC_Wait_Ack();
    IIC_Stop();
    delay_ms(50);
    
    IIC_Start();
    IIC_Send_Byte(addr<<1 | Read);
    if(IIC_Wait_Ack() == 0)//i2c连续读
    {
        buff[0]=IIC_Read_Byte(1);
		buff[1]=IIC_Read_Byte(1);
		buff[2]=IIC_Read_Byte(1);
		buff[3]=IIC_Read_Byte(1);
		buff[4]=IIC_Read_Byte(1);
		buff[5]=IIC_Read_Byte(0);
		IIC_NAck();
		IIC_Stop();
    }

    tem = ((buff[0]<<8) | buff[1]);//两个温度数据拼接成十六位
    hum = ((buff[3]<<8) | buff[4]);//两个湿度数据拼接成十六位

    /*转换成实际温湿度*/
    Temperature = (175.0f*(float)tem/65535.0f-45.0f) ;// T = -45 + 175 * tem / (2^16-1)
    Humidity= (100.0f*(float)hum/65535.0f);// RH = hum*100 / (2^16-1)

//     if((Temperature>=-20)&&(Temperature<=125)&&(Humidity>=0)&&(Humidity<=100))
//     {
// //      sprintf(Humiture_buff,"%6.2f*C %6.2f%",Temperature,Humidity);//111.01*C 100.01%（保留2位小数）
		
//     }
// //    printf("温湿度：%s\n",Humiture_buff);
	printf("Temperature:%.1f Humidity:%.1f\r\n",Temperature,Humidity);
	hum=0;
	tem=0;
}


void SHT30_Read_ValueOut(u8 addr, float *Get_temperature, float *Get_Humidity)
{
    u16 tem, hum;
    u16 buff[6];
    float Temperature = 0.0f, Humidity = 0.0f;

    IIC_Start();
    IIC_Send_Byte(addr<<1 | Write);
    IIC_Wait_Ack();
    IIC_Send_Byte(0X2C);
    IIC_Wait_Ack();
    IIC_Send_Byte(0X06);
    IIC_Wait_Ack();
    IIC_Stop();
    delay_ms(50);
    
    IIC_Start();
    IIC_Send_Byte(addr<<1 | Read);
    if(IIC_Wait_Ack() == 0)//i2c连续读
    {
        buff[0]=IIC_Read_Byte(1);
		buff[1]=IIC_Read_Byte(1);
		buff[2]=IIC_Read_Byte(1);
		buff[3]=IIC_Read_Byte(1);
		buff[4]=IIC_Read_Byte(1);
		buff[5]=IIC_Read_Byte(0);
		IIC_NAck();
		IIC_Stop();
    }

    tem = ((buff[0]<<8) | buff[1]);//两个温度数据拼接成十六位
    hum = ((buff[3]<<8) | buff[4]);//两个湿度数据拼接成十六位

    /*转换成实际温湿度*/
    Temperature = (175.0f*(float)tem/65535.0f-45.0f) ;// T = -45 + 175 * tem / (2^16-1)
    Humidity= (100.0f*(float)hum/65535.0f);// RH = hum*100 / (2^16-1)

    *Get_temperature = Temperature; *Get_Humidity = Humidity;
	printf("Temperature:%.1f Humidity:%.1f\r\n",Temperature,Humidity);
	hum=0;
	tem=0;
}









