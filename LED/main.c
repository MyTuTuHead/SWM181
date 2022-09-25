/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/23
功能：点亮LED


修改日志：
2022/9/25--->>加入gpio.h


现有问题：


*/


#include "SWM181.h"
#include "gpio.h"
#include "led.h"


int main(void)
{	
	SystemInit();	
	Led_Init();
	SysTick_Config(SystemCoreClock/8);			//每0.25秒钟触发一次中断			
	PDOUT_H(LED1_PIN);
	PBOUT_L(LED2_PIN);
	while(1)
	{
	}
}
void SysTick_Handler(void)
{	
	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);
}

