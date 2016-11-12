#include "main.h"

int main(void)
{
	SystemInit();
	
	/* Initialize delay */
	Delay_Init();
		
	USART_Inits(USART1, USART_PinsPack_1, 115200);
	
	/* Put string to USART */
	USART_Puts(USART1, "Hello world\n");

	/* While loop */
	while(1)
	{
		USART_Puts(USART1, "Hello world\n\r");
		delay_ms(500);
	}
}
