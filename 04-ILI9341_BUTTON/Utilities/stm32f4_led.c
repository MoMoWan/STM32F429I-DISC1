#include "stm32f4_led.h"

static volatile uint8_t ButtonPressed = 0;

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	GPIO_InitStructure.GPIO_Pin = LED_ALL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void Button_Init(void)
{
	/* Set pin as input */
	GPIO_Inits(BUTTON_PORT, BUTTON_PIN, GPIO_Mode_IN, GPIO_OType_PP, BUTTON_PULL, GPIO_Low_Speed);
}

uint8_t Button_OnPressed(void)
{
	/* If button is now pressed, but was not already pressed */
	if (Button_Pressed()) {
		if (!ButtonPressed) {
			/* Set flag */
			ButtonPressed = 1;
			
			/* Return button onpressed */
			return 1;
		}
	} else {
		/* Clear flag */
		ButtonPressed = 0;
	}
	
	/* Button is not pressed or it was already pressed before */
	return 0;
}

uint8_t Button_OnReleased(void)
{
	/* If button is now released, but was not already released */
	if (!Button_Pressed()) {
		if (ButtonPressed) {
			/* Set flag */
			ButtonPressed = 0;
			
			/* Return button onreleased */
			return 1;
		}
	} else {
		/* Set flag */
		ButtonPressed = 1;
	}
	
	/* Button is not released or it was already released before */
	return 0;
}
