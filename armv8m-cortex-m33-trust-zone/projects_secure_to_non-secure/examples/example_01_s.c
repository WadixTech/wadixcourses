#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm33.h>
#include <arm_cmse.h>

extern int ns_func_pointer1(void);
extern int ns_func_pointer2(void);
extern int ns_func_pointer3(void);

typedef int (*func_pointer)(void);

func_pointer ns_func_array[3] = {ns_func_pointer1,ns_func_pointer2,ns_func_pointer3};

typedef void __attribute__((cmse_nonsecure_call)) nsfunc(void) ;
nsfunc * FunctionPointer ;

void example_01_s(void)
{
  
  // state transition switch second scenario:
  // secure --> non-secure: BLXNS to non-secure function
  // non-secure --> secure: BX to FNC_RETURN return value previously updated in LR register upon execution of BLXNS

  // make use of attribute __attribute__((cmse_nonSecure_call))  
    
  FunctionPointer = cmse_nsfptr_create( (nsfunc*)((uint32_t)ns_func_array[0]) );
  
  if (cmse_is_nsfptr(FunctionPointer) )
  {
    FunctionPointer = cmse_check_address_range(FunctionPointer, sizeof(FunctionPointer), CMSE_NONSECURE);
    if (FunctionPointer != NULL)
    {
        FunctionPointer() ;
    }
  }

   
  while(1){
  }
}