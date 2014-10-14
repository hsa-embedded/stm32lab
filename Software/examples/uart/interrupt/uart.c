/*
# uart.c
# Copyright (C) 2014 Andreas Schumann
# 
# uart.c is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# uart is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
*/




#include "uart.h"


volatile uint8_t data;



void USART3_Handler(void){

    data = (uint8_t)USART3_DR;
    USART3_DR = data;

    //wait until data has been sent
    while ((USART3_SR & USART_TXE) == 0)
          ;

}


int main(void)
{

    /*
     *  Enable USART3 in RCC_APB1ENR [USART3]
     *  Chapter 6.3.8 on page 91
     *  r/w access
     */

	APB1ENR |= USART3EN;

    /*
     *
     *  Enable PORTB in RCC_APB2ENR[PORTB]
     *  Chapter 6.3.7 on page 89
     *  r/w access
     */

	APB2ENR    |= IOBEN;

    /*
     *  Set GPIO register
     *  Chapter 7.2 on page
     *  PB10 -> TX
     *  PB11 -> RX
     *  r/w access
     */

     //No or !!! -> reset value is not 0
       GPIOB_CRH  = PB10_TX | PB11_RX ;

	/*
	 * Configure UART3
	 * 9600,8n1 Baudrate 9600 [8 Data bits, no Parity, 1 Stop bit]
	 * and a USART3 interrupt is generated whenever a char is received
	 * Enable USART, Transmitter, Receiver and RXNEIE interrupt
	 */

    USART3_BRR |= setBaud(24000000,9600);
    USART3_CR1 |= USART_UE | USART_TE | USART_RE | USART_RXNEIE;



    /*
     *   Enable interrupt for Usart 3
     *   IRQ39       39 mod 32 = 1 REST 7 
     *   Set ISER1[BIT 7] to enable USART3 interrupt
     *
     */

    ISER1 |= IRQ_USART3; //Set interrupt enbale


    while(1){
      //Standby and wake up if an interrupt occurs
       __asm__ volatile ("wfi");
    }

}

/*
vim: et sw=4 ts=4
*/
