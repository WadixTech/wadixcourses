#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>


static uint32_t variable_static;
uint32_t variable_global;

void add_fnc(uint32_t incr)
{
  variable_static += incr;
  variable_global += incr+1;
}

void example_02(void)
{
  add_fnc(3);
  add_fnc(10);
  add_fnc(2);
  
  while(1){
  }
}