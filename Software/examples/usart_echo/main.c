/*
# main.c
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

static char buffer[BUFFER_LENTH];

void USART1_Handler()
{
    char rxd = USART_DR;
	
	if (rxd != '\n' && rxd != '\r')
	{
		usart_sendc( rxd );
		write_buffer(rxd, buffer) ;
	}
	else
	{
		usart_sends("\n\r");
		write_buffer('\0', buffer);
		usart_sends(buffer);
		usart_sends("\r\n");
		clear_buffer();
	}
}

int main(void) 
{
    usart_init();
	
    while (1)
    {
        ;
    }
}

