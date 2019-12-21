#include "usart1.h"
#include "stm32f10x.h"
#include "led.h"
#include "exti.c"

extern int ledNo;
int main()
{
	
	//char msg[100];
	
	USART1_Config();
	NVIC_Config();
	LED_Config();
	
	//printf("请输入要显示的按钮");
	
	scanf("%d", &ledNo);
	
	//printf(&ledNo);
}