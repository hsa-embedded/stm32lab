/*
# register.h
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

#include <stdint.h>

/*
 * RCC - Reset and Clock Controller
 * Base Address 0x40021000
 */
#define RCC                 *((volatile unsigned int*)0x40021000)
#define RCC_APB2ENR         *((volatile unsigned int*)0x40021018)
#define RCC_CFGR            *((volatile unsigned int*)0x40021004)

/* 
 * GPIO
 */
#define GPIOA               *((volatile unsigned int*)0x40010800)
    #define GPIOA_CRL       *((volatile unsigned int*)0x40010800)
    #define GPIOA_CRH       *((volatile unsigned int*)0x40010804)
    #define GPIOA_IDR       *((volatile unsigned int*)0x40010808)
    #define GPIOA_ODR       *((volatile unsigned int*)0x4001080C)
#define GPIOB               *((volatile unsigned int*)0x40010C00)
    #define GPIOB_CRL       *((volatile unsigned int*)0x40010C00)
    #define GPIOB_CRH       *((volatile unsigned int*)0x40010C04)
    #define GPIOB_IDR       *((volatile unsigned int*)0x40010C08)
    #define GPIOB_ODR       *((volatile unsigned int*)0x40010C0C)
#define GPIOC               *((volatile unsigned int*)0x40011000)
    #define GPIOC_CRL       *((volatile unsigned int*)0x40011000)
    #define GPIOC_CRH       *((volatile unsigned int*)0x40011004)
    #define GPIOC_IDR       *((volatile unsigned int*)0x40011008)
    #define GPIOC_ODR       *((volatile unsigned int*)0x4001100C)

/*
 * System Control Block
 */
#define SCB_SHPR3           *((volatile unsigned int*)0xE000ED20)

/*
 * Systick
 */
#define STK_CTRL            *((volatile unsigned int*)0xE000E010)
#define STK_LOAD            *((volatile unsigned int*)0xE000E014)
#define STK_VAL             *((volatile unsigned int*)0xE000E018)

/*
 * USART
 */
#define USART_CR1          *((volatile unsigned int*)0x4001380C)
#define USART_SR           *((volatile unsigned int*)0x40013800)
#define USART_DR           *((volatile unsigned int*)0x40013804)

/*
 * USART1
 */
#define USART1              *((volatile unsigned int*)0x40013800)
#define USART1_BRR          *((volatile unsigned int*)0x40013808)

/*
 * NVIC
 */
#define NVIC                *((volatile unsigned int*)0xE000E100)
#define NVIC_ISER1          *((volatile unsigned int*)0xE000E104)
#define NVIC_IPR0x          *((volatile unsigned int*)0xE000E424)