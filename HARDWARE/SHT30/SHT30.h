#ifndef __SHT30_H__
#define __SHT30_H__

#include "delay.h"
#include "sys.h"



extern u8 Humiture_buff[20];
void SHT30_Read_Value(u8 addr);

void SHT30_Read_ValueOut(u8 addr, float *Get_temperature, float *Get_Humidity);







#endif



