#include "main.h"

int main(void)
{
	SystemInit();
	Delay_Init();
	LED_Init();
	
	LED_On(LED_GREEN);
	LED_Off(LED_RED);
	
	while(1)
	{
		LED_Toggle(LED_ALL);
		delay_ms(500);
	}
	
}
