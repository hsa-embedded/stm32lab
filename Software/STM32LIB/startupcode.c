/*
# startupcode.c
# Copyright (C) 2014 Andreas Schumann
# 
# startupcode.c is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# startupcode is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "startupcode.h"

   

void Pseudo_Handler(void){ while(1) ; }
 
void RESET_Handler(void)
{

    uint8_t *src, *dst;

    /* Copy data section from FLASH to SRAM */

    src = (uint8_t *)&_end_text;
    dst = (uint8_t *)&_start_data;

    while( dst < (uint8_t *)&_end_data)
    {
       *dst++ = *src ++;
    }

    /* Clear the bss section */

    dst = (uint8_t *)&_start_bss;
    while(dst < (uint8_t *)&_end_bss)
    {
       *dst++ = 0;
    }


#define DEBUG_STM32

#ifdef DEBUG_STM32

    /*
     *  Enable I/O Port A in RCC_APB2ENR
     *  Chapter 6.3.7 on page 89
     *  r/w access
    */

    APB2ENR |= IOPA;

    /*
     *  Set PA8 -> Alternate function push-pull to select MCO,
     *             Page: 109, Table 27
     *  MCO -> PA8
     *  r/w access
     */

    GPIOA_CRH  = MCO_CLK;

#endif //DEBUG_STM32


   /*
    *  Enable HSE and wait until HSE oscillator is ready
    *  Chapter 6.3.1 Page: 77
    *  r/w access
    */

    RCC_CR |= HSE_ON;

    while((RCC_CR & HSE_RDY) == 0)
    	;



   /*
	* Change PLL entry clock source to PREDIV
	* and set PLL multiplication
	* -> HSE * 3 = 8  MHZ * 3 = 24 MHZ
	* -> HSE * 2 = 2  MHZ * 2 = 16 MHZ
	* Page: 79
	*
    */
#if   F_CPU == 16000000UL || F_CPU == 8000000UL

   /*
    * Set multiplication (x2)
    */

    RCC_CFGR |= PLL_SRC;

#elif F_CPU == 24000000UL

   /*
    * Set multiplication (x3)
    */

    RCC_CFGR |= PLL_SRC | PLL_MUL0;

#else
  #error F_CPU not set !
#endif


#if  F_CPU == 8000000UL

   /*
    *  Set division faktor to 2
    *  -> HSE/2 * 2 = 8MHZ
    */
    RCC_CFGR2 |= PREDIV0;

#endif



   /*
    *  Enable PLL and wait until PLL clock is ready (PLL locked) !
    *  Chapter 6.3.1 Page: 77
    *  r/w access
    */

	RCC_CR |= PLL_ON;

    while((RCC_CR & PLL_RDY ) == 0 )
   	;

   /*
    * Set System Clock to PLL  SW[PLL]
    */

    RCC_CFGR |= SW1;


    /*
     * Disable internal 8 MHZ oscillator
     */


    RCC_CR &= ~ HSION;




#ifdef DEBUG_STM32
   /*
    * Set MCO[PLLCLK]   MCO = PLLCLK/2
 	*/

     RCC_CFGR |= (1 << 24) | (1 << 25) | (1 << 26);
    //RCC_CFGR |= (1 << 24)  | (1 << 26);

#endif //DEBUG_STM32

   /*
    *   Note:  HSE is now 24 MHz !
    */
    main();
    while(1)
    {
        ;
    }


}

