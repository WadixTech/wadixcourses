#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>

uint32_t debug_variable = 0;

void add_fnc(uint32_t incr)
{
  static uint32_t variable;
  variable += incr;
  debug_variable = variable;
}

void example_01(void)
{
  add_fnc(3);
  add_fnc(10);
  add_fnc(2);
  
  while(1){
  }
}