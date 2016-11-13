#include "main.h"

int main(void)
{
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay */
	Delay_Init();
	
	/* Initialize ILI9341 with LTDC */
	/* By default layer 1 is used */
	ILI9341_Init();
	
	/* Rotate LCD for 90 degrees */
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	
	/* Go to layer 1 */
	ILI9341_SetLayer1();
	
	/* Fill screen on layer 1 */
	ILI9341_Fill(ILI9341_COLOR_BLUE);
	
	/* Show text */
	ILI9341_Puts(65, 30, "Layer 1", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(20, 130, "STM32F429 Discovery ONLY!", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(60, 150, "ILI9341 LCD Module", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(70, 170, "with LTDC support", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(170, 230, "stm32f4-discovery.com", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);
	
	/* Go to layer 2 */
	ILI9341_SetLayer2();
	
	/* Fill screen on layer 2 */
	ILI9341_Fill(ILI9341_COLOR_GREEN);
	
	/* Show text */
	ILI9341_Puts(65, 30, "Layer 2", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE);
	ILI9341_Puts(20, 130, "STM32F429 Discovery ONLY!", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	ILI9341_Puts(60, 150, "ILI9341 LCD Module", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(70, 170, "with LTDC support", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	ILI9341_Puts(170, 230, "stm32f4-discovery.com", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);
	
	/* Draw circle on layer 2 */
	ILI9341_DrawCircle(150, 150, 140, ILI9341_COLOR_BLACK);

	while (1) {		
		/* This will set opacity of one layer to 0, other to max (255) each time */
		/* This is like toggle function */
		ILI9341_ChangeLayers();
		/* Every 1 second */
		delay_ms(1000);
		
		//Bottom code works the same as one before inside while loop
		
		//Turn on Layer1 and turn off Layer2
		ILI9341_SetLayer1Opacity(255);
		ILI9341_SetLayer2Opacity(0);
		delay_ms(500);
		
		//Turn on Layer2 and turn off Layer1
		ILI9341_SetLayer1Opacity(0);
		ILI9341_SetLayer2Opacity(255);
		delay_ms(500);
		
	}
}
