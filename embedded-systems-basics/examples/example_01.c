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
#include <core_cm3.h>

#define WWDG_IRQ          0
#define WWDG_IRQ_INTID    0

// overwrite default interrupt handler
void Default_IRQHandler(void){
}

void example_01(void)
{
  // configure NVIC to generate WWDG interrupt
  // interrupt will be genetrated using NVIC software method

  // enable interrupt line 0: IRQ 0
  __NVIC_EnableIRQ(WWDG_IRQ);
  
  // set WWDG interrupt pending state to trigger interrupt generation
  __NVIC_SetPendingIRQ(WWDG_IRQ);
  
  // set bit 0 of NVIC STIR register
  //NVIC->STIR = WWDG_IRQ_INTID;
  
  while(1){
  }

}