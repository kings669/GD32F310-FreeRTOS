#include "gpio.h"

void My_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/*GPIO Port Clock Enable */
	rcu_periph_clock_enable(RCU_GPIOA);
	
	/*Configure GPIO pin : PtPin  PA8*/
	GPIO_InitStruct.gpio_periph = GPIOA;
	GPIO_InitStruct.mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.pin = GPIO_PIN_8;
	GPIO_InitStruct.otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.speed = GPIO_OSPEED_50MHZ;
	GPIO_InitStruct.pull_up_down = GPIO_PUPD_NONE;
	gpio_mode_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.mode,GPIO_InitStruct.pull_up_down,GPIO_InitStruct.pin);

	/*Configure GPIO pin Output Level */
	gpio_output_options_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.otype,GPIO_InitStruct.speed,GPIO_InitStruct.pin);
	GPIO_BC(GPIO_InitStruct.gpio_periph) = GPIO_InitStruct.pin;
	/* EXTI interrupt init*/
}
