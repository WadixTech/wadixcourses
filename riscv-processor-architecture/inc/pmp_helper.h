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

typedef struct pmp_reg_t {
	uint32_t low_addr;
	uint32_t top_addr;
	uint32_t configuration;
} pmp_reg_t;


typedef void (*pmp_napot_cfg_ptr)(uint32_t,uint32_t);
typedef void (*pmp_tor_cfg_ptr)(uint32_t,uint32_t,uint32_t);

void pmp_region_selection(pmp_reg_t region, uint8_t region_nbr);

// pmp region address matching tor encoding
void __set_pmp_tor_reg_0(uint32_t pmp_reg_base_addr, uint32_t pmp_reg_top_addr, uint32_t configuration);
void __set_pmp_tor_reg_1(uint32_t pmp_reg_base_addr, uint32_t pmp_reg_top_addr, uint32_t configuration);
void __set_pmp_tor_reg_2(uint32_t pmp_reg_base_addr, uint32_t pmp_reg_top_addr, uint32_t configuration);
void __set_pmp_tor_reg_3(uint32_t pmp_reg_base_addr, uint32_t pmp_reg_top_addr, uint32_t configuration);


// pmp region address matching napot encoding
void __set_pmp_napot_reg_0(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_1(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_2(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_3(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_4(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_5(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_6(uint32_t addr_encoded, uint32_t config);
void __set_pmp_napot_reg_7(uint32_t addr_encoded, uint32_t config);