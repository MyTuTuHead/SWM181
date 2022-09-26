/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/23
功能：UART通信
函数文件模板和洋桃电子类似，irq.c文件存放系统中断服务函数


修改日志：
2022/9/24--->>去除Fputc()重定义函数
							原因：重定义fputc使用printf时需要单个字符打印，过程过于繁琐
							如需调试打印，请使用 UART0_printf（）函数，使用方法和printf一致
2022/9/26--->>加入gpio.h


现有问题：
2022/9/24--->>重定义fputc函数后，使用printf会卡死
							原因分析：使用printf函数读取字符长度未知导致


*/


#include "SWM181.h"
#include "uart.h"
#include "irq.h"
#include "gpio.h"
#include "led.h"

int main(void)
{	
	SystemInit();	
	Uart_Init(115200);
	UART0_printf("MiaoA");
	Led_Init();
	PDOUT_H(LED1_PIN);//一亮一灭，布灵布灵
	PBOUT_L(LED2_PIN);

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

