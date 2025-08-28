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
#include <math.h>
#include <pmp_helper.h>


__attribute__((always_inline)) void pmp_config_reset(void)
{
  __asm__( "/* Clear address register */"
           "CSRW pmpaddr0, x0 \n\t"
           "CSRW pmpaddr1, x0 \n\t"
           "CSRW pmpaddr2, x0 \n\t"
           "CSRW pmpaddr3, x0 \n\t"
           "CSRW pmpaddr4, x0 \n\t"
           "CSRW pmpaddr5, x0 \n\t"
           "CSRW pmpaddr6, x0 \n\t"
           "CSRW pmpaddr7, x0 \n\t"
		   "/* Clear config registers */"
		   "CSRW pmpcfg0, x0 \n\t"
		   "CSRW pmpcfg1, x0 \n\t"
		   "CSRW pmpcfg2, x0 \n\t"
		   "CSRW pmpcfg3, x0 \n\t"
          );
}

pmp_tor_cfg_ptr pmp_tor_regions_configurations_array[4] = {__set_pmp_tor_reg_0,__set_pmp_tor_reg_1,__set_pmp_tor_reg_2,__set_pmp_tor_reg_3};

// napot callbacks configurations
pmp_napot_cfg_ptr pmp_napot_regions_configurations_array[8] = {__set_pmp_napot_reg_0,__set_pmp_napot_reg_1,__set_pmp_napot_reg_2,__set_pmp_napot_reg_3,
                                                               __set_pmp_napot_reg_4,__set_pmp_napot_reg_5,__set_pmp_napot_reg_6,__set_pmp_napot_reg_7};

uint32_t lockup_regions[8] = {8,24,8,24}; // 4 regions can be configured for 8 pmp regions on tor enoding

uint32_t log2_impl(uint32_t value)
{
  uint32_t result = 0;
  while (value >>= 1) result++; 
  
  return result;
}
void pmp_region_selection(pmp_reg_t region, uint8_t region_nbr)
{
  // napot encoding
  if (((region.configuration >> 3) & 3) == 3)
  {
    uint32_t size = (region.top_addr - region.low_addr);
	uint32_t size_encoding_length = log2_impl(size);
	uint32_t pmp_reg_addr = ((region.low_addr >> (2+(size_encoding_length - 2))) << (size_encoding_length - 2)) | (0xFFFFFFFF >> (32 - (size_encoding_length - 3)))  ;
	uint32_t pmp_reg_cfg = (uint32_t)(region.configuration << ((region_nbr%4)*8));
	pmp_napot_regions_configurations_array[region_nbr](pmp_reg_addr,pmp_reg_cfg);
  }
  
  // tor encoding
  if (((region.configuration >> 3) & 3) == 1)
  { 
    uint32_t pmp_reg_base_addr = (region.low_addr >> 2);
    uint32_t pmp_reg_top_addr = (region.top_addr >> 2);
    uint32_t pmp_reg_cfg = (region.configuration << lockup_regions[region_nbr]);
    pmp_tor_regions_configurations_array[region_nbr](pmp_reg_base_addr,pmp_reg_top_addr,pmp_reg_cfg); 
  }	
  
}