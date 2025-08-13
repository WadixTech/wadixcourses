#include <stdio.h>
#include <stdint.h>
#include <header.h>

void example_02(void)
{
  // call assembly routine to switch to user mode upon execution of mret
  UserMode_Switch();
 
  
  while(1){
  }
 
}
