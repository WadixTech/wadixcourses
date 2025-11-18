#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


uint8_t Var_0 = 0x12;
uint32_t Var_1 = 0x12345678;
uint8_t* Ptr_u8 = &Var_0;
uint32_t* Ptr_u32 = &Var_1;
uint32_t tmp = 0;
	
void example_05(void)
{	
  Ptr_u8 = Ptr_u32;
	tmp = *Ptr_u8;
  
  while(1){
  }
}