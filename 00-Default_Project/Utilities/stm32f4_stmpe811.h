#ifndef __STM32F4_STMPE811_H
#define __STM32F4_STMPE811_H

#ifdef __cplusplus
 extern "C" {
#endif
     
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4_i2c.h"
#include "stm32f4_delay.h"

/**
 * @defgroup STMPE811_Macros
 * @brief    Library defines
 * @{
 */

/**
 * @brief  Default I2C used, on STM32F429-Discovery board 
 */
#ifndef STMPE811_I2C
#define STMPE811_I2C					I2C3
#define STMPE811_I2C_PINSPACK			I2C_PinsPack_1
#endif

/**
 * @brief  Default I2C clock for STMPE811
 */
#ifndef STMPE811_I2C_CLOCK
#define STMPE811_I2C_CLOCK				100000
#endif

/**
 * @}
 */
 
/**
 * @defgroup STMPE811_Typedefs
 * @brief    Library Typedefs
 * @{
 */
 
/**
 * @brief  Enum for set how to read x and y from controller
 * @note   You may need experimenting to get proper orientation to match your LCD
 */
typedef enum {
	STMPE811_Orientation_Portrait_1,  /*!< Portrait orientation mode 1 */
	STMPE811_Orientation_Portrait_2,  /*!< Portrait orientation mode 2 */
	STMPE811_Orientation_Landscape_1, /*!< Landscape orientation mode 1 */
	STMPE811_Orientation_Landscape_2, /*!< Landscape orientation mode 2 */
} STMPE811_Orientation_t;

/**
 * @brief  Enumeration for touch pressed or released
 */
typedef enum {
	STMPE811_State_Pressed,  /*!< Touch detected as pressed */
	STMPE811_State_Released, /*!< Touch detected as released/not pressed */
	STMPE811_State_Ok,       /*!< Result OK. Used on initialization */
	STMPE811_State_Error     /*!< Result error. Used on initialization */
} STMPE811_State_t;

/**
 * @brief  Main structure, which is passed into @ref STMPE811_ReadTouch function
 */
typedef struct {
	uint16_t x;                            /*!< X coordinate on LCD for touch */ 
	uint16_t y;                            /*!< Y coordinate on LCD for touch */
	STMPE811_State_t pressed;           /*!< Pressed touch status */
	STMPE811_State_t last_pressed;      /*!< Last pressed touch status */
	STMPE811_Orientation_t orientation; /*!< Touch screen orientation to match your LCD orientation */
} STMPE811_t;

/* Backward compatibility */
typedef STMPE811_t STMPE811_TouchData;

/**
 * @}
 */

/**
 * @defgroup STMPE811_Functions
 * @brief    Library Functions
 * @{
 */
 
/**
 * @brief  Initializes STMPE811 Touch driver
 * @param  None
 * @retval Member of @ref STMPE811_State_t
 */
STMPE811_State_t STMPE811_Init(void);

/**
 * @brief  Reads touch coordinates
 * @param  *structdata: Pointer to @ref STMPE811_t to store data into
 * @retval Touch status:
 *            - STMPE811_State_Pressed: Touch detected as pressed, coordinates valid
 *            - STMPE811_State_Released: Touch detected as not pressed, coordinates not valid
 */
STMPE811_State_t STMPE811_ReadTouch(STMPE811_t* structdata);

/**
 * @brief  Checks if touch data is inside specific rectangle coordinates
 * @param  sd: Pointer to @ref STMPE811_t to get data from
 * @param  xPos: Top-left X position of rectangle
 * @param  yPos: Top-left Y position of rectangle
 * @param  w: Rectangle width
 * @param  h: Rectangle height:
 * @retval Touch inside rectangle status:
 *            - 0: Touch is outside rectangle
 *            - > 0: Touch is inside rectangle
 * @note   Defined as macro for faster execution
 */ 
#define STMPE811_TouchInRectangle(sd, xPos, yPos, w, h)	(((sd)->x >= (xPos)) && ((sd)->x < (xPos + w)) && ((sd)->y >= (yPos)) && ((sd)->y < (yPos + h)))

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_STMPE811_H */

