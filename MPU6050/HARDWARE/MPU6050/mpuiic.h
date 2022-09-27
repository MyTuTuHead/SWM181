#ifndef __MPUIIC_H
#define __MPUIIC_H
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK MiniSTM32F103������
//MPU6050 IIC���� ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/4/18
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
#include "gpio.h"
  


#define POUT(PIN,n)	{ n==1 ? PBOUT_H(PIN) : PBOUT_L(PIN);}
	
#define SCL_PIN	PIN6

#define SDA_PIN	PIN7
#define SDA_PORT	GPIOB
	   
//IO��������
#define MPU_SDA_IN()  {GPIO_Init(SDA_PORT,SDA_PIN,GPIO_DIR_IN,GPIO_PULL_UP,GPIO_PULL_DOWN_NOT,0);}//�������룬
#define MPU_SDA_OUT() {GPIO_Init(SDA_PORT,SDA_PIN,GPIO_DIR_OUT,GPIO_PULL_UP_NOT,GPIO_PULL_DOWN_NOT,GPIO_OUT_PP);}//ͨ���������

//IO��������	 
//#define MPU_IIC_SCL    PBOUT_H(9) 		//SCL
//#define MPU_IIC_SDA    PBout(8) 		//SDA	 
#define MPU_READ_SDA   PB_READ(SDA_PIN)		//����SDA 

#define u8 unsigned char
#define u16 unsigned short

//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

void IMPU_IC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 MPU_IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















