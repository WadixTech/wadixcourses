
MEMORY
{
  /* Define each memory region */
  CODE (rx) : ORIGIN = 0x20000000, LENGTH = 0x800000 /* 512 mb bytes */  
  DATA (rwx) : ORIGIN = 0x80000000, LENGTH = 0x1000 /* 4kb bytes*/ 
}

  /* Define a symbol for the top of each memory region */    
  __top_RAM = 0x80000000 + 0x4000 ; /* 12K bytes */    


ENTRY(reset_handler)

SECTIONS
{
     /* MAIN TEXT SECTION */
    .text : ALIGN(4)
    {
        FILL(0xff)
        KEEP(*(.reset_handler))
		. += 0x3C;
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.vectors))
        KEEP(*(.after_vectors*))
		
    } > CODE

    .text : ALIGN(4)
    {
       *(.text*)
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > CODE
 
    . += 0x400;
	
    _etext = .;
	
    _global_data_begin = .;
	
    /* Main DATA section */
    .data : AT(_global_data_begin)
    {
       FILL(0xff)
       _sdata = . ;
       *(.data*)
       *(.data.*)
       *(.sdata)
       . = ALIGN(4) ;
       _edata = . ;
	   _global_data_end = .;
    } > DATA

    /* MAIN BSS SECTION */
    .bss : ALIGN(4)
    {
        _bss_start = .;
        *(.bss*)
        *(.bss.*)
        *(.sbss*)
        *(.sbss.*)
        . = ALIGN(4) ;
        _bss_end = .;
        PROVIDE(end = .);
    } > DATA

    PROVIDE(_vStackTop = DEFINED(__user_stack_top) ? __user_stack_top : __top_RAM - 0);

}