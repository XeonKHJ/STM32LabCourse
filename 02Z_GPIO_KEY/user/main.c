#include "key.h"
#include "led.h"

int main()
{
	KEY_Config();
	LED_Config();
	
	while(1)
	{
		if(KEY0_STATE == 1)
		{
			LED_On(0);
			Delay(0xFFFF);
			LED_Off(0);
		}
		if(KEY1_STATE == 1)
		{
			LED_On(1);
			Delay(0xFFFF);
			LED_Off(1);
		}
	}
}
