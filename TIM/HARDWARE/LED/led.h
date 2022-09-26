/*
文件名：led.h
创建人：MiaoA
创建时间：2022/9/23
功能：点亮LED

修改日志：



现有问题：


*/

#ifndef __LED_H
#define __LED_H 

#include "SWM181.h"
#include "gpio.h"



#define LED1_PORT 	GPIOD
#define LED1_PIN		PIN0


#define LED2_PORT 	GPIOB
#define LED2_PIN		PIN8

#define LED3_PORT		GPIOB
#define LED3_PIN		PIN9	


void Led_Init(void);


#endif

