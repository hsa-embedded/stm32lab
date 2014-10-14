/*
# usart.c
# Copyright (C) 2014 Ferdinand Saufler
# 
# this is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# this software is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "usart.h"
#include "register.h"

void delay(int cnt)
{
    int i;
    for(i=0; i<=cnt; i++)
    {
        __asm__("nop");
    }
}

void usart_sendc(char c)
{
	while(!(USART_SR & (1 << 7)))
	{
	    //wait
	    ;
    }
    USART_DR = c;
}

void usart_sends(char* c)
{
    int i = 0;
    while(c[i] != 0)
    {
        usart_sendc(c[i]);
        i++;
    }
}

void usart_init(void) 
{
    // enable usart1 (bit 14 in APB2ENR)
    RCC_APB2ENR |= (1 << 14);

    // enable port A
    // TX = PA9
    // RX = PA10
    RCC_APB2ENR |= (1 << 2);
    
    // enable AFIO in APB2ENR
    RCC_APB2ENR |= (1 << 0);
    
    // set PA10 Input High Impedance RxD
    //GPIOA_CRH |= (0x8 << 8);
    
    // set PA9 Alternate Function PushPull 50Mhz TxD
    //GPIOA_CRH |= (0xB << 8);
    GPIOA_CRH = 0x8b0;
    // calcualte usartdiv - page 588 reference manual
    // usartdiv = (24e6/9600*16) = 156,25
	
	// calcualtion of fraction
	//16 * 0d0,25 = 4 => 0x04
	
	// calculation of mantissa
	// 0d156 = 0x9C
	
	// in the sum
	// BRR must be 0x9C4
	USART1_BRR = 0x9C4;
	
	// enable TE (tansmit enable) and UE (uart enable)
	USART_CR1 |= (1 << 13) | (1 << 3);
}

