ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1M
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 192K
}

_estack     = ORIGIN(RAM) + LENGTH(RAM);
_stack_size = 128;    /* minimum stack; link fails if .bss + stack exceeds RAM */

SECTIONS
{
    .text :
    {
        . = ALIGN(128);
        KEEP(*(.vectors))
        . = ALIGN(4);
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM

    /* Stack space reservation: the stack grows down from _estack. */
    .stack (NOLOAD) :
    {
        . = ALIGN(8);
        . = . + _stack_size;
    } > RAM
}