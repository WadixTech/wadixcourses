#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <example_03.h>
#include <core_cm4.h>

inline uint32_t add(int a,int b)
{
  volatile uint32_t res = 0;
  res = *a + *b;
  return res;
}

  
uint32_t result_add = 0;
void example_03(void)
{
  
  result_add = add(10,20);
  
  while(1){
  }
}