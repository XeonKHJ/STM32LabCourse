#include "exti.h"
#include "key.h"

static void NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//配置组优先级 
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//配置中断源
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //组优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//配置P3为中断源，用到Key1（PE3）
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //组优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_KEY0_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	
	NVIC_Config();
	KEY_Config();
	
	//指明EXTI线
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	
	//指明工作模式
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	
	//指明触发有效边缘
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	//允许中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
	
}

void EXTI_KEY1_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
	//配置NVIC
	NVIC_Config();
	
	KEY_Config();
	
	//初始化EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	
	//指明EXTI线
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	
	//指明工作模式
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	
	//指明触发有效边缘
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	//允许中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
}

