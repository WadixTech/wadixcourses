#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <example_03.h>
#include <core_cm4.h>


uint32_t result_add = 0;
void example_03(void)
{
  
  result_add = add(10,20);
  
  while(1){
  }
}