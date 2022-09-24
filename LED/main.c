#include "SWM181.h"
int main(void)
{	
	SystemInit();	
	GPIO_Init(GPIOD, PIN0, 1, 0, 0, 0);			//输出，接LED	
	GPIO_Init(GPIOB, PIN8, 1, 0, 0, 0);
	SysTick_Config(SystemCoreClock/8);			//每0.25秒钟触发一次中断			
	while(1)
	{
	}
}
void SysTick_Handler(void)
{	
	GPIO_InvBit(GPIOD, PIN0);	//反转LED亮灭状态
	GPIO_InvBit(GPIOB, PIN8);
}

