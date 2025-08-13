#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>

#define WWDG_IRQ          0
#define WWDG_IRQ_INTID    0

// overwrite default interrupt handler
void Default_IRQHandler(void){
}

void example_01(void)
{
  // configure NVIC to generate WWDG interrupt
  // interrupt will be genetrated using NVIC software method

  // enable interrupt line 0: IRQ 0
  __NVIC_EnableIRQ(WWDG_IRQ);
  
  // set WWDG interrupt pending state to trigger interrupt generation
  __NVIC_SetPendingIRQ(WWDG_IRQ);
  
  // set bit 0 of NVIC STIR register
  //NVIC->STIR = WWDG_IRQ_INTID;
  
  while(1){
  }

}