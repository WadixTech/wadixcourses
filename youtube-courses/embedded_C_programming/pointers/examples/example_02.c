#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


// overwrite default WDT interrupt handler
void SysTick_Handler(void){
  while(1){
  }
}

void example_02(void)
{
  volatile int j = 0;
  // set systick reload register
  SysTick->LOAD = 0xFFFFFF;
  // reset systick counter register
  SysTick->VAL   = 0UL;
  
  // Enable SysTick IRQ and SysTick Timer
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;  
				   
	while(1){
	}
}