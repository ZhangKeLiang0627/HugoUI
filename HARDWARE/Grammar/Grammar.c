#include "sys.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct
{
	unsigned char *name;	//用来存放汉字
}ChineseWord;

ChineseWord Chinese_v[] = {
"挽留","谙谴","泥塑","庇护","谋杀","转化","回顾","处理","发起","帮扶",
"孕育","打乱","杂糅","解构","歪曲","发表","跨越","斩断","尝试","服务",
"吸纳","呈现","抓取","阻止","桎梏","摆脱","提携","违背","诅咒","逮捕",
"睡","妨害","拯救","杀死","做","关心","缱绻","服从","讽刺","沉溺",
"遗留","按捺","淹没","期待","需要","谋杀","携带","揣摩","旁观","流淌",
"束缚","繁衍","枪毙","哭喊","去","怀念","喜欢","禁止","撕咬","践踏",
"改变","离开","想","记得","羡慕","解雇","回避","伪装","刺穿","乞求",
"等","写","当","和","与","说","烦恼","活","读","看",
"循环","推荐","矫正","思考","害怕","骗","遇见","喝","发现","教",
"学","走","过","进","去","取","拿","送","唱","欢呼",
"蹂躏","画","吃","发","打","穿","超越","打开","认可","暂停",
"赞同","经历","飞翔","坠落","复活","坐","说","愈合","满溢","裹挟",
//"喜欢""居住","发愁","继续","告诉","住","浮现","记得","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
};

ChineseWord Chinese_adj[] = {
"黏糊糊","深奥","斗争","伟大","不确定","非规则式","未来","恶臭","习惯性","犀利",
"普世","平衡","截肢","组织性","被保护","无尽","难以描述","紧密结合","可疑","冲动",
"七千个单位","唯一","高度成熟","基础","一针见血","无人知晓","形式主义","浅陋","她","二进制",
"拥挤不堪","腐烂","混乱","丑陋","滂沱","温暖","痉挛","笨拙","暗哑","残损",
"窒息","美丽","纯粹","瘫痪","沉默","缓慢","失速","他妈","抑郁","蓄意",
"温柔","堕落","戏剧性","肮脏","诡异","锋利","永不停歇","丰腴","流浪","忧郁",
"痛苦","枯萎","困倦","斑驳","狭隘","幽闭","年轻","出乎意料","残酷","重要",
"尴尬","幸运","严重","蹁跹","梦核","糟糕","多余","多语","赧赧","徜徉",
"丧","甜","颓废","过分","逼仄","腐烂","废弃","透明","亲爱","无头绪",
"兢兢业业","混沌","软软糯糯","昏昏沉沉","半梦半醒","隐晦","慵懒","文艺","有年代感","广袤无垠",
"炽热","上瘾","长","酷酷","一般般","恍惚","彷徨","庄严","松弛","独立",
//"理智","坦荡","揪心","逐渐","摇摆","勇敢","氤氲","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
};

ChineseWord Chinese_n[] = {
"态度","错觉","传说","社群","夸富宴","兔子","先辈平原","佛洛西斯","路怒","饥荒",
"革命","斐花","亚种","血肉","怪物","达达主义","黄昏","同性恋","华裔","伦理学",
"罪孽","权力","形式","后现代主义","传统","声音","错觉","牯岭街少年","恶性循环","殉情",
"失乐园","爱","纪念碑","锁","造物主","相对论","偶像崇拜","乌托邦","象牙塔","快乐",
"平克弗洛伊德","光","疾病","浪漫","妈妈","我","标点","自由","诗歌","你",
"证据","大雨","雏菊","人类","速度","灵魂","头发","心脏","灰雨","藤蔓",
"赤地荒野","眼睛","瞳孔","手掌","呼吸","诗云","佩索阿","宇宙","悲哀","树",
"晚风","睡莲","酒精","海波","海浪","春天","梦","月亮","太阳","呜咽",
"泪水","斑鸠","赛博朋克","世界","欲望","博尔赫斯","向日葵","白醋","野柚子","海豚",
"浴室","酶","荷花","命运","褶皱","朗姆酒","长岛冰茶","冰","泥土","蜘蛛",
"星空","闪电","桥","野餐","旧天堂","板栗","拥抱","月光","文字","人间",
"灯塔","孤雏","涟漪","岛屿","性交","贩卖机","日落","流氓","真理","多伦多",
"时钟","猫","烟火","茉莉","森林","蓝调","色","艳红","乳房","吻",
"耳朵","鱼缸","以太","人类","莉莉周","未来","青苹果","天台","虚空","青春",
"大阪","东京","名古屋","歌声","微笑","冬眠","洛丽塔","哥特","人","羊羔",
"自己","春光乍泄","高级感","友谊","小狗","坂本龙一","金汤力","我爱你","恋爱","迷幻乐",
"情书","眼神","发条橙","椅子","麦当劳","精神状态","林檎","情绪","前兆","白光",
"奈良美智","水星","月球","乐曲","蝴蝶","疫情","圣诞","眼睛","六月","二十七日",
"钢琴师","裸体","魔女","乌贼","身份","种族","国籍","祝福","苔藓","尤加利叶",
"薄荷","香草","生命","家","稻田","人生","意义","酒馆","行星","爵士乐",
"居酒屋","苏打","电车","再见","姐姐","人工智能","白痴","药","夜晚","喉咙",
"企鹅","艺伎","朝圣","学术放映","蓝蘑菇","花束","桔梗","巧克力","马克杯","脊柱",
"泉水","甲壳虫","躁郁症","LaLaLand","池袋","磁带","豆花","镣铐","迷宫","泰迪熊",
"杜松子","柠檬","别针","细胞","异地恋","尾巴","染色玻璃","雾气","彩虹","脚趾",
"避难所","教育","铁皮滑梯","曼哈顿","蓝色大门","故事","柯南","基德","胡安米罗","肌肤",
"身体","躯干","旧书店","地下铁","芥末味蚕豆","地平线","浓积云","我们","癔症","雪",
"龙血","独角兽羽毛","床","象限","楼梯","深圳大学","告白","可尔必思","瘟疫","灾难",
//"惘闻","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",
//"","","","","","","","","","",

};

ChineseWord Chinese_And[] = {
"和","与","跟","同","的",
};

ChineseWord Chinese_TrueFlase[] = {
"是","不是","不再是","不需要","就是没","是不是",
};

ChineseWord Chinese_Possible[] = {
"难道","真的","也许","或许","可能","一定","必须",

};

//unsigned char *Chinese_v = "谋杀";

/**
  * @brief 封面
  * @param  无
  * @retval 无
  */
void FrontCover(void)
{
	OLED_ShowString(0,0,"伪诗云",16,1);
	OLED_ShowString(24,16,"Designed by L",16,1);
	OLED_Refresh();
}



/**
  * @brief 按键随机选择语法
  * @param  无
  * @retval 无
  */
void Grammar_Chioce(void)
{
	uint16_t RDTempNum1 = 0;	//定义临时的随机数变量1
	RDTempNum1 = RandomCreate(); //用一个随机数来选择2个不同的语法
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
  * @param  无
  * @retval 无
  */
void Grammar1(void)
{
	uint8_t Row = 0;	//纵坐标y
	uint16_t RDTempNum1 = 0;	//定义临时的随机数变量1
	RDTempNum1 = RandomCreate(); 
	Time_ms ++;
	
	//这里虽然很复杂，疯狂套娃，但是生成随机数效果很好！也是没有办法的办法！
	RDNum1 = (uint16_t)RandomCreate() / 10;
	Time_ms ++;
	RDNum2 = (uint16_t)RandomCreateAgain(RDNum1 + Time_ms) / 10;
	Time_ms ++;
	RDNum3 = (uint16_t)RandomCreateAgain(RDNum2 + Time_ms) / 4;
	Time_ms ++;
	RDNum4 = (uint16_t)RandomCreateAgain(RDNum3 + Time_ms) / 4;
	Time_ms ++;
	
	OLED_ShowString(0, 0,"                                ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
	OLED_Refresh();

	if(RDTempNum1 >= 500) //加一个名词
	{
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum4].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum4].name)/2);
	}
	
	OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum1].name,16,1);
	
	LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum1].name)/2);	//取上一个打印在屏幕上的字符串的长度除以2再乘上16（除以2是因为一个汉字占2byte）
	
	if(LengthTemp > 128)	//自动换行
	{
		LengthTemp -= 128;
		Row += 16;
	}
	
	OLED_ShowString(LengthTemp, Row, Chinese_adj[RDNum2].name,16,1);
	
	LengthTemp +=  16 * (strlen((char *)Chinese_adj[RDNum2].name)/2);		//用strlen函数得出字符串的byte长度
	
	if(LengthTemp > 128)	//自动换行
	{
		LengthTemp -= 128;
		Row += 16;
	}

	OLED_ShowString(LengthTemp,Row,"的",16,1);
	
	LengthTemp += 16;
	
	if(LengthTemp > 128)
	{
		LengthTemp -= 128;
		Row += 16;
	}
	
	OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
	
	LengthTemp = 0;	

	OLED_Refresh();		//刷新oled
}


void Grammar_test(void)
{
	uint8_t i;
	uint8_t Row = 0;	//纵坐标y
	for(i = 0; i <= 1; i++)
	{
		OLED_ShowString(0,Row,Chinese_v[i].name,16,1);
		
		LengthTemp = 16 * (strlen((char *)Chinese_v[i].name)/2);	//取上一个打印在屏幕上的字符串的长度除以2再乘上16（除以2是因为一个汉字占2byte）
		
		OLED_ShowString(LengthTemp, Row, Chinese_adj[i].name,16,1);
		
		LengthTemp +=  16 * (strlen((char *)Chinese_adj[i].name)/2);
		
		if(LengthTemp > 128)
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,"的",16,1);
		
		if(LengthTemp > 128)
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		LengthTemp += 16;
		
		OLED_ShowString(LengthTemp, Row, Chinese_n[i].name,16,1);
		
		LengthTemp = 0;	
		Row = 0;	
		OLED_Refresh();		//刷新oled
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		OLED_ShowString(0, 0,"                               ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
		OLED_Refresh();
	}
}

/**
  * @brief n+和+n//n+是+n
  * @param  无
  * @retval 无
  */
void Grammar2(void)
{
	
		uint16_t RDTempNum1 = 0;	//定义临时的随机数变量1
		uint16_t RDTempNum2 = 0; //定义临时的随机数变量2
		RDTempNum1 = RandomCreate(); //用一个随机数来选择2个不同的语法
		Time_ms ++;
		RDTempNum2 = RandomCreateAgain(RDTempNum1 + Time_ms);
		Time_ms ++;
		
		if(RDTempNum1 >= 500)	//n+和+n
		{
			uint8_t Row = 0;	//纵坐标y
			
			//这里虽然很复杂，疯狂套娃，但是生成随机数效果很好！也是没有办法的办法！
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
			
			OLED_ShowString(0, 0,"                                ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
			OLED_Refresh();
			
			if(RDTempNum2 > 800)	//通过这里决定要不要加一个形容词
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			}
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_And[RDNum2].name,16,1);	
			LengthTemp +=  16 * (strlen((char *)Chinese_And[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			if(RDTempNum1 > 800)	//通过这里决定要不要加一个形容词
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum5].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum5].name)/2);
			}
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
			
			LengthTemp = 0;	
		
			OLED_Refresh();		//刷新oled
		}
		
		else//n+是+n
		{
			uint8_t Row = 0;	//纵坐标y
			
			//这里虽然很复杂，疯狂套娃，但是生成随机数效果很好！也是没有办法的办法！
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
			
			OLED_ShowString(0, 0,"                                ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
			OLED_Refresh();
			
			if(RDTempNum2 >= 800)	//通过这里决定要不要加一个形容词
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
				LengthTemp = 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			}
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_TrueFlase[RDNum2].name,16,1);	
			LengthTemp +=  16 * (strlen((char *)Chinese_TrueFlase[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			if(RDTempNum1 > 800)	//通过这里决定要不要加一个形容词
			{
				OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum5].name,16,1);
				LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum5].name)/2);
			}
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp, Row, Chinese_n[RDNum3].name,16,1);
			
			LengthTemp = 0;	
		
			OLED_Refresh();		//刷新oled
		}
}

/**
  * @brief 疑问句
  * @param  无
  * @retval 无
  */
void Grammar3(void)
{
	uint16_t RDTempNum1 = 0;	//定义临时的随机数变量1
	uint16_t RDTempNum2 = 0; //定义临时的随机数变量2
	RDTempNum1 = RandomCreate(); //用一个随机数来选择2个不同的语法
	Time_ms ++;
	RDTempNum2 = RandomCreateAgain(RDTempNum1 + Time_ms);
	Time_ms ++;
	
	if(RDTempNum1 >= 500)
	{
		uint8_t Row = 0;	//纵坐标y
			
		//这里虽然很复杂，疯狂套娃，但是生成随机数效果很好！也是没有办法的办法！
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
		
		OLED_ShowString(0, 0,"                                ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
		OLED_Refresh();
		
		OLED_ShowString(LengthTemp,Row,Chinese_Possible[RDNum1].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_Possible[RDNum1].name)/2);
		
		OLED_ShowString(LengthTemp,Row,"要",16,1);
		LengthTemp += 16;
		
		OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum2].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum2].name)/2);
		
		if(RDTempNum2 > 800)	//通过这里决定要不要加一个形容词
		{
			OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum4].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum4].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp,Row,"的",16,1);
			LengthTemp += 16;
		}
		
		if(LengthTemp > 128)	//自动换行//保险一点
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum3].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum3].name)/2);
		
		if(LengthTemp > 128)	//自动换行//保险一点
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,"吗",16,1);
		
		LengthTemp = 0;	
		
		OLED_Refresh();		//刷新oled
	}
	else
	{
		uint8_t Row = 0;	//纵坐标y
			
		//这里虽然很复杂，疯狂套娃，但是生成随机数效果很好！也是没有办法的办法！
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
		
		OLED_ShowString(0, 0,"                                ", 16, 1);		//清屏oled，我总感觉库函数里面那个clear函数太呆了
		OLED_Refresh();
		
		OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum1].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum1].name)/2);
		
		if(RDTempNum2 >= 400)
		{
			OLED_ShowString(LengthTemp,Row,Chinese_adj[RDNum2].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_adj[RDNum2].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
			
			OLED_ShowString(LengthTemp,Row,"地",16,1);
			LengthTemp += 16;
		}
		
		if(LengthTemp > 128)	//自动换行//保险一点
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		OLED_ShowString(LengthTemp,Row,Chinese_v[RDNum3].name,16,1);
		LengthTemp += 16 * (strlen((char *)Chinese_v[RDNum3].name)/2);
		
		if(LengthTemp > 128)	//自动换行//保险一点
		{
			LengthTemp -= 128;
			Row += 16;
		}
		
		if(RDTempNum1 >= 400)
		{
			OLED_ShowString(LengthTemp,Row,Chinese_n[RDNum4].name,16,1);
			LengthTemp += 16 * (strlen((char *)Chinese_n[RDNum4].name)/2);
			
			if(LengthTemp > 128)	//自动换行//保险一点
			{
				LengthTemp -= 128;
				Row += 16;
			}
		}
		
		OLED_ShowString(LengthTemp,Row,"了吗",16,1);
		
		LengthTemp = 0;	
		
		OLED_Refresh();		//刷新oled
	}
}














