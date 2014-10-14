STM32LIB_ROOT_PATH   = $(STM32LIB_PATH)/STM32LIB

STM32LIB_STARTUPCODE = $(STM32LIB_ROOT_PATH)/startupcode.c
STM32LIB_UART_DEBUG  = $(STM32LIB_ROOT_PATH)/uart_debug.c
STM32LIB_LINKERSCRIPT = $(STM32LIB_ROOT_PATH)/stm32test.ld

PREFIX = arm-none-eabi
CC      = $(PREFIX)-gcc
LD      = $(PREFIX)-ld 
CP      = $(PREFIX)-objcopy
OD      = $(PREFIX)-objdump
  
CFLAGS  =  -I./ -c -fno-common -g  -mcpu=cortex-m3 -mthumb -std=c99 -Wall 
CFLAGS += -mlittle-endian # need it? little-endian ist default !?
CFLAGS += -I/opt/stm32lab/CMSIS/Include
CFLAGS += -D__CHECK_DEVICE_DEFINES
CFLAGS += -DF_CPU=$(F_CPU)


#CFLAGS += --specs=nano.specs -lc -lnosys #TODO Linker ? 

LFLAGS  = -T$(STM32LIB_LINKERSCRIPT) -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

