#include "iwdg.h"

void IWDG_Config()
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_256);
	IWDG_SetReload(1563);
	IWDG_ReloadCounter();
	IWDG_Enable();
}