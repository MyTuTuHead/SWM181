/*
文件名：gpio.h
创建人：MiaoA
创建时间：2022/9/25
功能：该文件无功能，在配置GPIO时应用该文件，可提高代码阅读性


修改日志：



现有问题：


*/


#ifndef __GPIO_H_
#define __GPIO_H_

#include "SWM181.h"



#define GPIO_DIR_OUT	1		//输出模式
#define GPIO_DIR_IN		0		//输入模式

#define GPIO_PULL_UP			1		//有上拉电阻
#define GPIO_PULL_UP_NOT	0		//无下拉电阻

#define GPIO_PULL_DOWN			1		//有下拉电阻
#define GPIO_PULL_DOWN_NOT	0		//无下拉电阻

#define GPIO_OUT_OD			1		//开漏输出
#define GPIO_OUT_PP			0		//推挽输出



#define PAOUT_H(pin)	GPIO_SetBit(GPIOA, (pin))	//高电平输出
#define PBOUT_H(pin)	GPIO_SetBit(GPIOB, (pin))
#define PCOUT_H(pin)	GPIO_SetBit(GPIOC, (pin))
#define PDOUT_H(pin)	GPIO_SetBit(GPIOD, (pin))
#define PEOUT_H(pin)	GPIO_SetBit(GPIOE, (pin))

#define PAOUT_L(pin)	GPIO_ClrBit(GPIOA, (pin))	//低电平输出
#define PBOUT_L(pin)	GPIO_ClrBit(GPIOB, (pin))
#define PCOUT_L(pin)	GPIO_ClrBit(GPIOC, (pin))
#define PDOUT_L(pin)	GPIO_ClrBit(GPIOD, (pin))
#define PEOUT_L(pin)	GPIO_ClrBit(GPIOE, (pin))

#define PAOUT_T(pin)	GPIO_InvBit(GPIOA, (pin))	//电平反转
#define PBOUT_T(pin)	GPIO_InvBit(GPIOB, (pin))
#define PCOUT_T(pin)	GPIO_InvBit(GPIOC, (pin))
#define PDOUT_T(pin)	GPIO_InvBit(GPIOD, (pin))
#define PEOUT_T(pin)	GPIO_InvBit(GPIOE, (pin))

#define PA_READ(pin)	GPIO_GetBit(GPIOA, (pin))	//读取电平值
#define PB_READ(pin)	GPIO_GetBit(GPIOB, (pin))
#define PC_READ(pin)	GPIO_GetBit(GPIOC, (pin))
#define PD_READ(pin)	GPIO_GetBit(GPIOD, (pin))
#define PE_READ(pin)	GPIO_GetBit(GPIOA, (pin))

#endif


