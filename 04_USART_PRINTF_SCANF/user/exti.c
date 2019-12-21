#include "exti.h"

static void NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //缁勪紭鍏堢骇涓?
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //缁勪紭鍏堢骇涓?
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/*
void EXTI_KEY0_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	
	NVIC_Config();
	KEY_Config();
	
	//鎸囨槑EXTI绾?
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	
	//鎸囨槑宸ヤ綔妯″紡
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	
	//鎸囨槑瑙﹀彂鏈夋晥杈圭紭
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	//鍏佽涓柇
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
	
}

void EXTI_KEY1_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
	//閰嶇疆NVIC
	NVIC_Config();
	
	KEY_Config();
	
	//鍒濆鍖朎XTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	
	//鎸囨槑EXTI绾?
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	
	//鎸囨槑宸ヤ綔妯″紡
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	
	//鎸囨槑瑙﹀彂鏈夋晥杈圭紭
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	//鍏佽涓柇
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
}*/

