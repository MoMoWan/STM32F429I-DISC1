#ifndef __STM32F4_LED_H
#define __STM32F4_LED_H
#ifdef __cplusplus
 extern "C" {
#endif
     
#include "stm32f4xx.h"
#include "stm32f4_gpio.h"
	 
#define LED_GREEN					GPIO_Pin_13
#define LED_RED						GPIO_Pin_14
#define LED_ALL						LED_GREEN | LED_RED
#define LED_PORT					GPIOG

#define BUTTON_PORT					GPIOA
#define BUTTON_PIN					GPIO_Pin_0
#define BUTTON_PRESSED				1
#define BUTTON_PULL					GPIO_PuPd_DOWN
	 
void LED_Init(void);
#define LED_On(led)					GPIO_SetBits(LED_PORT, led);
#define LED_Off(led)				GPIO_ResetBits(LED_PORT, led);
#define LED_Toggle(led)				GPIO_ToggleBits(LED_PORT, led);
#define LED_IsOn(led)				(((LED_PORT)->ODR & (led)) == 0 ? 0 : 1)

#define Button_Pressed()       ((GPIO_GetInputPinValue(BUTTON_PORT, BUTTON_PIN) == 0) != BUTTON_PRESSED)

/**
 * @brief  Checks if button was pressed now, but was not already pressed before
 * @param  None
 * @retval Button on pressed value
 *           - 0: In case that button has been already pressed on last call or was not pressed at all yet
 *           - > 0: Button was pressed, but state before was released
 */
uint8_t Button_OnPressed(void);

/**
 * @brief  Checks if button was released now, but was already pressed before
 * @param  None
 * @retval Button on released value
 *           - 0: In case that button has been already released on last call or was not released at all yet
 *           - > 0: Button was released, but state before was pressed
 */
uint8_t Button_OnReleased(void);
	 
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_LED_H */

