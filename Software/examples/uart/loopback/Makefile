SHELl := /bin/bash
STM32LIB_PATH= ../../..
include $(STM32LIB_PATH)/STM32LIB/Makefile

# Target file name (without extension)
TARGET = uart
F_CPU=24000000UL


SRC = $(TARGET).c \
	  $(STM32LIB_STARTUPCODE)
 
all: elf

elf: $(TARGET).elf
	@ echo ""
	@ echo "---------------------"
	@ echo "copying: $(<) -> $(<:.elf=.bin)"
	@ echo "---------------------"
	$(CP) $(CPFLAGS) $(TARGET).elf   $(TARGET).bin
	$(OD) $(ODFLAGS) $(TARGET).elf > $(TARGET).lst
	@ echo ""

$(TARGET).elf: $(SRC:.c=.o) $(STM32LIB_LINKERSCRIPT) 
	@ echo ""
	@ echo "---------------------"
	@ echo "linking: $(SRC:%.c=%.o) "
	@ echo "---------------------"
	$(LD) $(LFLAGS) -o $(TARGET).elf $(SRC:.c=.o) 
	@ echo ""

%.o: %.c 
	@ echo ""
	@ echo "---------------------"
	@ echo "compiling : $(<) -> $(<:.c=.o)"
	@ echo "---------------------"
	$(CC)  $(CFLAGS) -c $< -o $(<:.c=.o)
	@ echo ""


.PHONY: clean
clean:
	rm -f $(TARGET).lst $(TARGET).elf  $(TARGET).bin  $(SRC:.c=.o) 
