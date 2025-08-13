
.extern SystemInit
.extern main

  /* reset handler */
  .section .reset_handler, "ax"
  .option norvc;
  
Reset_Entry:
  j reset_handler
  
  /* vector table */
  .section .vectors, "ax"

.global vector_table_base
vector_table_base:
riscv_vector:
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j SystemTimer_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  j default_int_handler
  
  .section .text
  
  .global __main
__main:
  .global reset_handler
reset_handler:
  mv x1, x0
  mv x2, x1
  mv x3, x1
  mv x4, x1
  mv x5, x1
  mv x6, x1
  mv x7, x1
  mv x8, x1
  mv x9, x1
  mv x10, x1
  mv x11, x1
  mv x12, x1
  mv x13, x1
  mv x14, x1
  mv x15, x1
  mv x16, x1
  mv x17, x1
  mv x18, x1
  mv x19, x1
  mv x20, x1
  mv x21, x1
  mv x22, x1
  mv x23, x1
  mv x24, x1
  mv x25, x1
  mv x26, x1
  mv x27, x1
  mv x28, x1
  mv x29, x1
  mv x30, x1
  mv x31, x1

  /* stack initialization */
  la sp, _vStackTop

  /* Initialize global variables from ROM->RAM image */ 
  la t0, _global_data_begin 
  la t1, _sdata 
  la t2, _edata 
  
  bge t1, t2, global_init_loop_end 
  
  global_init_loop: 
    lw t3, 0(t0) 
    sw t3, 0(t1) 
    addi t0, t0, 4 
    addi t1, t1, 4 
    ble t1, t2, global_init_loop 
  global_init_loop_end: 
  
  /* Clear BSS section (uninitialized variables) */ 
  la x26, _bss_start 
  la x27, _bss_end 
  
  bge x26, x27, bss_zero_loop_end 
  
  bss_zero_loop: 
    sw x0, 0(x26) 
    addi x26, x26, 4 
    ble x26, x27, bss_zero_loop 
  bss_zero_loop_end:
  
  
/* SystemInit routine */
SystemInit_entry:
  mv a0, x0  
  mv a1, x0
  jal x1, SystemInit
  
  /* initialize vector table : direct mode : bits[1:0] = 00 */
  la t0, vector_table_base
  li t1, 0x1
  or t2, t0, t1
  csrw mtvec, t2
  
  /* disable locally all interrupts lines */
  li t0, 0b00000000
  csrrs zero, mie, t0
  
  li t0, 0b00000000
  csrrs zero, mip, t0
   
  # /* enable interrupts, set mstatus.MPIE and mstatus.MIE */
  # li t0, 0b10001000
  # csrrs zero, mstatus, t0

/* main jump routine */
main_entry:
  mv a0, x0  
  mv a1, x0
  jal x1, main

  j .  
  
  
.weak default_int_handler
default_int_handler:
j .

SystemTimer_int_handler:
  addi sp, sp, -0x10
  sw ra,  0x00(sp)
  sw a3, 0x04(sp)
  sw a4, 0x08(sp)
  sw a5, 0x0C(sp)
  jal timer_handler
  lw ra,  0x00(sp)
  lw a3, 0x04(sp)
  lw a4, 0x08(sp)
  lw a5, 0x0C(sp)
  addi sp, sp, 0x10
  mret