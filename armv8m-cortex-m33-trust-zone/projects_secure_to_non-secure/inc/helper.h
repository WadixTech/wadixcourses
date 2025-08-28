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

#define CALL_FUNCTION(x)         example_##x()
#define DECLARE_FUNCTION(x)      void example_##x(void)
#define EXAMPLE_FUNCTION(x)      DECLARE_FUNCTION(x)
#define CALL_EXAMPLE_FUNCTION(y) CALL_FUNCTION(y)

typedef enum  IRQn_Type {
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn = -11,
  UsageFault_IRQn = -10,
  SecureFault_IRQn = -9,
  SVCall_IRQn = -5,
  DebugMonitor_IRQn = -4,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  IRQ0 = 0,
  IRQ1 = 1
}IRQn_Type;

#define __NVIC_PRIO_BITS 8
#define __MPU_PRESENT    1