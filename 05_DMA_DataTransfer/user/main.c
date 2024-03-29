#include "dma.h"
#include "usart1.h"
#include "led.h"
#include "stm32f10x_it.h"

#define SENDBUFFER_SIZE 10000
char SendBuffer[SENDBUFFER_SIZE];
//extern int dmastatus;
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
 	DMA_SetCurrDataCounter(DMA1_Channel4,SENDBUFFER_SIZE);
 	DMA_Cmd(DMA1_Channel4, ENABLE);
	
	while(dmastatus)
	{
			LED_On(0);
			Delay(0xFFFF);
			LED_Off(0);
			LED_On(1);
			Delay(0xFFFF);
			LED_Off(1);
	}
	//printf("DMA传输完成");
}
