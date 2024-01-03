/*
文件名：oled.h
创建人：MiaoA
创建时间：2022/9/26
功能：OLED屏幕显示，使用软件I2C

修改日志：



现有问题：


*/

#ifndef __OLED_H
#define __OLED_H 

#include "SWM181.h"
#include "stdlib.h"	


//------OLED端口定义---用户只需修改这个端口即可-----//

#define OLED_SCL_PIN	PIN1
#define OLED_SCL_PORT	GPIOD

#define OLED_SDA_PIN	PIN2
#define OLED_SDA_PORT	GPIOD


#define OLED_SCLK_Clr() GPIO_ClrBit(OLED_SCL_PORT,OLED_SCL_PIN)
#define OLED_SCLK_Set() GPIO_SetBit(OLED_SCL_PORT,OLED_SCL_PIN)//SCL

#define OLED_SDIN_Clr() GPIO_ClrBit(OLED_SDA_PORT,OLED_SDA_PIN)//SDA
#define OLED_SDIN_Set() GPIO_SetBit(OLED_SDA_PORT,OLED_SDA_PIN)



#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define u8 unsigned char
#define u32 unsigned int

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2c_Start(void);
void I2c_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh_Gram(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1);
void OLED_WR_BP(u8 x,u8 y);
void OLED_Init(void);

#endif
