#ifndef __OLED_USER_H
#define __OLED_USER_H

#include "stm32f4xx.h" 

/*u8g2_SetDrawColor param*/
#define NORMAL  1
#define XOR     2

/* API */
void Oled_u8g2_ShowFloat(uint16_t x, uint16_t y, float dat, uint8_t num, uint8_t pointNum);
void Oled_u8g2_ShowStr(uint16_t x, uint16_t y, char *str);
void Oled_u8g2_DrawPoint(uint16_t x, uint16_t y);
void Oled_u8g2_DrawBox(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void Oled_u8g2_DrawFrame(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void Oled_u8g2_DrawRFrame(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t r);
void Oled_u8g2_DrawRBox(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t r);
void Oled_u8g2_ClearBuffer(void);
void Oled_u8g2_SendBuffer(void);
void Oled_u8g2_SetDrawColor(uint8_t mode);
void Oled_u8g2_ShowBMP(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *pic);
void Oled_u8g2_ModifyColor(uint8_t mode);
uint32_t Oled_u8g2_Get_UTF8_ASCII_PixLen(char* s);
void Oled_u8g2_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
uint16_t Oled_u8g2_GetBufferTilHeight(void);
uint16_t Oled_u8g2_GetBufferTileWidth(void);
uint8_t* Oled_u8g2_GetBufferPtr(void);

/* Event */
void Oled_EventUpdateOledLightLevel(void);


#endif
