#include "main.h"

int main(void)
{
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay */
	Delay_Init();
		
	/* Initialize ILI9341 */
	ILI9341_Init();
	
	/* Rotate LCD for 90 degrees */
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	
	/* Fill lcd with color */
	ILI9341_Fill(ILI9341_COLOR_MAGENTA);
	/* Draw white circle */
	ILI9341_DrawCircle(60, 60, 40, ILI9341_COLOR_GREEN);
	/* Draw red filled circle */
	ILI9341_DrawFilledCircle(60, 60, 35, ILI9341_COLOR_RED);
	/* Draw blue rectangle */
	ILI9341_DrawRectangle(120, 20, 220, 100, ILI9341_COLOR_BLUE);
	/* Draw black filled circle */
	ILI9341_DrawFilledRectangle(130, 30, 210, 90, ILI9341_COLOR_BLACK);
	/* Draw line with custom color 0x0005 */
	ILI9341_DrawLine(10, 120, 310, 120, 0x0005);
	
	/* Put string with black foreground color and blue background with 11x18px font */
	ILI9341_Puts(65, 130, "STM32F4 Discovery", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	/* Put string with black foreground color and blue background with 11x18px font */
	ILI9341_Puts(60, 150, "ILI9341 LCD Module", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE2);
	/* Put string with black foreground color and red background with 11x18px font */
	ILI9341_Puts(45, 229, "stm32f4-discovery.com", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);

	/* While loop */
	while(1)
	{
		
	}
}
