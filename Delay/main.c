/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/25
功能：延时


修改日志：
2022/9/26--->>修改延时时间不精准


现有问题：


*/


#include "SWM181.h"
#include "delay.h"
#include "led.h"
#include "gpio.h"

int main(void)
{	
	SystemInit();	
	Led_Init();
	
	PDOUT_H(LED1_PIN);
	PBOUT_L(LED2_PIN);
	delay_us(1);
	delay_ms(1);
	delay_s(1);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);
	delay_us(1);
	delay_ms(1);
	delay_s(1);

	PDOUT_T(LED1_PIN);
	PBOUT_T(LED2_PIN);

	SysTick_Config(SystemCoreClock/8);			//每1/8秒钟触发一次中断			
	while(1)
	{
	}
}
void SysTick_Handler(void)
{	
	PDOUT_T(LED1_PIN);
	PBOUT_T(LED2_PIN);
}

