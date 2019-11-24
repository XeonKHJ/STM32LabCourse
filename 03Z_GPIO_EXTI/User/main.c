#include "exti.h"
#include "key.h"
#include "led.h"
#include "stm32f10x_it.h"

int main()
{
	EXTI_KEY0_Config();
	EXTI_KEY1_Config();
	
	LED_Config();
	LED_Off_all();
	
	__set_PRIMASK(1);
	__set_PRIMASK(0);
	
	while(1);
}
