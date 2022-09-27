/*
�ļ�����irq.c
�����ˣ�MiaoA
����ʱ�䣺2022/9/23
���ܣ���������жϷ�����

�޸���־��



�������⣺


*/

#include "irq.h"

uint32_t led_duty = 5;
uint8_t flag = 0;
uint32_t adc_val;

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


void IRQ5_Handler(void){

	TIMR_INTClr(TIMR0);
	
//	PBOUT_T(LED3_PIN);	//��תLED����״̬

	adc_val = ADC_Read(ADC,ADC_CH5);
	if(adc_val == 0)
		return;
	OLED_ShowNum(65,16,adc_val,4,12);
	OLED_Refresh_Gram();
}


void SysTick_Handler(void)
{	
	PWM_SetHDuty(PWM0,PWM_CH_A,DUTY(led_duty));
	PWM_SetHDuty(PWM0,PWM_CH_B,DUTY(led_duty));
	if(flag == 0){
		if(led_duty <= 75)
			led_duty += 3;
		else	flag = 1;
	}
	if(flag == 1){
		if(led_duty >= 5)
			led_duty -= 3;
		else	flag = 0;
	}
	
	PDOUT_T(LED1_PIN);	//��תLED����״̬
	PBOUT_T(LED2_PIN);	
}

