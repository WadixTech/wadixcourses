#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm33.h>
#include <arm_cmse.h>
#include <s_image_interface.h>

void example_01_ns(void)
{
  volatile int test = 1;
  while(test == 1){
  }
  
  int tmp = 0;
  tmp = s_image_entry1(5);
  
  if(1 != tmp)
  {
    while(1){
	}
  }
  
  tmp = s_image_entry2(8);
  
  if(2 != tmp)
  {
    while(1){
	}
  }
  
  tmp = s_image_entry3(8);
  
  if(3 != tmp)
  {
    while(1){
	}
  }
   
  while(1){
  }
}