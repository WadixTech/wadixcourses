  /* user mode handler */
  .section .text, "ax"

.global user_mode_handler
user_mode_handler:
  nop
  nop
  nop
  ecall
  j .
  