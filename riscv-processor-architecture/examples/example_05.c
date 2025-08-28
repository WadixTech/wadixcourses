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
#include <pmp_helper.h>

void example_05(void)
{
  // PMP configuration: FE310-G002 support 8 regions
  // each region is of minimum size 4 bytes
  
  /* address range to protect against read/write: 0x80001000 -- 0x80003000
     region index: 0
	 address match encoding: napot encoding
  */
  
  // reset the previous pmp regions configurations
  pmp_config_reset();
  
  // try to access the memory before pmp configuration
  *(volatile uint32_t*)0x80001000 = 0x12345678;
  
  // we fill in our region structure
  pmp_reg_t region_cfg;
  region_cfg.low_addr = 0x80001000;
  region_cfg.top_addr = 0x80003000;
  region_cfg.configuration = 0x9C;  // binary : 10011100 --> set lock bit to 1 to enable the check on machine mode access based privilege
  pmp_region_selection(region_cfg, 0);
  
  // try to access the memory after pmp configuration
  *(volatile uint32_t*)0x80000000 = 0x12345678;
  
  while(1){
  }
 
}
