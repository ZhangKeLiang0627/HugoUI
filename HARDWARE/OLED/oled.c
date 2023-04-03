#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"

u8 OLED_GRAM[128][4];


void I2C_WriteByte(uint8_t addr,uint8_t data)//??? ??IIC??
{
	while(I2C_GetFlagStatus(I2C1,I2C_FLAG_BUSY));
    //????IIC1????        ?????
	
	I2C_GenerateSTART(I2C1,ENABLE);
    //??IIC1
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
    //??????IIC????	SR1????0 ??EV5
 
	I2C_Send7bitAddress(I2C1,OLED_ADDRESS,I2C_Direction_Transmitter);
    //IIC??7?????
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    //??????IIC??????    SR1????1 ??EV6
 
	I2C_SendData(I2C1,addr);
    //IIC?????????,??????????
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTING));
	//??????????????    ??EV8
    
	I2C_SendData(I2C1,data);
    //IIC???????
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTING));
    //??????????????    ??EV8
	
	I2C_GenerateSTOP(I2C1,ENABLE);
    //IIC??
}



void WriteCmd(unsigned char I2C_Command)//???
{
   	I2C_WriteByte(0x00, I2C_Command);
}


void WriteDat(unsigned char I2C_Data)//???
{
   	I2C_WriteByte(0x40, I2C_Data);
}




//���Ժ���
void OLED_ColorTurn(u8 i)
{
	if(i==0)
		{
			WriteCmd(0xA6);//������ʾ
		}
	if(i==1)
		{
			WriteCmd(0xA7);//��ɫ��ʾ
		}
}

//��Ļ��ת180��
void OLED_DisplayTurn(u8 i)
{
	if(i==0)
		{
			WriteCmd(0xC8);//????
			WriteCmd(0xA1);
		}
	if(i==1)
		{
			WriteCmd(0xC0);//????
			WriteCmd(0xA0);
		}
}



//����OLED��ʾ 
void OLED_DisPlay_On(void)
{
	WriteCmd(0x8D);//?????
	WriteCmd(0x14);//?????
	WriteCmd(0xAF);//????
}

//�ر�OLED��ʾ 
void OLED_DisPlay_Off(void)
{
	WriteCmd(0x8D);//?????
	WriteCmd(0x10);//?????
	WriteCmd(0xAE);//????
}

//�����Դ浽OLED	
void OLED_Refresh(void)
{
	u8 i,n;
	for(i=0;i<4;i++)	//????? i<4
	{
		WriteCmd(0xb0+i); //???????
		WriteCmd(0x00);   //????????
		WriteCmd(0x10);   //????????

		for(n=0;n<128;n++)
		{
			WriteDat(OLED_GRAM[n][i]);
		}
  }
}

void OLED_PartialRefresh(uint8_t x1,uint8_t x2,uint8_t y1,uint8_t y2)
{
	u8 i,n;
	for(i=y1;i<y2;i++)	//���ﲻһ�� i<4
	{
		WriteCmd(0xb0+i); //???????
		WriteCmd(0x00);   //????????
		WriteCmd(0x10);   //????????
		for(n=x1;n<x2;n++)
		{
			WriteDat(OLED_GRAM[n][i]);
		}
  }
}
	
void OLED_PartialRefreshForBuff(uint8_t x1,uint8_t x2,uint8_t y1,uint8_t y2)
{
	u8 i,n;
	for(i=y1;i<y2;i++)	//���ﲻһ�� i<4
	{
		WriteCmd(0xb0+i); //???????
		WriteCmd(0x00);   //????????
		WriteCmd(0x10);   //????????
		for(n=x1;n<x2;n++)
		{
			WriteDat(OLED_GRAM[n][i]);
		}
	}
}

//��������
void OLED_Clear(void)
{
	u8 i,n;
	for(i=0;i<4;i++)	//���ﲻһ�� i<4
	{
	   for(n=0;n<128;n++)
			{
			 OLED_GRAM[n][i]=0;//�����������
			}
  }
	OLED_Refresh();//������ʾ
}

//���� 
//x:0~127
//y:0~63
//t:1 ��� 0,���	
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 i,m,n;
	i=y/8;
	m=y%8;
	n=1<<m;
	if(t){OLED_GRAM[x][i]|=n;}
	else
	{
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
		OLED_GRAM[x][i]|=n;
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
	}
}

//����
//x1,y1:�������
//x2,y2:��������
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1;
	uRow=x1;//�����������
	uCol=y1;
	if(delta_x>0)incx=1; //���õ������� 
	else if (delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//ˮƽ�� 
	else {incy=-1;delta_y=-delta_x;}
	if(delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		OLED_DrawPoint(uRow,uCol,mode);//����
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
//x,y:Բ������
//r:Բ�İ뾶
void OLED_DrawCircle(u8 x,u8 y,u8 r)
{
	int a, b,num;
    a = 0;
    b = r;
    while(2 * b * b >= r * r)      
    {
        OLED_DrawPoint(x + a, y - b,1);
        OLED_DrawPoint(x - a, y - b,1);
        OLED_DrawPoint(x - a, y + b,1);
        OLED_DrawPoint(x + a, y + b,1);
 
        OLED_DrawPoint(x + b, y + a,1);
        OLED_DrawPoint(x + b, y - a,1);
        OLED_DrawPoint(x - b, y - a,1);
        OLED_DrawPoint(x - b, y + a,1);
        
        a++;
        num = (a * a + b * b) - r*r;//���㻭�ĵ���Բ�ĵľ���
        if(num > 0)
        {
            b--;
            a--;
        }
    }
}



//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~63
//size1:ѡ������ 6x8/6x12/8x16/12x24
//mode:0,��ɫ��ʾ;1,������ʾ
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode)
{
	u8 i,m,temp,size2,chr1;
	u8 x0=x,y0=y;
	if(size1==8)size2=6;
	else size2=(size1/8+((size1%8)?1:0))*(size1/2);  //�õ�����һ���ַ���Ӧ������ռ���ֽ���
	chr1=chr-' ';  //����ƫ�ƺ��ֵ
	for(i=0;i<size2;i++)
	{
		if(size1==8)
			  {temp=asc2_0806[chr1][i];} //����0806����
		else if(size1==12)
        {temp=asc2_1206[chr1][i];} //����1206����
		else if(size1==16)
        {temp=asc2_1608[chr1][i];} //����1608����
		else if(size1==24)
        {temp=asc2_2412[chr1][i];} //����2412����
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((size1!=8)&&((x-x0)==size1/2))
		{x=x0;y0=y0+8;}
		y=y0;
  }
}


//��ʾ�ַ���
//x,y:�������  
//size1:�����С 
//*chr:�ַ�����ʼ��ַ 
//mode:0,��ɫ��ʾ;1,������ʾ
/**
  * @brief ��ʾ�ַ��������֡����ġ�Ӣ�ķ��ţ�
  * @param x	������			0~127
  * @param y	������			0~63
  * @param *chr	�ַ�����ʼ��ַ
  * @param size1 �����С		д16����Ϊֻ����16*16�Ĺ�����
  * @param mode ��ɫģʽ		��0������ʾ�� ��1������ʾ    	
  * @retval 
  */
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode)
{
	while(*chr != '\0')
	{
		if((*chr >= ' ')&&(*chr <= '~'))
		{
			if(size1 == 8)
			{
				if((x + 6) > 128)
					x = 0;
					y = y + size1;
			}
			else if((x + size1/2) > 128)
			{
				x = 0;
				y = y + size1;
			}
			OLED_ShowChar(x, y, *chr, size1, mode);
			if(size1 == 8)x += 6;
			else x += size1/2;
			chr++;
		}
		else
		{
			if(size1 == 8)
			{
				if((x + 6) > 128)
					x = 0;
					y = y + size1;
			}
			else if((x +size1) > 128)
			{
				x = 0;
				y = y + size1;
			}
			
			OLED_ShowChinese(x, y, chr, size1, mode);
			if(size1 == 8)x += 6;
			else x += size1;
			chr += 2;
		}

	}
}


//m^n
u32 OLED_Pow(u8 m,u8 n)
{
	u32 result=1;
	while(n--)
	{
	  result*=m;
	}
	return result;
}

//��ʾ����
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//mode:0,��ɫ��ʾ;1,������ʾ
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode)
{
	u8 t,temp,m=0;
	if(size1==8)m=2;
	for(t=0;t<len;t++)
	{
		temp=(num/OLED_Pow(10,len-t-1))%10;
			if(temp==0)
			{
				OLED_ShowChar(x+(size1/2+m)*t,y,'0',size1,mode);
      }
			else 
			{
			  OLED_ShowChar(x+(size1/2+m)*t,y,temp+'0',size1,mode);
			}
  }
}

//��ʾ����
//x,y:�������
//num:���ֶ�Ӧ�����
//mode:0,��ɫ��ʾ;1,������ʾ
void OLED_ShowChinese(uint8_t x, uint8_t y, uint8_t* str, uint8_t size1, uint8_t mode)
{
	uint8_t num;
	int index = 0;
	uint8_t m,temp;
	uint8_t x0=x,y0=y;
	uint16_t i,size3=(size1/8+((size1%8)?1:0))*size1;  //�õ�����һ���ַ���Ӧ������ռ���ֽ���
	for(i=0;i<size3;i++)
	{
		if(size1==16)
		{
			for(index = 0; index < sizeof(Hzk)/35; index++)
			{
				if(Hzk[index].name[0] == str[0]&&Hzk[index].name[1] == str[1])
					temp = Hzk[index].dat[i];
			}
		}	
		else if(size1==24)
				{temp=Hzk2[num][i];}//����24*24����
		else if(size1==32)       
				{temp=Hzk3[num][i];}//����32*32����
		else if(size1==64)
				{temp=Hzk4[num][i];}//����64*64����
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((x-x0)==size1)
		{x=x0;y0=y0+8;}
		y=y0;
	}
}


//x,y���������
//sizex,sizey,ͼƬ����
//BMP[]��Ҫд���ͼƬ����
//mode:0,��ɫ��ʾ;1,������ʾ
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 *BMP,u8 mode)
{
	u16 j=0;
	u8 i,n,temp,m;
	u8 x0=x,y0=y;
	sizey=sizey/8+((sizey%8)?1:0);
	for(n=0;n<sizey;n++)
	{
		 for(i=0;i<sizex;i++)
		 {
				temp=BMP[j];
				j++;
				for(m=0;m<8;m++)
				{
					if(temp&0x01)OLED_DrawPoint(x,y,mode);
					else OLED_DrawPoint(x,y,!mode);
					temp>>=1;
					y++;
				}
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y0=y0+8;
				}
				y=y0;
		}
	 }
}
//OLED�ĳ�ʼ��
void OLED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//??PORTB??
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	//GPIO?????
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//????
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//??
	GPIO_Init(GPIOB, &GPIO_InitStructure);//???

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);
	
	//HW_i2c????
	I2C_StructInit(&I2C_InitStructure);
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;//400Khz
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_OwnAddress1 = 0x77;//????????

	I2C_Init(I2C1, &I2C_InitStructure);
	I2C_Cmd(I2C1, ENABLE);
	
	delay_ms(200);
	
	WriteCmd(0xAE); /*display off*/
	WriteCmd(0x00); /*set lower column address*/ 
	WriteCmd(0x10); /*set higher column address*/
	WriteCmd(0x00); /*set display start line*/ 
	WriteCmd(0xB0); /*set page address*/ 
	WriteCmd(0x81); /*contrast control*/ 
	WriteCmd(0xff); /*255*/ 
	WriteCmd(0xA1); /*set segment remap*/ 
	WriteCmd(0xA6); /*normal / reverse*/ 
	WriteCmd(0xA8); /*multiplex ratio*/ 
	WriteCmd(0x1F); /*duty = 1/32*/ 
	WriteCmd(0xC8); /*Com scan direction*/ 
	WriteCmd(0xD3); /*set display offset*/ 
	WriteCmd(0x00); 
	WriteCmd(0xD5); /*set osc division*/ 
	WriteCmd(0x80); 
	WriteCmd(0xD9); /*set pre-charge period*/ 
	WriteCmd(0x1f); 
	WriteCmd(0xDA); /*set COM pins*/ 
	WriteCmd(0x00); 
	WriteCmd(0xdb); /*set vcomh*/ 
	WriteCmd(0x40); 
	WriteCmd(0x8d); /*set charge pump enable*/ 
	WriteCmd(0x14);
	OLED_Clear();
	WriteCmd(0xAF); /*display ON*/
}

