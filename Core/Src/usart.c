#include "usart.h"
#include "gpio.h"

UART_HandleTypeDef usart0;

void My_Usart_Init(void)
{
	/* USART configure */
	usart0.usart_periph = USART0;
	usart0.Init.BaudRate = 115200U;
	usart0.Init.WordLength = USART_WL_8BIT;
	usart0.Init.StopBits = USART_STB_1BIT;
	usart0.Init.Parity = USART_PM_NONE;
	
	usart_deinit(usart0.usart_periph);
	usart_baudrate_set(usart0.usart_periph,usart0.Init.BaudRate);
	usart_word_length_set(usart0.usart_periph,usart0.Init.WordLength);
	usart_stop_bit_set(usart0.usart_periph,usart0.Init.StopBits);
	usart_parity_config(usart0.usart_periph,usart0.Init.Parity);
	usart_receive_config(usart0.usart_periph,USART_RECEIVE_ENABLE);
	usart_transmit_config(usart0.usart_periph,USART_TRANSMIT_ENABLE);
	usart_enable(usart0.usart_periph);
	usart_interrupt_enable(usart0.usart_periph, USART_INT_RBNE);
	usart_interrupt_enable(usart0.usart_periph, USART_INT_ERR);
	nvic_irq_enable(USART0_IRQn,0,0);
}

void My_Usart_MspInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/*GPIO Port Clock Enable */
	rcu_periph_clock_enable(RCU_GPIOA);
	/*Usart0 Clock Enable */
	rcu_periph_clock_enable(RCU_USART0);
	
	/**USART0 GPIO Configuration
   PA10    ------> USART0_RX
   PA9     ------> USART0_TX
   */
	/*Configure GPIO pin : PtPin  PA9*/
	GPIO_InitStruct.gpio_periph = GPIOA;
	GPIO_InitStruct.mode = GPIO_MODE_AF;
	GPIO_InitStruct.pin = GPIO_PIN_9;
	GPIO_InitStruct.otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.speed = GPIO_OSPEED_50MHZ;
	GPIO_InitStruct.pull_up_down = GPIO_PUPD_PULLUP;
	GPIO_InitStruct.alt_func_num=GPIO_AF_1;
	gpio_af_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.alt_func_num,GPIO_InitStruct.pin);
	gpio_mode_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.mode,GPIO_InitStruct.pull_up_down,GPIO_InitStruct.pin);
	gpio_output_options_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.otype,GPIO_InitStruct.speed,GPIO_InitStruct.pin);
	/*Configure GPIO pin : PtPin  PA10*/
	GPIO_InitStruct.gpio_periph = GPIOA;
	GPIO_InitStruct.mode = GPIO_MODE_AF;
	GPIO_InitStruct.pin = GPIO_PIN_10;
	GPIO_InitStruct.otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.speed = GPIO_OSPEED_50MHZ;
	GPIO_InitStruct.pull_up_down = GPIO_PUPD_PULLUP;
	GPIO_InitStruct.alt_func_num=GPIO_AF_1;
	gpio_af_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.alt_func_num,GPIO_InitStruct.pin);
	gpio_mode_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.mode,GPIO_InitStruct.pull_up_down,GPIO_InitStruct.pin);
	gpio_output_options_set(GPIO_InitStruct.gpio_periph,GPIO_InitStruct.otype,GPIO_InitStruct.speed,GPIO_InitStruct.pin);
}
