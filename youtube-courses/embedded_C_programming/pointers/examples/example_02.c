#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>



int Var_0 = 10;
int Var_1 = 20;
int* const Ptr_0 = &Var_0;
int* const Ptr_1 = &Var_1;

void example_02(void)
{
  *Ptr_0 = 10;
  //Ptr_0 = Ptr_1;
  while(1){
  }
}