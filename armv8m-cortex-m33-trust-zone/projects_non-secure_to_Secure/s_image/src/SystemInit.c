/*
 */

#include <stdio.h>
#include <stdint.h>
#include <header.h>
#define __SAUREGION_PRESENT 1
#define __MPU_PRESENT 1
#include <core_cm33.h>

extern const int   Image$$NS_STACK$$Base;

/* Set up and initialize hardware prior to call to main */
void SystemInit(void)
{
  unsigned int *pSCB_VTOR = (unsigned int *) 0xE000ED08;
  extern void *g_pfnVectors;

  *pSCB_VTOR = (unsigned int) &g_pfnVectors;
  
  // NS image context preparation
  
  // set non-secure top of the stack from secure state
  __TZ_set_SP_NS((uint32_t)&Image$$NS_STACK$$Base);

}