#include <stdio.h>
#include <stdint.h>
#include <header.h>


#define SYSTEM_TIMER_COMPARATOR   *(volatile uint64_t*)0x2004000 
#define SYSTEM_TIMER_COUNTER      *(volatile uint64_t*)0x200bff8

void timer_handler(void)
{
  volatile uint32_t test = 1;
  while(test == 1){
  }
}

void example_03(void)
{      
  // generate interrupt
  SYSTEM_TIMER_COMPARATOR = 0x0000000000000100; // compare data 0x100
  SYSTEM_TIMER_COUNTER    = 0x0000000000000000; // reset timer counter
 
  // enable interrupt
  __asm__ volatile(" li t0, 0b10000000 \n\t"
                   " csrrs zero, mie, t0"); 
				   
  /* enable interrupts, set mstatus.MPIE and mstatus.MIE */
  __asm__ volatile(" li t0, 0b10001000 \n\t"
                   " csrrs zero, mstatus, t0");
  
  while(1){
  }
 
}
