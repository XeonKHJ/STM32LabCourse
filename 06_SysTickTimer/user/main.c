#include "stm32f10x.h"
#include "key.h"
#include "iwdg.h"
#include "led.h"
int main()
{
	KEY_Config();
	LED_Config();
	LED_On_all();
	Delay(0xfffff);
	LED_Off_all();
	
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST)==SET)
	{
		LED_On(1);
		Delay(0xfffff);
		LED_Off(1);
	}
	else
	{
		LED_On(0);
		Delay(0xfffff);
		LED_Off(0);
	}
	while(1)
	{
		if(KEY0_STATE == 1)
		{
			IWDG_ReloadCounter();
		}
	}
}