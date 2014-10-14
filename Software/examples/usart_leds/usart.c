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
#include <string.h>

// line buffer handler functions
static int wrpos = -1;				// write index, points to the last written cell
static int rdpos = -1;				// read index, points to the last read character

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

int write_buffer(char c, char* buffer)
{
	if (wrpos != -1 && wrpos == rdpos)	
		wrpos = rdpos = -1;				
	
	if (wrpos == BUFFER_LENTH -1)		
		return 0;					    

	wrpos++;						    
	buffer[wrpos] = c;
	return 1;
}

int read_buffer(char* buffer)
{
	if (rdpos < wrpos)
	{
		rdpos++;
		return (int) buffer[rdpos];
	}
	return -1;
}

void clear_buffer( void )
{
	wrpos = rdpos = -1;
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
	// and RXNEIE (RX Buffer not empty interrupt enable)
	USART_CR1 |= (1 << 13) | (1 << 5) | (1 << 3) | (1 << 2);
	
	// NVIC config
	// set NVIC interrupt priority
	NVIC_IPR0x |= (2 << 12);
	
	// set NVIC interrupt enable
	NVIC_ISER1 |= (1 << 5);
}
