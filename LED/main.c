/*
�ļ�����main.c
�����ˣ�MiaoA
����ʱ�䣺2022/9/23
���ܣ�����LED


�޸���־��
2022/9/25--->>����gpio.h


�������⣺


*/


#include "SWM181.h"
#include "gpio.h"
#include "led.h"


int main(void)
{	
	SystemInit();	
	Led_Init();
	SysTick_Config(SystemCoreClock/8);			//ÿ0.25���Ӵ���һ���ж�			
	PDOUT_H(LED1_PIN);
	PBOUT_L(LED2_PIN);
	while(1)
	{
	}
}
void SysTick_Handler(void)
{	
	PDOUT_T(LED1_PIN);	//��תLED����״̬
	PBOUT_T(LED2_PIN);
}

