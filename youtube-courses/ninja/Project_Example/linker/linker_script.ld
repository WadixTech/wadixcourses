/* Linker script for STM32F4 series Cortex-M4 MCU */

/* Specify memory regions */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 192K
}

/* Entry point */
ENTRY(Reset_Handler)

/* Sections */
SECTIONS
{
    /* Vector table */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH

    /* .text section (code) */
    .text :
    {
        . = ALIGN(4);
        *(.text*)           /* main code */
        *(.rodata*)         /* read-only data */
        *(.glue_7) *(.glue_7t)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(4);
    } > FLASH

    /* .data section (initialized RAM variables) */
    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        _edata = .;
        . = ALIGN(4);
    } > RAM
	
    /* Flash location for initialization values */
    _sidata = LOADADDR(.data);

    /* .bss section (zero-initialized RAM variables) */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
        . = ALIGN(4);
    } > RAM

    /* Stack top (define _estack) */
    _estack = ORIGIN(RAM) + LENGTH(RAM);

    /* Heap (optional) */
    _sheap = _ebss;
    _eheap = ORIGIN(RAM) + LENGTH(RAM);

    /* End of RAM */
    end_of_ram = ORIGIN(RAM) + LENGTH(RAM);
}

/* Symbols exported to startup code */
PROVIDE(_stack_start = _estack);
PROVIDE(_heap_start  = _sheap);
PROVIDE(_heap_end    = _eheap);
