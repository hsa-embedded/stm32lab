ENTRY(RESET_Handler)

/* Memory configuration for STM32F100xx */

MEMORY
{
  sram (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
  flash (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
}

_end_stack = 0x20002000;


SECTIONS {
    . = ORIGIN(flash);
 
    vectors :
    {
        *(.vectors)
    } >flash

    .text :
    {
        *(.text)
        *(.rodata)
        *(.rodata*)
        _end_text = .;
    } >flash

    .data :
    {
        _start_data = .;
        *(.data)
        _end_data = .;
    } >sram AT >flash 

    . = ALIGN(4);

    .bss :
    {
        _start_bss = .;
        *(.bss)
        _end_bss = .;
    } >sram

    . = ALIGN(4);

    _start_stack = .;
}

_end = .;
PROVIDE(end = .);
