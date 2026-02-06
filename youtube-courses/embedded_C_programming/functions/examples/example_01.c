#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <example_01.h>
#include <core_cm4.h>

uint32_t add(int* a,int* b)
{
  volatile uint32_t res = 0;
  res = *a + *b;
  return res;
}

  
uint32_t result_add = 0;
void example_01(void)
{
  int in_0 = 10;
  int in_1 = 10;
  result_add = add(&in_0,&in_1);
  
  while(1){
  }
}