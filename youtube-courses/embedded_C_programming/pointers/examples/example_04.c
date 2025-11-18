#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


uint8_t Var = 4;
uint8_t* Ptr_u8 = &Var;
uint32_t* Ptr_u32 = NULL;
uint32_t tmp = 0;
	
void example_04(void)
{	
  Ptr_u32 = Ptr_u8;
  tmp = *Ptr_u32; --> 32 bits access to 1 byte address aligned = unaligned access!!!
  
  while(1){
  }
}