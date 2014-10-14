/*
# startupcode.h
# Copyright (C) 2014 Andreas Schumann
# 
# startupcode.h is free software: you can redistribute it and/or modify it
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

#ifndef _STARTUPCODE_H_
#define _STARTUPCODE_H_

  /* Includes: */

   #include "stdint.h"

  /* Macros: */

   #define WEAK_ALIAS(a) __attribute__ ((weak,alias(#a)))


  /* Defines: */

   #define APB2ENR    *((volatile unsigned int *) 0x40021018)
    #define IOPA                                    (1 << 2)

   #define GPIOA_CRH  *((volatile unsigned int *) 0x40010804)
    #define MCO_CLK                                0x4444444b

   #define RCC_CR     *((volatile unsigned int *) 0x40021000)
    #define HSE_ON                                  (1 << 16)
    #define HSE_RDY                                 (1 << 17)
    #define PLL_ON                                  (1 << 24)
    #define PLL_RDY                                 (1 << 25)
    #define HSION                                   (1 << 0 )

   #define RCC_CFGR   *((volatile unsigned int *) 0x40021004)
    #define PLL_SRC                                 (1 << 16)
    #define PLL_MUL0                                (1 << 18)
    #define SW1                                     (1 <<  1)
    #define MCO0                                    (1 << 24)
    #define MCO1                                    (1 << 25)
    #define MCO2                                    (1 << 26)

  #define RCC_CFGR2    *((volatile unsigned int *) 0x4002102c)
   #define PREDIV0                                    (1<< 0)

   /* Variables: */

   extern uint32_t _end_stack;
   extern uint32_t _end_text;
   extern uint32_t _start_data;
   extern uint32_t _end_data;
   extern uint32_t _start_bss;
   extern uint32_t _end_bss;

  
   /* Functions: */

   extern int main(void);

   /* Interrupt handlers Prototypes: */
   
   // Cortex M3 CORE handlers
   void RESET_Handler(void);
   void NMI_Handler(void)                WEAK_ALIAS(Pseudo_Handler);
   void HARDFAULT_Handler(void)          WEAK_ALIAS(Pseudo_Handler);
   void MEMMANAGE_Handler(void)          WEAK_ALIAS(Pseudo_Handler);
   void BUSFAULT_Handler(void)           WEAK_ALIAS(Pseudo_Handler);
   void USAGEFAULT_Handler(void)         WEAK_ALIAS(Pseudo_Handler);
   void SVC_Handler(void)                WEAK_ALIAS(Pseudo_Handler);
   void DEBUGMON_Handler(void)           WEAK_ALIAS(Pseudo_Handler);
   void PENDSV_Handler(void)             WEAK_ALIAS(Pseudo_Handler);
   void SYSTICK_Handler(void)            WEAK_ALIAS(Pseudo_Handler);

   // STM32F100xx devices specific handlers
   //Page 129, Chapter 8.1 (NVIC)
   void WWDG_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void PVD(void)                        WEAK_ALIAS(Pseudo_Handler);
   void TAMPER_STAMP(void)               WEAK_ALIAS(Pseudo_Handler);
   void RTC_WKUP_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void FLASH_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void RCC_HANDLER(void)                WEAK_ALIAS(Pseudo_Handler);
   void EXIT0_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void EXIT1_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void EXIT2_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void EXIT3_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void EXIT4_HANDLER(void)              WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH1_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH2_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH3_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH4_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH5_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH6_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void DMA1_CH7_HANDLER(void)           WEAK_ALIAS(Pseudo_Handler);
   void ADC1_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   //Pos. 19 -22 reserved
   void EXTI9_5_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void TIM1_BRK_TIM15_HANDLER(void)     WEAK_ALIAS(Pseudo_Handler);
   void TIM1_UP_TIM16(void)              WEAK_ALIAS(Pseudo_Handler);
   void TIM1_TRG_COM_TIM17_HANDLER(void) WEAK_ALIAS(Pseudo_Handler);
   void TIM1_CC_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void TIM2_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void TIM3_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void TIM4_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void I2C1_EV_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void I2C1_ER_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void I2C2_EV_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void I2C2_ER_HANDLER(void)            WEAK_ALIAS(Pseudo_Handler);
   void SPI1_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void SPI2_HANDLER(void)               WEAK_ALIAS(Pseudo_Handler);
   void USART1_Handler(void)             WEAK_ALIAS(Pseudo_Handler);
   void USART2_Handler(void)             WEAK_ALIAS(Pseudo_Handler);
   void USART3_Handler(void)             WEAK_ALIAS(Pseudo_Handler);
   void EXTI15_10_Handler(void)          WEAK_ALIAS(Pseudo_Handler);
   void RTC_ALARM_Handler(void)          WEAK_ALIAS(Pseudo_Handler);
   void CEC_Handler(void)                WEAK_ALIAS(Pseudo_Handler);
   void TIM12_Handler(void)              WEAK_ALIAS(Pseudo_Handler);
   void TIM13_Handler(void)              WEAK_ALIAS(Pseudo_Handler);
   void TIM14_Handler(void)              WEAK_ALIAS(Pseudo_Handler);
   //Pos. 26 - 29  reserved
   void FSMC_Handler(void)               WEAK_ALIAS(Pseudo_Handler);
   //Pos. 49
   void TIM5_Handler(void)               WEAK_ALIAS(Pseudo_Handler);
   void SPI3_Handler(void)               WEAK_ALIAS(Pseudo_Handler);
   void UART4_Handler(void)              WEAK_ALIAS(Pseudo_Handler);
   void UART5_Handler(void)              WEAK_ALIAS(Pseudo_Handler);
   void TIM6_DAC_Handler(void)           WEAK_ALIAS(Pseudo_Handler);
   void TIM7_Handler(void)               WEAK_ALIAS(Pseudo_Handler);
   void DMA2_CHANNEL1_Handler(void)      WEAK_ALIAS(Pseudo_Handler);
   void DMA2_CHANNEL2_Handler(void)      WEAK_ALIAS(Pseudo_Handler);
   void DMA2_CHANNEL3_Handler(void)      WEAK_ALIAS(Pseudo_Handler);
   void DMA2_CHANNEL4_5_Handler(void)    WEAK_ALIAS(Pseudo_Handler);


   const unsigned int * Interrupt_Vec[]                     // exep.    IRQ
   __attribute__((section("vectors"))) = {
      (const unsigned int *) &_end_stack,                   // 1        -
      (const unsigned int *) RESET_Handler,                 // 2        -14
      (const unsigned int *) NMI_Handler,                   // 3        -13
      (const unsigned int *) HARDFAULT_Handler,             // 4        -12
      (const unsigned int *) MEMMANAGE_Handler,             // 5        -11
      (const unsigned int *) BUSFAULT_Handler, 
      (const unsigned int *) USAGEFAULT_Handler,
                             0,0,0,0, //Reserved
      (const unsigned int *) SVC_Handler,
      (const unsigned int *) DEBUGMON_Handler,
                             0,       //Reserved
      (const unsigned int *) PENDSV_Handler,
      (const unsigned int *) SYSTICK_Handler,               // 15       -1
      
    // STM32F100xx devices specific handlers
      (const unsigned int *) WWDG_HANDLER,                  // 16       0
      (const unsigned int *) PVD,                           // 17       1
      (const unsigned int *) TAMPER_STAMP,
      (const unsigned int *) RTC_WKUP_HANDLER,
      (const unsigned int *) FLASH_HANDLER,                 // 20       4
      (const unsigned int *) RCC_HANDLER,
      (const unsigned int *) EXIT0_HANDLER,
      (const unsigned int *) EXIT1_HANDLER,
      (const unsigned int *) EXIT2_HANDLER,
      (const unsigned int *) EXIT3_HANDLER,
      (const unsigned int *) EXIT4_HANDLER,
      (const unsigned int *) DMA1_CH1_HANDLER,
      (const unsigned int *) DMA1_CH2_HANDLER,
      (const unsigned int *) DMA1_CH3_HANDLER,
      (const unsigned int *) DMA1_CH4_HANDLER,              // 30       14
      (const unsigned int *) DMA1_CH5_HANDLER,
      (const unsigned int *) DMA1_CH6_HANDLER,
      (const unsigned int *) DMA1_CH7_HANDLER,
      (const unsigned int *) ADC1_HANDLER,
                             0,0,0,0, //Reserved
      (const unsigned int *) EXTI9_5_HANDLER,
      (const unsigned int *) TIM1_BRK_TIM15_HANDLER,        // 40       24
      (const unsigned int *) TIM1_UP_TIM16,
      (const unsigned int *) TIM1_TRG_COM_TIM17_HANDLER,
      (const unsigned int *) TIM1_CC_HANDLER,
      (const unsigned int *) TIM2_HANDLER,
      (const unsigned int *) TIM3_HANDLER,
      (const unsigned int *) TIM4_HANDLER,
      (const unsigned int *) I2C1_EV_HANDLER,
      (const unsigned int *) I2C1_ER_HANDLER,
      (const unsigned int *) I2C2_EV_HANDLER,
      (const unsigned int *) I2C2_ER_HANDLER,               // 50       34
      (const unsigned int *) SPI1_HANDLER,                  
      (const unsigned int *) SPI2_HANDLER,
      (const unsigned int *) USART1_Handler,                // 53       37
      (const unsigned int *) USART2_Handler,
      (const unsigned int *) USART3_Handler,
      (const unsigned int *) EXTI15_10_Handler,
      (const unsigned int *) RTC_ALARM_Handler,
      (const unsigned int *) CEC_Handler,
      (const unsigned int *) TIM12_Handler,
      (const unsigned int *) TIM13_Handler,
      (const unsigned int *) TIM14_Handler,
                             0,0, //Reserved
      (const unsigned int *) FSMC_Handler,
                             0, //Reserved
      (const unsigned int *) TIM5_Handler,
      (const unsigned int *) SPI3_Handler,
      (const unsigned int *) UART4_Handler,
      (const unsigned int *) UART5_Handler,
      (const unsigned int *) TIM6_DAC_Handler,
      (const unsigned int *) TIM7_Handler,
      (const unsigned int *) DMA2_CHANNEL1_Handler,
      (const unsigned int *) DMA2_CHANNEL2_Handler,
      (const unsigned int *) DMA2_CHANNEL3_Handler,
      (const unsigned int *) DMA2_CHANNEL4_5_Handler,


    };

 


#endif // __STARTUPCODE_H_
