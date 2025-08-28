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

#define WEAK __attribute__ ((weak))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
// Declaration of external SystemInit function
extern void SystemInit(void);

//*****************************************************************************
//
// Forward declaration of the default handlers. These are aliased.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void Default_IRQHandler(void);

//*****************************************************************************
//
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//
//*****************************************************************************
extern int main(void);
//*****************************************************************************
//
// External declaration for the pointer to the stack top from the Linker Script
//
//*****************************************************************************
extern const int Image$$STACK$$Base;
extern unsigned int Load$$DATA$$RW$$Base;
extern unsigned int Load$$DATA$$RW$$Length;
extern unsigned int Load$$DATA$$ZI$$Base;
extern unsigned int Load$$DATA$$ZI$$Length;
extern unsigned int Image$$DATA$$RW$$Base;
extern unsigned int Image$$DATA$$RW$$Length;
extern unsigned int Image$$DATA$$ZI$$Base;
extern unsigned int Image$$DATA$$ZI$$Length;

//*****************************************************************************
//
// The vector table.
// This relies on the linker script to place at correct location in memory.
//
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM33
    &Image$$STACK$$Base, // The initial stack pointer
    ResetISR,                                  // The reset handler
    NMI_Handler,                               // The NMI handler
    HardFault_Handler,                         // The hard fault handler
    MemManage_Handler,                         // The MPU fault handler
    BusFault_Handler,                          // The bus fault handler
    UsageFault_Handler,                        // The usage fault handler
    0,                                         // non secure fault handler for the non-secure vector table
    0,                                         // Reserved
    0,                                         // Reserved
    0,                                         // Reserved
    SVC_Handler,                               // SVCall handler
    DebugMon_Handler,                          // Debug monitor handler
    0,                                         // Reserved
    PendSV_Handler,                            // The PendSV handler
    SysTick_Handler,                           // The SysTick handler

    // Chip Level - map to default handler
    Default_IRQHandler,                        // 16, 0x40 
    Default_IRQHandler,                        // 17, 0x44 
    Default_IRQHandler,                        // 18, 0x48 
    Default_IRQHandler,                        // 19, 0x4c 
    Default_IRQHandler,                        // 20, 0x50 
    Default_IRQHandler,                        // 21, 0x54
    Default_IRQHandler,                        // 22, 0x58
    Default_IRQHandler,                        // 23, 0x5c
    Default_IRQHandler,                        // 24, 0x60
    Default_IRQHandler,                        // 25, 0x64
    Default_IRQHandler,                        // 26, 0x68
    Default_IRQHandler,                        // 27, 0x6c
    Default_IRQHandler,                        // 28, 0x70
    Default_IRQHandler,                        // 29, 0x74
    Default_IRQHandler,                        // 30, 0x78
    Default_IRQHandler,                        // 31, 0x7c
    Default_IRQHandler,                        // 32, 0x80
    Default_IRQHandler,                        // 33, 0x84
    Default_IRQHandler,                        // 34, 0x88
    Default_IRQHandler,                        // 35, 0x8c
    Default_IRQHandler,                        // 36, 0x90
    Default_IRQHandler,                        // 37, 0x94
    Default_IRQHandler,                        // 38, 0x98
    Default_IRQHandler,                        // 39, 0x9c
    Default_IRQHandler,                        // 40, 0xA0
    Default_IRQHandler,                        // 41, 0xa4
    Default_IRQHandler,                        // 42, 0xa8
    Default_IRQHandler,                        // 43, 0xac
    Default_IRQHandler,                        // 44, 0xb0
    Default_IRQHandler,                        // 45, 0xb4
    Default_IRQHandler,                        // 46, 0xb8
    Default_IRQHandler,                        // 47, 0xbc
    Default_IRQHandler,                        // 48, 0xc0
    Default_IRQHandler,                        // 49, 0xc4
    Default_IRQHandler,                        // 50, 0xc8
};

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".reset_handler")))
void ResetISR(void) {

  volatile int rwsrc;
  volatile int rwsize;
  volatile int zisrc;
  volatile int zisize;
  
  volatile int rwdst;
  volatile int zidst;
  
  
  // data/bss copy routine
  rwsrc = (volatile unsigned int) &Load$$DATA$$RW$$Base;
  rwsize = (volatile unsigned int) &Load$$DATA$$RW$$Length;
 
  zisrc = (volatile unsigned int) &Load$$DATA$$RW$$Base;
  zisize = (volatile unsigned int) &Image$$DATA$$ZI$$Length;
  
  rwdst = (volatile unsigned int) &Image$$DATA$$RW$$Base;
  zidst = (volatile unsigned int) &Image$$DATA$$ZI$$Base; 

  for (int i = 0; i < rwsize; i++)
  {
    *(volatile int*)(rwdst + i) = *(volatile int*)(rwsrc + i);
  }	  
  
  for (int i = 0; i < zisize; i++)
  {
    *(volatile int*)(zidst + i) = 0;
  }	 
  
  SystemInit();

  // Call the Redlib library, which in turn calls main()
  main() ;

  //
  // main() shouldn't return, but if it does, we'll just enter an infinite loop
  //
  while (1) {
      ;
  }
}

//*****************************************************************************
// Default exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void NMI_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void HardFault_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void MemManage_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void BusFault_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void UsageFault_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void SVC_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void DebugMon_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void PendSV_Handler(void)
{ while(1) {}
}

__attribute__ ((section(".after_vectors")))
void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
//
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void Default_IRQHandler(void)
{ while(1) {}
}