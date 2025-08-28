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

#define PLIC_INT_ENABLE_REG1 *(int*)0xc002000
#define PLIC_INT_ENABLE_REG2 *(int*)0xc002004

#define AON_WDG_TIMER_KEY    *(int*)0x1000001C
#define AON_WDG_TIMER_CFG    *(int*)0x10000000

#define SYSTEM_TIMER_COMPARATOR   *(volatile uint64_t*)0x2004000 
#define SYSTEM_TIMER_COUNTER      *(volatile uint64_t*)0x200bff8

void SystemInit(void)
{
  // disable interrupts
  PLIC_INT_ENABLE_REG1 = 0;
  PLIC_INT_ENABLE_REG2 = 0;
  
  // disable watchdog timer
  AON_WDG_TIMER_KEY = 0x51F15E;
  AON_WDG_TIMER_CFG = 0; 
  
  // disable machine timer interrupt triggering
  SYSTEM_TIMER_COMPARATOR = 0;
  SYSTEM_TIMER_COUNTER = 0;
  
}