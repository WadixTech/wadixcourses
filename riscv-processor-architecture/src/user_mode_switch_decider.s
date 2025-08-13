.extern user_mode_handler  
  
  /* user mode switch routine from machine mode */
  /* UserMode_Switch */
  .section .text, "ax"

.global UserMode_Switch
UserMode_Switch:
  /* mstatus.mpp = 0 */
  li a0, 0x00
  csrrw x0,mstatus,a0
  
  /* mepc = user_mode_handler */
  la a0, user_mode_handler
  csrw mepc,a0
  /* configure pmp to allow full access to memory while cpu is in user mode */
  li t0, -1
  csrrs zero,pmpaddr7, t0
  li t0,0b00011111000000000000000000000000
  csrrs zero, pmpcfg1, t0
  
  /* mret: we will jump to user mode */
  mret
  