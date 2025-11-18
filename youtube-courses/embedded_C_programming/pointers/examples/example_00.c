#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>

int Var = 0;
volatile int* Ptr = &Var;

void example_00(void)
{
  *Ptr = 6;
  while(1){
  }
}