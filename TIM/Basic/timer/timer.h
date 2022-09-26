/*
文件名：timer.h
创建人：MiaoA
创建时间：2022/9/23
功能：定时器使用，板载绿色LED亮灭

修改日志：



现有问题：


*/
#ifndef __TIMER_H
#define __TIMER_H

#include "SWM181.h"
#include "SWM181_irqmux.h"
#include "SWM181_timr.h"
#include "irq.h"


#define CyclesPerMs (CyclesPerUs * 1000)
#define TIM_IRQ_ENABLE		1
#define TIM_IRQ_DISENABLE	0


#define TIM_US(us) (CyclesPerUs * (us))
#define TIM_MS(ms) (CyclesPerMs * (ms))
#define TIM_S(s) 	 (SystemCoreClock * (s))

void Tim_Init(void);


#endif

