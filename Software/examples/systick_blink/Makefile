
# object files
OBJS = systick.o 
OBJS+= startupcode.o

F_CPU=24000000UL

STM32LIB_PATH= ../..
include $(STM32LIB_PATH)/STM32LIB/Makefile

vpath %.c $(STM32LIB_PATH)/STM32LIB
CFLAGS+=  -I$(STM32LIB_PATH)/STM32LIB


TARGET  = mlights


all: elf

elf: $(TARGET).elf
	@ echo "Try to Copy files..."
	$(CP) $(CPFLAGS) $(TARGET).elf $(TARGET).bin
	$(OD) $(ODFLAGS) $(TARGET).elf > $(TARGET).lst

$(TARGET).elf: $(OBJS) $(STM32LIB_LINKERSCRIPT)
	@ echo "Linking..."
	$(CC) $(LFLAGS) -o $(TARGET).elf $(OBJS)

%.o: %.c
	@ echo "Compiling..."
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -f $(TARGET).elf $(TARGET).lst $(TARGET).o $(TARGET).bin
	rm -f *.o
	rm -f openocd.cfg .gdbinit
	
# unbind the stm32 if connected
unbind:
	python3 $(STM32LIB_PATH)/util/unbind.py
	
# flash the stm board
flash:
	rm -f openocd.cfg
	echo "source [find board/stm32vldiscovery.cfg]" > openocd.cfg
	echo "init" >> openocd.cfg
	echo "reset halt" >> openocd.cfg
	echo "flash erase_sector 0 0 last" >> openocd.cfg
	echo "flash write_bank 0 $(TARGET).bin 0" >> openocd.cfg
	echo "reset run" >> openocd.cfg
	echo "shutdown" >> openocd.cfg
	openocd -f openocd.cfg
	
gdbinit:
	rm -f .gdbinit
	echo "set complaints 1" > .gdbinit
	echo "set input-radix 0x10" >> .gdbinit
	echo "set output-radix 0x10" >> .gdbinit
	echo "set endian little" >> .gdbinit
	echo "dir ." >> .gdbinit
	echo "file $(TARGET).elf" >> .gdbinit
	echo "layout split" >> .gdbinit
	echo "target remote localhost:3333" >> .gdbinit
	echo "monitor reset halt" >> .gdbinit
	echo "load" >> .gdbinit

gdb:
	arm-none-eabi-gdb -iex "set auto-load safe-path /" …
	
server:
	openocd -f ../../util/openocd_server.cfg
