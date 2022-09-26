/*
文件名：irq.c
创建人：MiaoA
创建时间：2022/9/23
功能：存放所有中断服务函数

修改日志：



现有问题：


*/

#include "irq.h"



void IRQ0_Handler(void){
	uint32_t chr;
	
	if(UART_INTRXThresholdStat(UART0)){             //RX FIFO溢出中断
		while(UART_IsRXFIFOEmpty(UART0) == 0){     //读取 RX FIFO不为0
			if(UART_ReadByte(UART0, &chr) == 0){

                if(UART0_RX_STA >= UART0_REC_LEN - 10)    //循环数据接收
                    UART0_RX_STA = 0;

                UART0_RX_BUF[UART0_RX_STA] = chr;
                UART0_RX_STA++;
								UART_WriteByte(UART0, chr);//回显
								GPIO_InvBit(GPIOD, PIN0);
			}
		}
	}
}



void SysTick_Handler(void)
{	
	PDOUT_T(LED1_PIN);
	PBOUT_T(LED2_PIN);
}

