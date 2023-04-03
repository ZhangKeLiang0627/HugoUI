#include "sys.h"
#include "SHT30.h"
#include "BEEPER.h"
#include "u8g2.h"
#include "u8g2_Init.h"
#include "OLED_User.h"
#include "Hugo_UI.h"
#include "malloc.h"
#include "Encoder.h"
#include "HugoUI_User.h"

unsigned char i = 0, j = 0, n, m;
unsigned char LengthTemp = 0;	
uint8_t KeyNum;	
uint8_t EncoderNum;			
uint16_t RDNum1 = 0, RDNum2 = 0, RDNum3 = 0,
RDNum4 = 0, RDNum5 = 0, RDNum6 = 0;	

extern u8 mpu6050_set_flag;
extern u8 sht30_set_flag;
u8g2_t u8g2;	


int main(void)
{ 
	// u8 res;
	
	Key_A0.LongPressOpen_Flag = 1;
	Key_A0.DoublePressOpen_Flag = 0;
	
	delay_init();
 	OLED_Init();				
	Encoder_Init();
	my_mem_init(SRAMIN);

	uart_init(115200);
	
	Key_Init();
	
	TIM4_Random_Init(10000 - 1, 10 - 1);
	
	// res = MPU_Init();
	// printf("MPU_Init = %d\r\n", res);
	
	// res = mpu_dmp_init();
	// printf("mpu_dmp_Init = %d\r\n", res);
	
	Beeper_Init();
	
	u8g2Init(&u8g2); 
	
	u8g2_SetFont(&u8g2,u8g2_font_profont15_mr);


	HugoUI_InitLayout();


	while(1) 
	{
		
		KeyNum = Key_GetNum();
		EncoderNum = Encoder_GetNum();

		// if(KeyNum == 3)
		// {
		// 	Beeper_Perform(BEEPER_WARNING);			
			
		// 	printf("keypress!!!!!!\r\n\r\n\r\n");

		// }

		// if(KeyNum == 2)
		// {
		// 	Beeper_Perform(BEEPER_TRITONE);			
			
		// 	printf("keypress!!!!!!\r\n\r\n\r\n");

		// }

		// if(KeyNum == 1)
		// {
		// 	Beeper_Perform(BEEPER_KEYPRESS);			
			
		// 	printf("keypress!!!!!!\r\n\r\n\r\n");

		// }

		// if(sht30_set_flag)
		// {
		// 	sht30_set_flag = 0;
		// 	// SHT30_Read_Value(0x44);
			
		// }
		
		// if(mpu6050_set_flag)
		// {
		// 	mpu6050_set_flag = 0;
		// 	mpu_dmp_get_data(&pitch,&roll,&yaw);
		// 	// printf("pitch = %.1f ", pitch);
		// 	// printf("roll = %.1f ", roll);
		// 	// printf("yaw = %.1f\r\n", yaw);
		// }
		
		HugoUI_System();

		
		
	}
}



