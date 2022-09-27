/*
文件名：uart.h
创建人：MiaoA
创建时间：2022/9/23
功能：UART通信

修改日志：



现有问题：


*/
#ifndef __UART_H
#define __UART_H

#include "SWM181.h"
#include "SWM181_uart.h"
#include "SWM181_irqmux.h"
#include "stdio.h"	
#include <stdlib.h>
#include "stdarg.h"
#include "string.h"


#define UART_n		UART0  //定义使用printf函数的串口，其他串口要使用UART_printf专用函数发送  [UART0 UART1 UART2 UART3]
#define printf		UART0_printf

#define UART0_REC_LEN  			200  	//定义UART1最大接收字节数
#define UART1_REC_LEN  			200  	//定义UART2最大接收字节数
#define UART2_REC_LEN  			200  	//定义UART3最大接收字节数

//不使用某个串口时要禁止此串口，以减少编译量
#define EN_UART0 			1		//使能（1）/禁止（0）串口1
#define EN_UART1 			0		//使能（1）/禁止（0）串口2
#define EN_UART2 			0		//使能（1）/禁止（0）串口3
	  	
extern uint8_t  UART0_RX_BUF[UART0_REC_LEN]; //接收缓冲,最大UART_REC_LEN个字节.末字节为换行符 
//extern uint8_t  UART2_RX_BUF[UART2_REC_LEN]; //接收缓冲,最大UART_REC_LEN个字节.末字节为换行符
//extern uint8_t  UART3_RX_BUF[UART3_REC_LEN]; //接收缓冲,最大UART_REC_LEN个字节.末字节为换行符
 
extern uint16_t UART0_RX_STA;         		//接收状态标记	
// extern uint16_t UART2_RX_STA;         		//接收状态标记	
// extern uint16_t UART3_RX_STA;         		//接收状态标记	

//函数声明
void Uart_Init(uint32_t baudrate);
//void UART2_Init(uint32_t bound);//串口2初始化并启动
//void UART3_Init(uint32_t bound);//串口3初始化并启动

void UART0_printf (char *fmt, ...);

#endif

