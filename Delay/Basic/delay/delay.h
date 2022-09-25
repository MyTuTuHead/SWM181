/*
文件名：delay.h
创建人：MiaoA
创建时间：2022/9/25
功能：延时

修改日志：



现有问题：


*/

#ifndef __DELAY_H
#define __DELAY_H 

#include "SWM181.h"




uint8_t delay_us(uint32_t us);//uS微秒级延时程序
void delay_ms(uint16_t ms);
void delay_s(uint16_t s);






#endif

