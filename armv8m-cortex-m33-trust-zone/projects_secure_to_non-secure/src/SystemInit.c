/*
 */

#include <stdio.h>
#include <stdint.h>

/* Set up and initialize hardware prior to call to main */
void SystemInit(void)
{
	unsigned int *pSCB_VTOR = (unsigned int *) 0xE000ED08;
	extern void *g_pfnVectors;

	*pSCB_VTOR = (unsigned int) &g_pfnVectors;

}