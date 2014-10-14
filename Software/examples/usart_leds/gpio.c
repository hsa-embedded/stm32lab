/*
# gpio.c
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

#include "gpio.h"
#include "register.h"

void gpio_init(void)
{
    // enable PORT B
    RCC_APB2ENR |= (1 << 4);
    
    // PC8 and PC9 as Output PushPull 50Mhz
    GPIOC_CRH = 0x33;
    
    // PC0-3 as Output PushPull 50Mhz
    GPIOC_CRL = 0x3333;

}
