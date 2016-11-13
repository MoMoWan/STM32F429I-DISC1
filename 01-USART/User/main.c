#include "main.h"

int main(void)
{
	char SentData[100];
	uint8_t index = 0;
	SystemInit();
	
	Delay_Init();
	/* Initialize USART1 at 115200 baud, TX: PA9, RX: PA10 */
	USART_Inits(USART1, USART_PinsPack_1, 115200);
	
	/* Put string to USART */
	USART_Puts(USART1, "\r\nSTM32F429ZI-DISC1");

	while(1)
	{
		sprintf(SentData,"\r\nSend data: %03d", index);
		USART_Puts(USART1, SentData);
		index++;
		delay_ms(500);
	}
}
