#include "main.h"

int main(void)
{
	char str[30];
	/* Create TouchData struct */
	STMPE811_TouchData touchData;
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize LCD */
	ILI9341_Init();
	
	/* Rotate LCD */
	ILI9341_Rotate(ILI9341_Orientation_Portrait_2);
	
	/* Fill with orange color */
	ILI9341_Fill(ILI9341_COLOR_ORANGE);
	
	/* Initialize Touch */
	if (STMPE811_Init() != STMPE811_State_Ok)
	{
		ILI9341_Puts(20, 20, "STMPE811 Error", &Font_11x18, ILI9341_COLOR_ORANGE, ILI9341_COLOR_BLACK);
		while (1);
	}
	
	/* Select touch screen orientation */
	touchData.orientation = STMPE811_Orientation_Portrait_2;
	
	/* Print some text */
	ILI9341_Puts(20, 20, "Press on LCD", &Font_11x18, ILI9341_COLOR_ORANGE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(93, 310, "stm32f4-discovery.com", &Font_7x10, ILI9341_COLOR_GREEN, ILI9341_COLOR_BLACK);
	
	while(1) 
	{
		/* If touch pressed */
		if (STMPE811_ReadTouch(&touchData) == STMPE811_State_Pressed) {
		/* Touch valid */
		sprintf(str, "Pressed    \n\nX: %03d\nY: %03d", touchData.x, touchData.y);
		ILI9341_Puts(20, 80, str, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);

		/* Draw pixel on touch location */
		ILI9341_DrawPixel(touchData.x, touchData.y, 0x0000);
		} else {
		/* Touch not pressed */
		sprintf(str, "Not Pressed\n\n       \n      ");
		ILI9341_Puts(20, 80, str, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);
		}
	}
}
