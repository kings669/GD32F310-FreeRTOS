#include "bsp_led.h"

void led_on(void)
{
	gpio_bit_write(GPIOA, GPIO_PIN_8, SET);
}

void led_off(void)
{
	gpio_bit_write(GPIOA, GPIO_PIN_8, RESET);
}

void led_toggle(void)
{
	gpio_bit_toggle(GPIOA,GPIO_PIN_8);
}

