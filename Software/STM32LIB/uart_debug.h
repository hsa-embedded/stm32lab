/*
# uart_debug.h
# Copyright (C) 2014 Andreas Schumann
# 
# uart_debug.h is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# uart_debug is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _UART_DEBUG_H_
#define _UART_DEBUG_H_

   /* Includes: */
   
    #include <stdint.h>

   /* Functions: */

    void    uart_debug_init(void);
    void    uart_debug_putChar(char send_char);
    void    uart_debug_putString(char *send_string);
    char    uart_debug_getChar(void);


   /* Defines: */
    #define APB1ENR     *((volatile unsigned int *) 0x4002101C)
     #define USART3EN                                (1 << 18)

    #define APB2ENR     *((volatile unsigned int *) 0x40021018)
     #define IOBEN                                   (1 << 3)

    #define GPIOB_CRH  *((volatile unsigned int *) 0x40010c04)
     #define PB10_TX                                ( (1 << 8) | (1 << 9) | (1 << 11) )    // ((uint16_t) 0xb00)
     #define PB11_RX                                ( (1 << 14)  )                         //((uint16_t) 0x4000)

    #define USART3_CR1  *((volatile unsigned int *) 0x4000480C)
     #define USART_UE                                (1 << 13)
     #define USART_TE                                (1 << 3)
     #define USART_RE                                (1 << 2)

    #define USART3_BRR  *((volatile unsigned int *) 0x40004808)
     #define setBaud(clock,baud) (clock/baud)

    #define USART3_SR   *((volatile unsigned int *) 0x40004800)
     #define USART_TXE                               (1 << 7)
     #define USART_RXNE                              (1 << 5)

    #define USART3_DR   *((volatile unsigned int *) 0x40004804)



#endif //_UART_H_

/*
vim: et sw=4 ts=4
*/
