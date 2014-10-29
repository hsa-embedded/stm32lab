/*
# uart_debug.c
# Copyright (C) 2014 Andreas Schumann
# 
# uart_debug.c is free software: you can redistribute it and/or modify it
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


#include "uart_debug.h"


void uart_debug_init(void)
{
    /*
     *  Enable USART3 in RCC_APB1ENR [USART3]
     *  Chapter 6.3.8 on page 91
     *  r/w access
     */

    APB1ENR |= USART3EN;

    /*
     *  Enable PORTB in RCC_APB2ENR[PORTB]
     *  Chapter 6.3.7 on page 89
     *  r/w access
     */

    APB2ENR |= IOBEN;

    /*
     *  Set GPIO register
     *  Chapter 7.2 on page
     *  PB10 -> TX
     *  PB11 -> RX
     *  r/w access
     */


    GPIOB_CRH  = (PB10_TX | PB11_RX);


    /*
     * Configure UART3
     * 9600,8n1 Baudrate 9600 [8 Data bits, no Parity, 1 Stop bit]
     *
     * Enable USART, Transmitter and Receiver
     */

    USART3_BRR |= setBaud(24000000,9600);
    USART3_CR1 |= USART_UE | USART_TE | USART_RE ;
}



void uart_debug_putChar(char send_char){

   /*
    *  write char to data register
    */

   USART3_DR = send_char;

   /*
    * wait until data has been sent
    */

   while ((USART3_SR & USART_TXE) == 0)
      ;
}




void uart_debug_putString(char *send_string){

   while(* send_string){
      uart_debug_putChar(* send_string);
      send_string ++;
   }

}




char uart_debug_getChar(void){

    /*
     * wait until data is ready to be received
     */

    while( (USART3_SR &  USART_RXNE ) == 0 )
       ;

    return (char)USART3_DR;


}


/*
vim: et sw=4 ts=4
*/
