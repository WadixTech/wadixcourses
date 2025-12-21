#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>


static uint32_t variable;

void add_fnc(uint32_t incr)
{
  varilable += incr;
}

void example_00(void)
{
  add_fnc(3);
  add_fnc(10);
  add_fnc(2);
  
  while(1){
  }
}