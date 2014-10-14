/*
# button.c
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

#include "button.h"

int main(void) 
{

    // GPIO Port A and C Clock Enable
    RCC_APB2ENR |= (1 << 2) | (1 << 4);
    
    
    // GPIO PORT C as Output PushPull 50Mhz
    GPIOC_CRH = 0x33333333;
    
    // GPIO Port A as Input, floating Point
    GPIOC_CRL = 0x44444444;

    while (1)
    {
        if(GPIOA_IDR & 1)
        {    
            GPIOC_ODR |= (1 << 8) | (1 << 9);
        }
        else
        {
            GPIOC_ODR &= ~((1 << 8) | (1 << 9));
        }
    }
}
