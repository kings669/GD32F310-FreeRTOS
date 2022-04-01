#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/** 
  * @brief GPIO Init structure definition  
  */ 
typedef struct
{
	uint8_t otype;
	
  uint32_t pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  uint32_t mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  uint32_t pull_up_down;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

	uint32_t gpio_periph;		/* gpio_periph: GPIOx(x = A,B,C,D,F)	
																only one parameter can be selected which is shown as below:
																								@ref GPIOx(x = A,B,C,D,F)*/
	
	uint32_t speed;			/*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */
	uint32_t alt_func_num;  /*!< Peripheral to be connected to the selected pins. 
                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
}GPIO_InitTypeDef;



void My_GPIO_Init(void);

#ifdef __cplusplus
}
#endif
#endif

