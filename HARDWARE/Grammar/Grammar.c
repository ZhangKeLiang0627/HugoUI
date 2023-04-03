#include "sys.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct
{
	unsigned char *name;	//������ź���
}ChineseWord;

ChineseWord Chinese_v[] = {
"����","��Ǵ","����","�ӻ�","ıɱ","ת��","�ع�","����","����","���",
"����","����","����","�⹹","����","����","��Խ","ն��","����","����",
"����","����","ץȡ","��ֹ","����","����","��Я","Υ��","����","����",
"˯","����","����","ɱ��","��","����","���","����","���","����",
"����","����","��û","�ڴ�","��Ҫ","ıɱ","Я��","��Ħ","�Թ�","����",
"����","����","ǹ��","�޺�","ȥ","����","ϲ��","��ֹ","˺ҧ","��̤",
"�ı�","�뿪","��","�ǵ�","��Ľ","���","�ر�","αװ","�̴�","����",
"��","д","��","��","��","˵","����","��","��","��",
"ѭ��","�Ƽ�","����","˼��","����","ƭ","����","��","����","��",
"ѧ","��","��","��","ȥ","ȡ","��","��","��","����",
"����","��","��","��","��","��","��Խ","��","�Ͽ�","��ͣ",
"��ͬ","����","����","׹��","����","��","˵","����","����","��Ю",
//"ϲ��""��ס","����","����","����","ס","����","�ǵ�","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
};

ChineseWord Chinese_adj[] = {
"����","���","����","ΰ��","��ȷ��","�ǹ���ʽ","δ��","���","ϰ����","Ϭ��",
"����","ƽ��","��֫","��֯��","������","�޾�","��������","���ܽ��","����","�嶯",
"��ǧ����λ","Ψһ","�߶ȳ���","����","һ���Ѫ","����֪��","��ʽ����","ǳª","��","������",
"ӵ������","����","����","��ª","����","��ů","����","��׾","����","����",
"��Ϣ","����","����","̱��","��Ĭ","����","ʧ��","����","����","����",
"����","����","Ϸ����","����","����","����","����ͣЪ","����","����","����",
"ʹ��","��ή","����","�߲�","����","�ı�","����","��������","�п�","��Ҫ",
"����","����","����","����","�κ�","���","����","����","����","����",
"ɥ","��","�Ƿ�","����","����","����","����","͸��","�װ�","��ͷ��",
"����ҵҵ","����","����ŴŴ","������","���ΰ���","����","���","����","�������","��������",
"����","���","��","���","һ���","���","����","ׯ��","�ɳ�","����",
//"����","̹��","����","��","ҡ��","�¸�","��","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
};

ChineseWord Chinese_n[] = {
"̬��","���","��˵","��Ⱥ","�主��","����","�ȱ�ƽԭ","������˹","·ŭ","����",
"����","쳻�","����","Ѫ��","����","�������","�ƻ�","ͬ����","����","����ѧ",
"����","Ȩ��","��ʽ","���ִ�����","��ͳ","����","���","���������","����ѭ��","ѳ��",
"ʧ��԰","��","���","��","������","�����","ż����","���а�","������","����",
"ƽ�˸�������","��","����","����","����","��","���","����","ʫ��","��",
"֤��","����","����","����","�ٶ�","���","ͷ��","����","����","����",
"��ػ�Ұ","�۾�","ͫ��","����","����","ʫ��","������","����","����","��",
"���","˯��","�ƾ�","����","����","����","��","����","̫��","����",
"��ˮ","���","�������","����","����","������˹","���տ�","�״�","Ұ����","����",
"ԡ��","ø","�ɻ�","����","����","��ķ��","��������","��","����","֩��",
"�ǿ�","����","��","Ұ��","������","����","ӵ��","�¹�","����","�˼�",
"����","�³�","����","����","�Խ�","������","����","��å","����","���׶�",
"ʱ��","è","�̻�","����","ɭ��","����","ɫ","�޺�","�鷿","��",
"����","���","��̫","����","������","δ��","��ƻ��","��̨","���","�ഺ",
"����","����","������","����","΢Ц","����","������","����","��","���",
"�Լ�","����էй","�߼���","����","С��","�౾��һ","������","�Ұ���","����","�Ի���",
"����","����","������","����","����","����״̬","����","����","ǰ��","�׹�",
"��������","ˮ��","����","����","����","����","ʥ��","�۾�","����","��ʮ����",
"����ʦ","����","ħŮ","����","���","����","����","ף��","̦޺","�ȼ���Ҷ",
"����","���","����","��","����","����","����","�ƹ�","����","��ʿ��",
"�Ӿ���","�մ�","�糵","�ټ�","���","�˹�����","�׳�","ҩ","ҹ��","����",
"���","�ռ�","��ʥ","ѧ����ӳ","��Ģ��","����","�۹�","�ɿ���","��˱�","����",
"Ȫˮ","�׿ǳ�","����֢","LaLaLand","�ش�","�Ŵ�","����","����","�Թ�","̩����",
"������","����","����","ϸ��","�����","β��","Ⱦɫ����","����","�ʺ�","��ֺ",
"������","����","��Ƥ����","������","��ɫ����","����","����","����","��������","����",
"����","����","�����","������","��ĩζ�϶�","��ƽ��","Ũ����","����","�֢","ѩ",
"��Ѫ","��������ë","��","����","¥��","���ڴ�ѧ","���","�ɶ���˼","����","����",
//"���","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",

};

ChineseWord Chinese_And[] = {
"��","��","��","ͬ","��",
};

ChineseWord Chinese_TrueFlase[] = {
"��","����","������","����Ҫ","����û","�ǲ���",
};

ChineseWord Chinese_Possible[] = {
"�ѵ�","���","Ҳ��","����","����","һ��","����",

};

//unsigned char *Chinese_v = "ıɱ";

/**
  * @brief ����
  * @param  ��
  * @retval ��
  */
void FrontCover(void)
{
	OLED_ShowString(0,0,"αʫ��",16,1);
	OLED_ShowString(24,16,"Designed by L",16,1);
	OLED_Refresh();
}



/**
  * @brief �������ѡ���﷨
  * @param  ��
  * @retval ��
  */
void Grammar_Chioce(void)
{
	uint16_t RDTempNum1 = 0;	//������ʱ�����������1
	RDTempNum1 = RandomCreate(); //��һ���������ѡ��2����ͬ���﷨
	Time_ms ++;
	if(KeyNum == 1)
	{
		if(RDTempNum1 >= 666)
		{
			Grammar1();
		}
		else if(RDTempNum1 >= 333 && RDTempNum1 < 666)
		{
			Grammar2();
		}
		else
		{
			Grammar3();
		}
	}
}

/**
  * @brief v+adj+n
  * @param  ��
  * @retval ��
  */
void Grammar1(void)
{
	uint8_t Row = 0;	//������y
	uint16_t RDTempNum1 = 0;	//������ʱ�����������1
	RDTempNum1 = RandomCreate(); 
	Time_ms ++;
	
	//������Ȼ�ܸ��ӣ�������ޣ��������������Ч���ܺã�Ҳ��û�а취�İ취��
	RDNum1 = (uint16_t)RandomCreate() / 10;
	Time_ms ++;
	RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 10;
	Time_ms ++;
	RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 4;
	Time_ms ++;
	RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 4;
	Time_ms ++;
	
	OLED_ShowString(0, 0,"                                ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
	OLED_Refresh();

	if(RDTempNum1 >= 500) //��һ������
	{
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum4].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum4].name)/2);
	}
	
	OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum1].name,16,1);
	
	LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum1].name)/2);	//ȡ��һ����ӡ����Ļ�ϵ��ַ����ĳ��ȳ���2�ٳ���16������2����Ϊһ������ռ2byte��
	
	if(LengthTemp > 128)	//�Զ�����
	{
		LengthTemp -= 128;
		Row += 16;
	}
	
	OLED_ShowString(LengthTemp, Row, Chinese_adj[RDNum2].name,16,1);
	
	LengthTemp +=  16 * (strlen((char *)Chinese_adj[RDNum2].name)/2);		//��strlen�����ó��ַ�����byte����
	
	if(LengthTemp > 128)	//�Զ�����
	{
		LengthTemp -= 128;
		Row += 16;
	}

	OLED_ShowString(LengthTemp,Row,"��",16,1);
	
	LengthTemp += 16;
	
	if(LengthTemp > 128)
	{
		LengthTemp -= 128;
		Row += 16;
	}
	
	OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
	
	LengthTemp = 0;	

	OLED_Refresh();		//ˢ��oled
}


void Grammar_test(void)
{
	uint8_t i;
	uint8_t Row = 0;	//������y
	for(i = 0; i <= 1; i++)
	{
		OLED_ShowString(0,Row,Chinese_v[i].name,16,1);
		
		LengthTemp = 16 * (strlen((char *)Chinese_v[i].name)/2);	//ȡ��һ����ӡ����Ļ�ϵ��ַ����ĳ��ȳ���2�ٳ���16������2����Ϊһ������ռ2byte��
		
		OLED_ShowString(LengthTemp, Row, Chinese_adj[i].name,16,1);
		
		LengthTemp +=  16 * (strlen((char *)Chinese_adj[i].name)/2);
		
		if(LengthTemp > 128)
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,"��",16,1);
		
		if(LengthTemp > 128)
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		LengthTemp += 16;
		
		OLED_ShowString(LengthTemp, Row, Chinese_n[i].name,16,1);
		
		LengthTemp = 0;	
		Row = 0;	
		OLED_Refresh();		//ˢ��oled
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		OLED_ShowString(0, 0,"                               ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
		OLED_Refresh();
	}
}

/**
  * @brief n+��+n//n+��+n
  * @param  ��
  * @retval ��
  */
void Grammar2(void)
{
	
		uint16_t RDTempNum1 = 0;	//������ʱ�����������1
		uint16_t RDTempNum2 = 0; //������ʱ�����������2
		RDTempNum1 = RandomCreate(); //��һ���������ѡ��2����ͬ���﷨
		Time_ms ++;
		RDTempNum2 = RandomCreateAgain(RDTempNum1 + Time_ms);
		Time_ms ++;
		
		if(RDTempNum1 >= 500)	//n+��+n
		{
			uint8_t Row = 0;	//������y
			
			//������Ȼ�ܸ��ӣ�������ޣ��������������Ч���ܺã�Ҳ��û�а취�İ취��
			RDNum1 = (uint16_t)RandomCreate() / 4;
			Time_ms ++;
			RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 200;
			Time_ms ++;
			RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 4;
			Time_ms ++;
			RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 10;
			Time_ms ++;
			RDNum5 = (uint16_t)RandomCreateAgain(RDNum4 + Time_ms) / 10;
			Time_ms ++;
			
			OLED_ShowString(0, 0,"                                ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
			OLED_Refresh();
			
			if(RDTempNum2 > 800)	//ͨ���������Ҫ��Ҫ��һ�����ݴ�
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			}
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_And[RDNum2].name,16,1);	
			LengthTemp +=  16 * (strlen((char *)Chinese_And[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			if(RDTempNum1 > 800)	//ͨ���������Ҫ��Ҫ��һ�����ݴ�
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum5].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum5].name)/2);
			}
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
			
			LengthTemp = 0;	
		
			OLED_Refresh();		//ˢ��oled
		}
		
		else//n+��+n
		{
			uint8_t Row = 0;	//������y
			
			//������Ȼ�ܸ��ӣ�������ޣ��������������Ч���ܺã�Ҳ��û�а취�İ취��
			RDNum1 = (uint16_t)RandomCreate() / 4;
			Time_ms ++;
			RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 166;
			Time_ms ++;
			RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 4;
			Time_ms ++;
			RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 10;
			Time_ms ++;
			RDNum5 = (uint16_t)RandomCreateAgain(RDNum4 + Time_ms) / 10;
			Time_ms ++;
			
			OLED_ShowString(0, 0,"                                ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
			OLED_Refresh();
			
			if(RDTempNum2 >= 800)	//ͨ���������Ҫ��Ҫ��һ�����ݴ�
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
				LengthTemp = 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			}
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_TrueFlase[RDNum2].name,16,1);	
			LengthTemp +=  16 * (strlen((char *)Chinese_TrueFlase[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			if(RDTempNum1 > 800)	//ͨ���������Ҫ��Ҫ��һ�����ݴ�
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum5].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum5].name)/2);
			}
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
			
			LengthTemp = 0;	
		
			OLED_Refresh();		//ˢ��oled
		}
}

/**
  * @brief ���ʾ�
  * @param  ��
  * @retval ��
  */
void Grammar3(void)
{
	uint16_t RDTempNum1 = 0;	//������ʱ�����������1
	uint16_t RDTempNum2 = 0; //������ʱ�����������2
	RDTempNum1 = RandomCreate(); //��һ���������ѡ��2����ͬ���﷨
	Time_ms ++;
	RDTempNum2 = RandomCreateAgain(RDTempNum1 + Time_ms);
	Time_ms ++;
	
	if(RDTempNum1 >= 500)
	{
		uint8_t Row = 0;	//������y
			
		//������Ȼ�ܸ��ӣ�������ޣ��������������Ч���ܺã�Ҳ��û�а취�İ취��
		RDNum1 = (uint16_t)RandomCreate() / 142;
		Time_ms ++;
		RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 10;
		Time_ms ++;
		RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 4;
		Time_ms ++;
		RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 10;
		Time_ms ++;
		RDNum5 = (uint16_t)RandomCreateAgain(RDNum4 + Time_ms) / 10;
		Time_ms ++;
		
		OLED_ShowString(0, 0,"                                ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
		OLED_Refresh();
		
		OLED_ShowString(LengthTemp,Row,Chinese_Possible[RDNum1].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_Possible[RDNum1].name)/2);
		
		OLED_ShowString(LengthTemp,Row,"Ҫ",16,1);
		LengthTemp += 16;
		
		OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum2].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum2].name)/2);
		
		if(RDTempNum2 > 800)	//ͨ���������Ҫ��Ҫ��һ�����ݴ�
		{
			OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp,Row,"��",16,1);
			LengthTemp += 16;
		}
		
		if(LengthTemp > 128)	//�Զ�����//����һ��
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum3].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum3].name)/2);
		
		if(LengthTemp > 128)	//�Զ�����//����һ��
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,"��",16,1);
		
		LengthTemp = 0;	
		
		OLED_Refresh();		//ˢ��oled
	}
	else
	{
		uint8_t Row = 0;	//������y
			
		//������Ȼ�ܸ��ӣ�������ޣ��������������Ч���ܺã�Ҳ��û�а취�İ취��
		RDNum1 = (uint16_t)RandomCreate() / 4;
		Time_ms ++;
		RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 10;
		Time_ms ++;
		RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 10;
		Time_ms ++;
		RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 4;
		Time_ms ++;
		RDNum5 = (uint16_t)RandomCreateAgain(RDNum4 + Time_ms) / 4;
		Time_ms ++;
		
		OLED_ShowString(0, 0,"                                ", 16, 1);		//����oled�����ܸо��⺯�������Ǹ�clear����̫����
		OLED_Refresh();
		
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
		
		if(RDTempNum2 >= 400)
		{
			OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum2].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp,Row,"��",16,1);
			LengthTemp += 16;
		}
		
		if(LengthTemp > 128)	//�Զ�����//����һ��
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum3].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum3].name)/2);
		
		if(LengthTemp > 128)	//�Զ�����//����һ��
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		if(RDTempNum1 >= 400)
		{
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum4].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum4].name)/2);
			
			if(LengthTemp > 128)	//�Զ�����//����һ��
			{
				LengthTemp -= 128;
				Row += 16;
			}
		}
		
		OLED_ShowString(LengthTemp,Row,"����",16,1);
		
		LengthTemp = 0;	
		
		OLED_Refresh();		//ˢ��oled
	}
}














