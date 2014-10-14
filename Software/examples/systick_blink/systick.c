/*
# systick.c
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

#include "systick.h"

// globals
uint32_t in = 0;

void setIRQlimit(unsigned limit)
{
    int r0 = (limit & 0xf) << 4;
    __asm__(" msr BASEPRI, %0"
            : "+r" (r0)
    );
}

void SYSTICK_Handler()
{
    // toggle the blue and green led
    GPIOC_ODR ^= (1 << 8);
    GPIOC_ODR ^= (1 << 9);
}

int main(void) 
{
    //Systick Interrupt Priorität setzen
    setIRQlimit(4);
    
    // System Control Block -> Set Systick Interrupt Enable Priority
    SCB_SHPR3 |= (3 << 20);
    
    // Systick count value
    STK_LOAD = 1000000;    
    
    // GPIO Port C Clock Enable
    RCC_APB2ENR |= (1 << 4);
    
    // GPIO PORT C as Input, Floating Point
    GPIOC_CRH = 0x33333333;
    
    // Systick enable and tick init (enables the systick to work)
    STK_CTRL |= 0x03; 

    while (1)
    {
        ;
    } 
}



