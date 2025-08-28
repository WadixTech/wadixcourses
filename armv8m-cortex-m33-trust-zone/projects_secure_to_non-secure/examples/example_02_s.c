/*
 * Copyright (c) 2025 Wadix Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
#include <stdio.h>
#include <stdint.h>
#include <helper.h>

#define __SAUREGION_PRESENT 1
#define __MPU_PRESENT 1

#include <core_cm33.h>
#include <arm_cmse.h>

extern int ns_func_pointer1(void);
extern int ns_func_pointer2(void);
extern int ns_func_pointer3(void);

typedef int (*func_pointer)(void);

func_pointer ns_func_array[3] = {ns_func_pointer1,ns_func_pointer2,ns_func_pointer3};

typedef void __attribute__((cmse_nonsecure_call)) nsfunc(void) ;
nsfunc * FunctionPointer ;

void example_02_s(void)
{
  // state transition switch second scenario:
  // secure --> non-secure: BLXNS to non-secure function
  // non-secure --> secure: BX to FNC_RETURN return value previously updated in LR register upon execution of BLXNS

  // make use of attribute __attribute__((cmse_nonSecure_call))
  // to generate the proper assembly wrapper to jump safely to non-secure code
  
  #define NS  0u
  #define NSC 1u
  // SAU configuration
  // region number 0
  SAU->RNR = 0x00;
  // define base address of SAU region to be configured
  SAU->RBAR = (0x00010000 & SAU_RBAR_BADDR_Msk); 
  // define SAU region limit and mark as non-secure region then enable it
  SAU->RLAR = (0x00020000 & SAU_RLAR_LADDR_Msk) | ((NS << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) | 1U ;

  // Enable SAU
  SAU->CTRL = 0x3;
  
  __DSB();
  __ISB();
  
    
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