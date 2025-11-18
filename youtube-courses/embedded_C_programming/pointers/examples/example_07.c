#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


uint32_t address = 0x20000100;
uint32_t tmp = 0;
	
void example_07(void)
{	
  uint32_t* Ptr_u32 = (uint32_t*)address;
  tmp = *Ptr_u32;
  
  while(1){
  }
}