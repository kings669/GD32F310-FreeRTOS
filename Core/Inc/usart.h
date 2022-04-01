#ifndef __USART_H_
#define __USART_H_

#include "main.h"

/**
  * @brief UART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (8 * (OVR8+1) * (huart->Init.BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 8 * (OVR8+1)) + 0.5
                                           Where OVR8 is the "oversampling by 8 mode" configuration bit in the CR1 register. */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_Word_Length */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_Stop_Bits */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Mode */

  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Hardware_Flow_Control */

  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 is enabled or disabled, to achieve higher speed (up to fPCLK/8).
                                           This parameter can be a value of @ref UART_Over_Sampling */
} UART_InitTypeDef;
/**
  * @brief  UART handle Structure definition
  */
typedef struct __UART_HandleTypeDef
{
  uint32_t usart_periph;        /*!< UART registers base address        */
  UART_InitTypeDef Init;             /*!< UART communication parameters      */
} UART_HandleTypeDef;

extern UART_HandleTypeDef usart0;;

extern void My_Usart_Init(void);
extern void My_Usart_MspInit(void);

#endif
