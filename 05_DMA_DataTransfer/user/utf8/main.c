﻿#include "dma.h"
#include "usart1.h"
#include "led.h"
#include "stm32f10x_it.h"

#define SENDBUFFER_SIZE 100
char SendBuffer[SENDBUFFER_SIZE];

int main()
{
	for(int i = 0; i < SENDBUFFER_SIZE; ++i)
	{
		SendBuffer[i] = 'A';
	}
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Config();
	USART1_Config();
	NVIC_Config();
	DMA_Config(SENDBUFFER_SIZE, (uint32_t)SendBuffer);
	DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
	DMA_Cmd(DMA1_Channel4, DISABLE);     
 	DMA_SetCurrDataCounter(DMA1_Channel4,SENDBUFFER_SIZE);//DMA閫氶亾鐨凞MA缂撳瓨鐨勫ぇ灏?
 	DMA_Cmd(DMA1_Channel4, ENABLE);
	
	
	while(1)
	{
		
		if(DMA_GetFlagStatus(DMA1_FLAG_TC4) == SET)
		{
			LED_On(0);
			DMA_ClearITPendingBit(DMA1_IT_TC4);
			printf("done");
			break;
		}
	}
	LED_On(1);
	printf("sdfsdf");
	while(1);
	
}
