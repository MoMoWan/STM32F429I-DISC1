#include "main.h"
#include "button_back.h"

int main(void)
{
	/* STMPE811_TouchData instance */
	STMPE811_TouchData touchData;
	/* ILI9341_Button_t instance */
	ILI9341_Button_t button;
	int8_t buttonPressed, button1, button2, button3;
	char str[30];
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize onboard leds */
	LED_Init();
	
	/* Initialize LCD */
	ILI9341_Init();
	/* Fill LCD with gray color */
	ILI9341_Fill(ILI9341_COLOR_GRAY);
	/* Select orientation */
	ILI9341_Rotate(ILI9341_Orientation_Portrait_2);
	
	/* Select touch screen orientation */
	touchData.orientation = STMPE811_Orientation_Portrait_2;
	
	/* Initialize Touch */
	STMPE811_Init();
	
	/* Button 1, default configuration */
	/* Red with black border and black font 11x18 */
	button.x = 10;	/* X location */
	button.y = 30;	/* Y location */
	button.width = 219;
	button.height = 50;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "Button 1";
	button.color = ILI9341_COLOR_BLACK;
	button.font = &Font_11x18;
	/* Add button */
	button1 = ILI9341_Button_Add(&button);
	
	/* Button with custom background and without label */
	button.x = 10;
	button.y = 260;
	button.width = 105;
	button.height = 50;
	button.background = ILI9341_COLOR_GREEN;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "Button 2";
	/* Use background image and no label */
	button.flags = BUTTON_FLAG_NOLABEL | BUTTON_FLAG_IMAGE;
	button.color = ILI9341_COLOR_BLACK;
	button.font = &Font_11x18;
	button.image = buttonBackground; /* Variable stored in  */
	/* Add button */
	button2 = ILI9341_Button_Add(&button);
	
	/* Button with custom background and with label and without border and 7x10 fontsize */
	button.x = 125;
	button.y = 260;
	button.background = ILI9341_COLOR_BLUE2;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "Button 3";
	button.color = ILI9341_COLOR_BLACK;
	button.font = &Font_7x10;
	button.flags = BUTTON_FLAG_IMAGE | BUTTON_FLAG_NOBORDER;	/* Use background image, without border */
	/* Add button */
	button3 = ILI9341_Button_Add(&button);
	
	if (!LED_IsOn(LED_RED)) {
		/* If led res is turned off, disable buttons 2 and 3 */
		ILI9341_Button_Disable(button2);
		ILI9341_Button_Disable(button3);
		ILI9341_Puts(25, 220, "Buttons disabled!", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
	}
	
	/* Draw buttons */
	ILI9341_Button_DrawAll();
	
	/* Draw some strings */
	ILI9341_Puts(45, 245, "LED on         LED off", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_GRAY);
	ILI9341_Puts(10, 100, "Bottom buttons work\nonly if red led is turned on.\nYou can toggle red\nled with Button 1.", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_GRAY);

	while (1) {
		if (STMPE811_ReadTouch(&touchData) == STMPE811_State_Pressed) {
			buttonPressed = ILI9341_Button_Touch(&touchData);
			if (buttonPressed >= 0) {
				/* Any button pressed */
				sprintf(str, "Pressed: Button %d", (buttonPressed + 1));
			} else {
				sprintf(str, "Press the button ");
			}
			if (buttonPressed == button1) {
				/* Red button 1 is pressed, toggle led */
				LED_Toggle(LED_RED);
				
				if (LED_IsOn(LED_RED)) {
					/* If led is turned on, enable button 2 and button 3 */
					ILI9341_Button_Enable(button2);
					ILI9341_Button_Enable(button3);
					ILI9341_Puts(25, 220, "Buttons enabled! ", &Font_11x18, ILI9341_COLOR_GREEN, ILI9341_COLOR_GRAY);
				} else {
					/* otherwise disable both */
					ILI9341_Button_Disable(button2);
					ILI9341_Button_Disable(button3);
					ILI9341_Puts(25, 220, "Buttons disabled!", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
				}
			} else if (buttonPressed == button2) {
				/* If button 2 is pressed, turn green led on */
				LED_On(LED_GREEN);
			} else if (buttonPressed == button3) {
				/* if button 3 is pressed, turn green led off */
				LED_Off(LED_GREEN);
			}
		}
		ILI9341_Puts(10, 5, str, &Font_11x18, ILI9341_COLOR_GREEN, ILI9341_COLOR_GRAY);
	}
}
