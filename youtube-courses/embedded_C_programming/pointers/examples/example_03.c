#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>


int Var = 10;
const int* const Ptr = NULL;

void example_03(void)
{	
  Ptr = &Var;
  //*Ptr = 3;
  while(1){
  }
}