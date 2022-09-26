/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/26
功能：定时器使用，板载绿色LED亮灭

修改日志：



现有问题：


*/

#include "SWM181.h"
#include "oled.h"
#include "delay.h"
#include "led.h"
#include "gpio.h"
#include "timer.h"

int main(void)
{	
	SystemInit();	
	Led_Init();
	OLED_Init();			//初始化OLED  
	Tim_Init();

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_s(1);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_s(1);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	

	SysTick_Config(SystemCoreClock/8);			//每1/8秒钟触发一次中断
	
	OLED_ShowString(16,0,"MiaoA",12);		//x,y:起点坐标 *chr:字符串起始地址  size1:字体大小 
	OLED_Refresh_Gram();								//刷新显示
	while(1)
	{
	}
}


