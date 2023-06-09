#ifndef __HUGOUI_USER_H
#define __HUGOUI_USER_H

#include "oled.h"
#include "OLED_User.h"
#include "Hugo_UI.h"
#include "stm32f4xx.h"

/* 声明全局变量 */
extern uint8_t* Switch_space[];

/**
*    @变量组 *Slide_space[]
*    @brief 滑动条控件 用于存储滑动条控件的值
*    @param none
*    
*    @注册
*        -0->屏幕亮度
*        -1->单选框测试
*        -2->选项条固定长度
*/
enum Slide_space_Obj
{
    Slide_space_ScreenBrightness = 0,
    Slide_space_Scroll,
    Slide_space_val1,
    Slide_space_val2,
    Slide_space_val3,
    Slide_space_Volume_Ctrl,

    Slide_space_Obj_Max, // 标记成最大值

};

/**
*    @变量组 *Switch_space[]
*    @brief 开关控件 用于存储开关控件的值
*    @param none
*    
*    @注册
*        -0->平滑动画
*        -1->单选框测试
*        -2->选项条固定长度
*/
enum Switch_space_Obj
{
    SwitchSpace_SmoothAnimation = 0, // 缓动动画flag需要在HugoUI_Control中使用，建议不要改动！（don't change this one!!!）
    SwitchSpace_OptionStripFixedLength,
    CheckBox1,
    CheckBox2,
    CheckBox3,
    Switch1,
    Switch2,
    Switch3,
    BeeperEnableConfig,
    PageOnlyListModeConfig,
    ListShowMode1,
    ListShowMode2,

};

void HugoUI_InitLayout(void);

/* Event */
void EventUpdateOledLightLevel(void);
void EventBeeperEnableConfig(void);
void EventBeeperVolumeControl(void);
void EventChangeListMode1(void);
void EventChangeListMode2(void);

void EventShowGyroUI(void);
#endif
