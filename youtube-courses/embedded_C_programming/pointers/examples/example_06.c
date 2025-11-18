#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


uint32_t Var_0 = 0x12345678;
uint32_t* Ptr_u32 = &Var_0;
uint32_t tmp = 0;
	
void example_06(void)
{	
  tmp = *Ptr_u32;
  uint8_t* Ptr_u8 = (uint8_t*)Ptr_u32;
  tmp = *Ptr_u8;
  
  while(1){
  }
}