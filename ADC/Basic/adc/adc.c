/*
文件名：adc.c
创建人：MiaoA
创建时间：2022/9/27
功能：ADC功能，接在PWM0_CHB-PA8


修改日志：


现有问题：


*/


#include "adc.h"

void Adc_Init(void){
	ADC_InitStructure Adc_InitStruct;
	
	PORT_Init(PORTC, PIN7, PORTC_PIN7_ADC_CH5, 0);//ADC_CH5映射在	PC7，func映射详情见port.h
	
	Adc_InitStruct.clk_src = ADC_CLKSRC_HRC_DIV4;	//ADC时钟分频因子，使用 HIS 4分频
	Adc_InitStruct.channels = ADC_CH5;						//通道选择
	Adc_InitStruct.samplAvg = ADC_AVG_SAMPLE4;		//采样平均次数
	Adc_InitStruct.trig_src = ADC_TRIGSRC_SW;			//软件触发，即ADC->START.GO写1启动转换，调用ADC_Start即可
	Adc_InitStruct.Continue = 1;									//连续采样模式，启动后一直采样转换,直到软件清除START位
	Adc_InitStruct.EOC_IEn = 0;										//单次完成中断
	Adc_InitStruct.OVF_IEn = 0;										//FIFO溢出中断

	ADC_Init(ADC, &Adc_InitStruct);
	ADC_Open(ADC);									//使能ADC
	ADC_Start(ADC);									//开启转换

}








