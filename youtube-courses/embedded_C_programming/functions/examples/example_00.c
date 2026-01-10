#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <example_00.h>
#include <core_cm4.h>

uint32_t add(int a,int b)
{
  volatile uint32_t res = 0;
  res = a + b;
  return res;
}

  
uint32_t result_add = 0;
void example_00(void)
{
  
  result_add = add(10,20);
  
  while(1){
  }
}