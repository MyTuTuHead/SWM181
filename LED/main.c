#include "SWM181.h"
int main(void)
{	
	SystemInit();	
	GPIO_Init(GPIOD, PIN0, 1, 0, 0, 0);			//�������LED	
	GPIO_Init(GPIOB, PIN8, 1, 0, 0, 0);
	SysTick_Config(SystemCoreClock/8);			//ÿ0.25���Ӵ���һ���ж�			
	while(1)
	{
	}
}
void SysTick_Handler(void)
{	
	GPIO_InvBit(GPIOD, PIN0);	//��תLED����״̬
	GPIO_InvBit(GPIOB, PIN8);
}

