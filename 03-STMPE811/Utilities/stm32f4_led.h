#ifndef __STM32F4_LED_H
#define __STM32F4_LED_H
#ifdef __cplusplus
 extern "C" {
#endif
     
#include "stm32f4xx.h"

#define LED_GREEN					GPIO_Pin_13
#define LED_RED						GPIO_Pin_14
#define LED_ALL						LED_GREEN | LED_RED

#define LED_PORT					GPIOG
	 
void LED_Init(void);
	 
#define LED_On(led)					GPIO_SetBits(LED_PORT, led);
#define LED_Off(led)				GPIO_ResetBits(LED_PORT, led);
#define LED_Toggle(led)				GPIO_ToggleBits(LED_PORT, led);
#define LED_IsOn(led)				(((LED_PORT)->ODR & (led)) == 0 ? 0 : 1)

	 
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_LED_H */

