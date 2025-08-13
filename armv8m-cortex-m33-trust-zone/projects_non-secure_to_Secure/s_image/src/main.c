#include <stdio.h>
#include <stdint.h>
#include <header.h>
#define __SAUREGION_PRESENT 1
#define __MPU_PRESENT 1

#include <core_cm33.h>
#include <arm_cmse.h>


typedef int (*func_pointer)(void);
typedef void __attribute__((cmse_nonsecure_call)) nsfunc(void) ;
nsfunc * FunctionPointer ;

#define NS_IMAGE_ENTRY_ADDR 0x00011001

int main(void)
{  
  // configure SAU regions
  // [0x00010000:0x00020000] --> non-secure
  // [0x20021000:0x20022000] --> non-secure
  // [0x30039000:0x3003A000] --> non-secure callable
  // [0x10000000:0x10010000] --> secure, default settings no SAU needed
  
  #define NS  0u
  #define NSC 1u
  // SAU configuration
  // region number 0 [0x00010000:0x00020000] --> non-secure
  SAU->RNR = 0x00;
  // define base address of SAU region to be configured
  SAU->RBAR = (0x00010000 & SAU_RBAR_BADDR_Msk); 
  // define SAU region limit and mark as non-secure region then enable it
  SAU->RLAR = (0x00020000 & SAU_RLAR_LADDR_Msk) | ((NS << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) | 1U ;

  // region number 1:  [0x20021000:0x20022000] --> non-secure
  SAU->RNR = 0x01;
  // define base address of SAU region to be configured
  SAU->RBAR = (0x20020000 & SAU_RBAR_BADDR_Msk); 
  // define SAU region limit and mark as non-secure region then enable it
  SAU->RLAR = (0x20022000 & SAU_RLAR_LADDR_Msk) | ((NS << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) | 1U ;
  
  // region number 2 [0x20039000:0x2003A000] --> non-secure callable
  SAU->RNR = 0x02; 
  // define base address of SAU region to be configured
  SAU->RBAR = (0x20039000 & SAU_RBAR_BADDR_Msk); 
  // define SAU region limit and mark as non-secure region then enable it
  SAU->RLAR = (0x2003A000 & SAU_RLAR_LADDR_Msk) | ((NSC << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) | 1U ;

  // Enable SAU
  SAU->CTRL = 0x3;
  
  __DSB();
  __ISB();
  
  // jump into NS image entry point (Ns reset handler)
  FunctionPointer = cmse_nsfptr_create( (nsfunc*)((uint32_t)NS_IMAGE_ENTRY_ADDR) );
  
  if (cmse_is_nsfptr(FunctionPointer) )
  {
    FunctionPointer = cmse_check_address_range(FunctionPointer, sizeof(FunctionPointer), CMSE_NONSECURE);
    if (FunctionPointer != NULL)
    {
        FunctionPointer() ;
    }
  }
  
  while(1){
  }
  
  return 0;
}