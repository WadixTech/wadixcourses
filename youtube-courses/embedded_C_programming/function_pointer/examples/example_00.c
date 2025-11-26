#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>

int add(int a,int b)
{
  return a+b;
}

int(*funcPtr)(int,int);
  
int result_add = 0;
int result_funcPtr = 0;
void example_00(void)
{
  funcPtr = add;
  
  result_add = add(10,20);
  result_funcPtr = funcPtr(10,20);
  
  while(1){
  }
}