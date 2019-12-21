#include "usart1.h"
#include "stm32f10x.h"
#include "led.h"
#include "exti.c"

extern int ledNo;
int main()
{
	USART1_Config();
	NVIC_Config();
	LED_Config();
	
	printf("Press Key");
	
	scanf("%d", &ledNo);
}
