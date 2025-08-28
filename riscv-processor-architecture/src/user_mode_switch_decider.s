/*                                                                                 */
/* Copyright (c) 2025 Wadix Technologies                                           */
/*                                                                                 */
/* Licensed under the Apache License, Version 2.0 (the "License");                 */
/* you may not use this file except in compliance with the License.                */
/* You may obtain a copy of the License at                                         */
/*                                                                                 */
/*     http://www.apache.org/licenses/LICENSE-2.0                                  */
/*                                                                                 */
/* Unless required by applicable law or agreed to in writing, software             */
/* distributed under the License is distributed on an "AS IS" BASIS,               */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.        */
/* See the License for the specific language governing permissions and             */
/* limitations under the License.                                                  */
/*                                                                                 */
/* SPDX-License-Identifier: Apache-2.0                                             */ 

.extern user_mode_handler  
  
  /* user mode switch routine from machine mode */
  /* UserMode_Switch */
  .section .text, "ax"

.global UserMode_Switch
UserMode_Switch:
  /* mstatus.mpp = 0 */
  li a0, 0x00
  csrrw x0,mstatus,a0
  
  /* mepc = user_mode_handler */
  la a0, user_mode_handler
  csrw mepc,a0
  /* configure pmp to allow full access to memory while cpu is in user mode */
  li t0, -1
  csrrs zero,pmpaddr7, t0
  li t0,0b00011111000000000000000000000000
  csrrs zero, pmpcfg1, t0
  
  /* mret: we will jump to user mode */
  mret
  