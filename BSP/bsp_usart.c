#include "bsp_usart.h"
#include "usart.h"
#include <stdio.h>
#include <stdarg.h>
#include "string.h"
uint8_t usart0_buf[256];
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

