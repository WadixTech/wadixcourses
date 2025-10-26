.syntax unified
.cpu cortex-m4
.fpu fpv4-sp-d16
.thumb

/*------------------------------------------------------------------------------
  Vector Table
------------------------------------------------------------------------------*/
.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
    .word _estack             /* Top of Stack */
    .word Reset_Handler       /* Reset Handler */
    .word NMI_Handler
    .word HardFault_Handler
    .word MemManage_Handler
    .word BusFault_Handler
    .word UsageFault_Handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word SVC_Handler
    .word DebugMon_Handler
    .word 0
    .word PendSV_Handler
    .word SysTick_Handler

/*------------------------------------------------------------------------------
  Default Handlers
------------------------------------------------------------------------------*/
.thumb_func
NMI_Handler:       b .
HardFault_Handler: b .
MemManage_Handler: b .
BusFault_Handler:  b .
UsageFault_Handler: b .
SVC_Handler:       b .
DebugMon_Handler:  b .
PendSV_Handler:    b .
SysTick_Handler:   b .

/*------------------------------------------------------------------------------
  Reset Handler
------------------------------------------------------------------------------*/
.thumb_func
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    /* Copy .data from Flash to RAM */
    ldr   r0, =_sdata
    ldr   r1, =_edata
    ldr   r2, =_sidata
1:  
    cmp r0, r1
    bge 2f          /* done when r0 >= r1 */
    ldr r3, [r2], #4
    str r3, [r0], #4
    b 1b
2:

    /* Zero initialize .bss */
    ldr   r0, =_sbss
    ldr   r1, =_ebss
3:
    cmp r0, r1
    bge 4f
    mov r2, #0
    str r2, [r0], #4
    b 3b
4:

    /* Call main() */
    bl main

    /* If main returns, loop forever */
    b .

