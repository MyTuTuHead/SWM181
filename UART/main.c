/*
�ļ�����main.c
�����ˣ�MiaoA
����ʱ�䣺2022/9/23
���ܣ�UARTͨ��
�����ļ�ģ������ҵ������ƣ�irq.c�ļ����ϵͳ�жϷ�����


�޸���־��
2022/9/24--->>ȥ��Fputc()�ض��庯��
							ԭ���ض���fputcʹ��printfʱ��Ҫ�����ַ���ӡ�����̹��ڷ���
							������Դ�ӡ����ʹ�� UART0_printf����������ʹ�÷�����printfһ��


�������⣺
2022/9/24--->>�ض���fputc������ʹ��printf�Ῠ��
							ԭ�������ʹ��printf������ȡ�ַ�����δ֪����


*/


#include "SWM181.h"
#include "uart.h"
#include "irq.h"


int main(void)
{	
	SystemInit();	
	Uart_Init(115200);
	UART0_printf("MiaoA");
	GPIO_Init(GPIOB, PIN8, 1, 0, 0, 0);			//�������LED
	GPIO_Init(GPIOD, PIN0, 1, 0, 0, 0);
	SysTick_Config(SystemCoreClock/8);			//ÿ1/8���Ӵ���һ���ж�			
	while(1)
	{
	}
}


void SysTick_Handler(void)
{	
	GPIO_InvBit(GPIOB, PIN8);	//��תLED����״̬
	GPIO_InvBit(GPIOD, PIN0);
}

