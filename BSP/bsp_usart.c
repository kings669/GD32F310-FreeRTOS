#include "bsp_usart.h"
#include "usart.h"
#include <stdio.h>
#include <stdarg.h>
#include "string.h"
uint8_t usart0_buf[128];
uint16_t len = 0,i;
//printf redefine 
void usart0_printf(const char *fmt,...)
{
    static va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)usart0_buf, fmt, ap);
    va_end(ap);
		len = strlen((const char *)usart0_buf);
		for(i=0;i<len;i++)
		{
			while (RESET == usart_flag_get(usart0.usart_periph,USART_FLAG_TC));//循环发送,直到发送完毕   
			usart_data_transmit(usart0.usart_periph,(uint32_t)usart0_buf[i]);
		}	
}

uint8_t value;
void USART0_IRQHandler(void)
{
	if(RESET != usart_interrupt_flag_get(usart0.usart_periph, USART_INT_FLAG_RBNE))
	{
		/* receive data */
		value = (uint8_t)usart_data_receive(usart0.usart_periph);
		usart_interrupt_flag_clear(usart0.usart_periph,USART_INT_FLAG_ERR_FERR);
	}
}
