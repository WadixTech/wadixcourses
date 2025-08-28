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
#include <header.h>


#define SYSTEM_TIMER_COMPARATOR   *(volatile uint64_t*)0x2004000 
#define SYSTEM_TIMER_COUNTER      *(volatile uint64_t*)0x200bff8

void timer_handler(void)
{
  volatile uint32_t test = 1;
  while(test == 1){
  }
}

void example_03(void)
{      
  // generate interrupt
  SYSTEM_TIMER_COMPARATOR = 0x0000000000000100; // compare data 0x100
  SYSTEM_TIMER_COUNTER    = 0x0000000000000000; // reset timer counter
 
  // enable interrupt
  __asm__ volatile(" li t0, 0b10000000 \n\t"
                   " csrrs zero, mie, t0"); 
				   
  /* enable interrupts, set mstatus.MPIE and mstatus.MIE */
  __asm__ volatile(" li t0, 0b10001000 \n\t"
                   " csrrs zero, mstatus, t0");
  
  while(1){
  }
 
}
