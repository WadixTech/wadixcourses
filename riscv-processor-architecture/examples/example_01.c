#include <stdio.h>
#include <stdint.h>
#include <header.h>


extern void UserMode_Switch(void);
void example_01(void)
{
	
  // call assembly routine to switch to user mode upon execution of mret
  UserMode_Switch();
  
  while(1){
  }
 
}
