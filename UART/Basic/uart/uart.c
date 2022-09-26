/*
文件名：uart.c
创建人：MiaoA
创建时间：2022/9/23
功能：UART通信


修改日志：
2022/9/24--->>去除Fputc()重定义函数
							原因：重定义fputc使用printf时需要单个字符打印，过程过于繁琐
							如需调试打印，请使用 UART0_printf（）函数，使用方法和printf一致


现有问题：
2022/9/24--->>重定义fputc函数后，使用printf会卡死
							原因分析：使用printf函数读取字符长度未知导致


*/

#include "uart.h"

//重定义fputc函数 用于printf()
//int fputc(int ch, FILE *f)
//{
//	UART_WriteByte(UART_n, ch);
//	
//	while(UART_IsTXBusy(UART_n));
// 	
//	return ch;
//}



#if EN_UART0   //USART1使用与屏蔽选择
uint8_t UART0_RX_BUF[UART0_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
uint16_t UART0_RX_STA=0;       //接收状态标记	  


/*
USART1专用的printf函数
当同时开启2个以上串口时，printf函数只能用于其中之一，其他串口要自创独立的printf函数
调用方法：USART1_printf("123"); //向USART2发送字符123
*/
void UART0_printf (char *fmt, ...){ 
	char buffer[UART0_REC_LEN+1];  // 数据长度
	uint8_t i = 0;	
	va_list arg_ptr;
	va_start(arg_ptr, fmt);  
	vsnprintf(buffer, UART0_REC_LEN+1, fmt, arg_ptr);
	while ((i < UART0_REC_LEN) && (i < strlen(buffer))){
        UART_WriteByte(UART0, (uint8_t) buffer[i++]);
        while(UART_IsTXBusy(UART_n));
	}
	va_end(arg_ptr);
}

//UART初始化
//参数：波特率
void Uart_Init(uint32_t baudrate){
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTA, PIN0, FUNMUX_UART0_RXD, 1);	//GPIOA.0配置为UART0输入引脚  引脚可映射，如需修改，参照数据手册管脚定义
	PORT_Init(PORTA, PIN1, FUNMUX_UART0_TXD, 0);	//GPIOA.1配置为UART0输出引脚
 	
 	UART_initStruct.Baudrate = baudrate;            //波特率
	UART_initStruct.DataBits = UART_DATA_8BIT;      //8位数据位
	UART_initStruct.Parity = UART_PARITY_NONE;      //无奇偶校验位
	UART_initStruct.StopBits = UART_STOP_1BIT;      //1位停止位
	UART_initStruct.RXThreshold = 3;                //RX FIFO深度3可选[0-7]
	UART_initStruct.RXThresholdIEn = 1;             //开启FIFO数据溢出中断 RX FIFO中数据个数 >  RXThreshold时触发中断
	UART_initStruct.TXThreshold = 3;                //TX FIFO深度3可选[0-7]
	UART_initStruct.TXThresholdIEn = 0;             //当TX FIFO中数据个数 <= TXThreshold时触发中断
	UART_initStruct.TimeoutTime = 10;		        //10个字符时间内未接收到新的数据则触发超时中断
	UART_initStruct.TimeoutIEn = 0;                 //关闭超时中断

 	UART_Init(UART0, &UART_initStruct); 
	
	IRQ_Connect(IRQ0_15_UART0, UART0_IRQ_LINE, 1);        //中断配置，绑定UART0中断到 IRQ0上
	
	UART_Open(UART0);                               //开启UART0
}


#endif	









