/*
文件名：pwm.h
创建人：MiaoA
创建时间：2022/9/26
功能：PWM功能，板载绿色LED呼吸灯

修改日志：



现有问题：


*/
#ifndef __PWM_H
#define __PWM_H

#include "SWM181.h"
#include "SWM181_irqmux.h"
#include "SWM181_pwm.h"
#include "irq.h"
#include <math.h>
#include <stdlib.h>



//#define Auto_Calculation	//PWM分频因子自动计算,屏蔽则表示不开启,暂不可使用，功能不完善

#ifdef Auto_Calculation
typedef struct{
	uint32_t pwm_div;
	uint32_t	n;
}Auto_Cal;

uint8_t Pwm_Div(uint32_t hz);

#endif

#define DUTY(n)	( (300) / 100 * n)		//占空比计算，需手动将PWM初始化时 Pwm_InitStruct.cycleA 放入括号中

void Pwm_Init(void);

#endif

