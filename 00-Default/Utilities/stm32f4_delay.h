#ifndef __STM32F4_DELAY_H
#define __STM32F4_DELAY_H
#ifdef __cplusplus
 extern "C" {
#endif
     
#include "stm32f4xx.h"

#define DWT_CYCCNT  ((volatile uint32_t *)0xE0001004)
         
uint32_t Delay_Init(void);
void Delay_Decrement(void);
uint32_t micros(void);
uint32_t millis(void);
__STATIC_INLINE void delay_us(__IO uint32_t micros)
{
    uint32_t start = DWT->CYCCNT;
	RCC_ClocksTypeDef clocks;
	
    RCC_GetClocksFreq(&clocks);
    micros *= clocks.SYSCLK_Frequency / 1000000;

    /* Delay till end */
    while ((DWT->CYCCNT - start) < micros);
}

void delay_ms(__IO uint32_t millis);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_DELAY_H */

