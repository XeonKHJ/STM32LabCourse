#include "usart1.h"
#include "stm32f10x.h"

int main()
{
	char msg[100];
	USART1_Config();
	
	printf("sdfjslkdfjslkdf");
	
	scanf("%s", msg);
	
	printf(msg);
}