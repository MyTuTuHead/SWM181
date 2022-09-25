/*
文件名：delay.c
创建人：MiaoA
创建时间：2022/9/25
功能：延时

修改日志：



现有问题：


*/


#include "delay.h"


//输入	定时US
//输出	无
uint8_t delay_us(uint32_t us){								//uS微秒级延时程序
	 if ((us - 1UL) > SysTick_LOAD_RELOAD_Msk)
    return 1;                                                

	SysTick->LOAD=SystemCoreClock*us;      	//重装计数初值	systick系统时钟SystemCoreClock使用内部高速时钟
																					//如要修改，可在system_SWM181.C中修改
	SysTick->VAL=0x00;        							//清空定时器的计数器
	SysTick->CTRL=0x00000005;								//时钟源HCLK，打开定时器
	while(!(SysTick->CTRL&0x00010000)); 		//等待计数到0
	SysTick->CTRL=0x00000004;								//关闭定时器
	
	return 0;
}

void delay_ms(uint16_t ms){ 							//mS毫秒级延时程序（参考值即是延时数，最大值65535）	 		  	  
	while( ms-- != 0){
		delay_us(1000);												//调用1000微秒的延时
	}
}
 
void delay_s(uint16_t s){ 								//S秒级延时程序（参考值即是延时数，最大值65535）	 		  	  
	while( s-- != 0){
		delay_ms(1000);												//调用1000毫秒的延时
	}
} 
