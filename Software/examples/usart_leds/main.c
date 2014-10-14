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
#include "gpio.h"
#include "register.h"

static char buffer[BUFFER_LENTH];
static char led_control[6];

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
		led_control[0] = buffer[0];
		led_control[1] = buffer[1];
		led_control[2] = buffer[2];
		led_control[3] = buffer[3];
		led_control[4] = buffer[4];
		led_control[5] = buffer[5];
		usart_sends("\r\n");
		clear_buffer();
	}
}

int main(void) 
{
    usart_init();
    gpio_init();
    
    /*
     * led_control[0] refers to PC0
     * led_control[0] refers to PC1
     * led_control[0] refers to PC2
     * led_control[0] refers to PC3
     * led_control[0] refers to PC8
     * led_control[0] refers to PC9
     */
     
	
    while (1)
    {
        if(led_control[0] == '0')
        {
            GPIOC_ODR &= ~(1 << 0);
        }
        else
        {
            GPIOC_ODR |= (1 << 0);
        }
        if(led_control[1] == '0')
        {
            GPIOC_ODR &= ~(1 << 1);
        }
        else
        {
            GPIOC_ODR |= (1 << 1);
        }
        if(led_control[2] == '0')
        {
            GPIOC_ODR &= ~(1 << 2);
        }
        else
        {
            GPIOC_ODR |= (1 << 2);
        }
        if(led_control[3] == '0')
        {
            GPIOC_ODR &= ~(1 << 3);
        }
        else
        {
            GPIOC_ODR |= (1 << 3);
        }
        if(led_control[4] == '0')
        {
            GPIOC_ODR &= ~(1 << 8);
        }
        else
        {
            GPIOC_ODR |= (1 << 8);
        }
        if(led_control[5] == '0')
        {
            GPIOC_ODR &= ~(1 << 9);
        }
        else
        {
            GPIOC_ODR |= (1 << 9);
        }
    }
}

