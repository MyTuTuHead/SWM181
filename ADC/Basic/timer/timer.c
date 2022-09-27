/*
文件名：timer.c
创建人：MiaoA
创建时间：2022/9/26
功能：定时器使用


修改日志：


现有问题：


*/


#include "timer.h"



void Tim_Init(void){
	//定时器初始化	定时器0	定时模式			定时80ms		开启中断
	TIMR_Init(TIMR0, TIMR_MODE_TIMER, TIM_MS(80),TIM_IRQ_ENABLE);
	//中断线绑定		定时器0中断绑定在 中断线5	优先级 2
	IRQ_Connect(IRQ0_15_TIMR0, TIM_IRQ_LINE, 2);

	TIMR_Start(TIMR0);	//开启定时器
}

