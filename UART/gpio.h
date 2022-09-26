/*
�ļ�����gpio.h
�����ˣ�MiaoA
����ʱ�䣺2022/9/25
���ܣ����ļ��޹��ܣ�������GPIOʱӦ�ø��ļ�������ߴ����Ķ���


�޸���־��



�������⣺


*/


#ifndef __GPIO_H_
#define __GPIO_H_

#include "SWM181.h"



#define GPIO_DIR_OUT	1		//���ģʽ
#define GPIO_DIR_IN		0		//����ģʽ

#define GPIO_PULL_UP			1		//����������
#define GPIO_PULL_UP_NOT	0		//����������

#define GPIO_PULL_DOWN			1		//����������
#define GPIO_PULL_DOWN_NOT	0		//����������

#define GPIO_OUT_OD			1		//��©���
#define GPIO_OUT_PP			0		//�������



#define PAOUT_H(pin)	GPIO_SetBit(GPIOA, (pin))	//�ߵ�ƽ���
#define PBOUT_H(pin)	GPIO_SetBit(GPIOB, (pin))
#define PCOUT_H(pin)	GPIO_SetBit(GPIOC, (pin))
#define PDOUT_H(pin)	GPIO_SetBit(GPIOD, (pin))
#define PEOUT_H(pin)	GPIO_SetBit(GPIOE, (pin))

#define PAOUT_L(pin)	GPIO_ClrBit(GPIOA, (pin))	//�͵�ƽ���
#define PBOUT_L(pin)	GPIO_ClrBit(GPIOB, (pin))
#define PCOUT_L(pin)	GPIO_ClrBit(GPIOC, (pin))
#define PDOUT_L(pin)	GPIO_ClrBit(GPIOD, (pin))
#define PEOUT_L(pin)	GPIO_ClrBit(GPIOE, (pin))

#define PAOUT_T(pin)	GPIO_InvBit(GPIOA, (pin))	//��ƽ��ת
#define PBOUT_T(pin)	GPIO_InvBit(GPIOB, (pin))
#define PCOUT_T(pin)	GPIO_InvBit(GPIOC, (pin))
#define PDOUT_T(pin)	GPIO_InvBit(GPIOD, (pin))
#define PEOUT_T(pin)	GPIO_InvBit(GPIOE, (pin))

#define PA_READ(pin)	GPIO_GetBit(GPIOA, (pin))	//��ȡ��ƽֵ
#define PB_READ(pin)	GPIO_GetBit(GPIOB, (pin))
#define PC_READ(pin)	GPIO_GetBit(GPIOC, (pin))
#define PD_READ(pin)	GPIO_GetBit(GPIOD, (pin))
#define PE_READ(pin)	GPIO_GetBit(GPIOA, (pin))

#endif


