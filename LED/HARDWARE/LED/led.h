/*
�ļ�����led.h
�����ˣ�MiaoA
����ʱ�䣺2022/9/23
���ܣ�����LED

�޸���־��



�������⣺


*/

#ifndef __DELAY_H
#define __DELAY_H 

#include "SWM181.h"
#include "gpio.h"



#define LED1_PORT 	GPIOD
#define LED1_PIN		 PIN0


#define LED2_PORT 	GPIOB
#define LED2_PIN		 PIN8

void Led_Init(void);


#endif

