#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>

void add_fnc(uint32_t incr)
{
  static uint32_t variable;
  varilable += incr;
}

void example_01(void)
{
  add_fnc(3);
  add_fnc(10);
  add_fnc(2);
  
  while(1){
  }
}