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


现有问题：
2022/9/24--->>重定义fputc函数后，使用printf会卡死
							原因分析：使用printf函数读取字符长度未知导致


*/


#include "SWM181.h"
#include "uart.h"
#include "irq.h"


int main(void)
{	
	SystemInit();	
	Uart_Init(115200);
	UART0_printf("MiaoA");
	GPIO_Init(GPIOB, PIN8, 1, 0, 0, 0);			//输出，接LED
	GPIO_Init(GPIOD, PIN0, 1, 0, 0, 0);
	SysTick_Config(SystemCoreClock/8);			//每1/8秒钟触发一次中断			
	while(1)
	{
	}
}


void SysTick_Handler(void)
{	
	GPIO_InvBit(GPIOB, PIN8);	//反转LED亮灭状态
	GPIO_InvBit(GPIOD, PIN0);
}

