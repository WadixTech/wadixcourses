#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>

int Var = 10;
const int* Ptr = &Var;

void example_01(void)
{ 
  Var = 20;
  //*Ptr = 20;
  while(1){
  }
}