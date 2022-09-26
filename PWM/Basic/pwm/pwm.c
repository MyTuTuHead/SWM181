/*
文件名：pwm.c
创建人：MiaoA
创建时间：2022/9/26
功能：PWM功能，板载绿色LED呼吸灯


修改日志：


现有问题：


*/


#include "pwm.h"

#ifdef Auto_Calculation

Auto_Cal *p;

uint8_t Pwm_Div(uint32_t hz){
	 uint8_t div = 1;
	 p = (Auto_Cal *)malloc(sizeof(Auto_Cal));

	if(24000000 % hz == 0){
		p->n = (24000000 / hz),
		p->pwm_div = 0;
		return 1;
	}

	for(;div <= 7; div++){
		if(24000000 / hz % (uint8_t)pow(2,(div-1)) == 0){
				p->n = (24000000 / hz / pow(2,(div-1))),
				p->pwm_div = div;
				return 1;
		}
	}
	return 0;//自动计算失败，返回0
} 

#endif

void Pwm_Init(void){
	PWM_InitStructure  Pwm_InitStruct;
	
//	if(!Pwm_Div(hz))	//如果未自动计算出PWM分频因子，return 1
//			return 1;

//	Pwm_InitStruct.clk_div = p->pwm_div;			//pwm分频因子自动计算
//	Pwm_InitStruct.cycleA = p->n;		
//	free(p);		//释放堆栈空间

	Pwm_InitStruct.clk_div = PWM_CLKDIV_8;		//如计算失败，请手动计算并屏蔽上式，打开此式
	Pwm_InitStruct.cycleA = 300;							//计算公式  24M / clk_div / cycleA = Hz		10k	

	Pwm_InitStruct.mode = PWM_MODE_INDEP;			//通道A和通道B独立输出					
	Pwm_InitStruct.hdutyA = DUTY(5);					//通道A占空比 5%
	Pwm_InitStruct.deadzoneA = 5;							//死区时间
	Pwm_InitStruct.initLevelA = 1;						//初始输出电平
	Pwm_InitStruct.cycleB = 300;							//通道A 频率配置			10K			
	Pwm_InitStruct.hdutyB = DUTY(5);					//通道B占空比
	Pwm_InitStruct.deadzoneB = 10;
	Pwm_InitStruct.initLevelB = 1;

	Pwm_InitStruct.HEndAIEn = 0;							//A路高电平结束中断使能
	Pwm_InitStruct.NCycleAIEn = 0;						//A路新周期开始中断使能
	Pwm_InitStruct.HEndBIEn = 0;
	Pwm_InitStruct.NCycleBIEn = 0;
	
	PWM_Init(PWM0, &Pwm_InitStruct);
	
	PORT_Init(PORTB, PIN9, FUNMUX_PWM0A_OUT, 0);
	PORT_Init(PORTA, PIN8, FUNMUX_PWM0B_OUT, 0);
	
	PWM_Start(PWM0, 1, 1);			//启动A  B通道
	
}

