/*
�ļ�����irq.c
�����ˣ�MiaoA
����ʱ�䣺2022/9/23
���ܣ���������жϷ�����

�޸���־��



�������⣺


*/

#include "irq.h"



void IRQ0_Handler(void){
	uint32_t chr;
	
	if(UART_INTRXThresholdStat(UART0)){             //RX FIFO����ж�
		while(UART_IsRXFIFOEmpty(UART0) == 0){     //��ȡ RX FIFO��Ϊ0
			if(UART_ReadByte(UART0, &chr) == 0){

                if(UART0_RX_STA >= UART0_REC_LEN - 10)    //ѭ�����ݽ���
                    UART0_RX_STA = 0;

                UART0_RX_BUF[UART0_RX_STA] = chr;
                UART0_RX_STA++;
								UART_WriteByte(UART0, chr);//����
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

