/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/27
功能：ADC使用，连续采集模式，接在PWMO_CHB通道-PA8

修改日志：



现有问题：


*/

#include "SWM181.h"
#include "oled.h"
#include "delay.h"
#include "led.h"
#include "gpio.h"
#include "timer.h"
#include "pwm.h"
#include "adc.h"


int main(void)
{	
	SystemInit();	
	Led_Init();
	OLED_Init();			//初始化OLED  
	Pwm_Init();
	Adc_Init();

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_s(1);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_s(1);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	

	SysTick_Config(SystemCoreClock/8);			//每1/8秒钟触发一次中断,优先级-1级
	
	OLED_ShowString(16,0,"MiaoA",12);		//x,y:起点坐标 *chr:字符串起始地址  size1:字体大小 
	OLED_ShowString(16,16,"Adc_Val:",12);
	OLED_Refresh_Gram();								//刷新显示

	Tim_Init();//优先级2

	while(1)
	{
	}
}


