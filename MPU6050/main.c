/*
文件名：main.c
创建人：MiaoA
创建时间：2022/9/27
功能：MPU6050角度，OLED屏幕显示，使用软件I2C

修改日志：



现有问题：
2022/9/27--->>加入MPU_Init后滴答定时器进不去中断


*/

#include "SWM181.h"
#include "oled.h"
#include "delay.h"
#include "led.h"
#include "gpio.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "uart.h"

float pitch,roll,yaw; 		//欧拉角
short aacx,aacy,aacz;		//加速度传感器原始数据
short gyrox,gyroy,gyroz;	//陀螺仪原始数据
short temp;					//



int main(void)
{	
	SystemInit();	
	Led_Init();
	OLED_Init();			//初始化OLED  
	Uart_Init(115200);
	printf("MiaoA");

	if(MPU_Init())
		printf("MPU6050 Init Error");

	while(mpu_dmp_init()){
		OLED_ShowString(16,48,"MPU6050 Error",12);
		OLED_Refresh_Gram();
 		delay_ms(500);
	}

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_ms(300);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
	delay_ms(300);

	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	

	if(SysTick_Config(SystemCoreClock/4))	printf("systick error");			//每1/8秒钟触发一次中断
	
	OLED_Clear();
	OLED_ShowString(0,0,"MiaoA",12);		//x,y:起点坐标 *chr:字符串起始地址  size1:字体大小 
	OLED_ShowString(0,14,"OK",12); 
 	OLED_ShowString(0,27,"Pitch:     . C",12);	
 	OLED_ShowString(0,39," Roll:     . C",12);	 
 	OLED_ShowString(0,52," Yaw :     . C",12);	 
	OLED_Refresh_Gram();								//刷新显示
	while(1)
	{
				  //获取MPU6050数据
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0){
//				MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
//				MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		
				/***********显示***********/									
				/*X轴数据处理*/
					temp=pitch*10;				
					if(temp<0)
					{
						OLED_ShowChar(40,27,'-',12,1);//显示负号
						temp=-temp;		//转为正数
					}else	OLED_ShowChar(40,27,' ',12,1);//去掉负号 
					OLED_ShowNum(40+8,27,temp/10,3,12);		//显示整数部分	    
					OLED_ShowNum(40+8+8+8+8,27,temp%10,1,12);		//显示小数部分 
									
				/***********显示***********/		
				/*y轴数据处理*/
				temp=roll*10;				
				if(temp<0)
				{
					OLED_ShowChar(40,39,'-',12,1);//显示负号
					temp=-temp;		//转为正数
				}else	OLED_ShowChar(40,39,' ',12,1);//去掉负号 
				OLED_ShowNum(40+8,39,temp/10,3,12);		//显示整数部分	    
				OLED_ShowNum(40+8+8+8+8,39,temp%10,1,12);		//显示小数部分 

				/*z轴数据处理*/
				temp=yaw*10;				
				if(temp<0)
				{
					OLED_ShowChar(40,52,'-',12,1);//显示负号
					temp=-temp;		//转为正数
				}else	OLED_ShowChar(40,52,' ',12,1);//去掉负号 
				OLED_ShowNum(40+8,52,temp/10,3,12);		//显示整数部分	    
				OLED_ShowNum(40+8+8+8+8,52,temp%10,1,12);		//显示小数部分 
				OLED_Refresh_Gram();
		}
	}
}
void SysTick_Handler(void)
{	
	printf("systick");
	PDOUT_T(LED1_PIN);	//反转LED亮灭状态
	PBOUT_T(LED2_PIN);	
}


