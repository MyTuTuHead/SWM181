/*
文件名：led.c
创建人：MiaoA
创建时间：2022/9/23
功能：点亮LED

修改日志：



现有问题：


*/


#include "led.h"




void Led_Init(void){

	GPIO_Init(LED1_PORT, LED1_PIN, GPIO_DIR_OUT, GPIO_PULL_UP_NOT, GPIO_PULL_DOWN_NOT, GPIO_OUT_PP);			//输出，接LED	
	GPIO_Init(LED2_PORT, LED2_PIN, GPIO_DIR_OUT, GPIO_PULL_UP_NOT, GPIO_PULL_DOWN_NOT, GPIO_OUT_PP);
	
	PDOUT_H(LED1_PIN);	//一亮一灭，布灵布灵
	PBOUT_L(LED2_PIN);

}



