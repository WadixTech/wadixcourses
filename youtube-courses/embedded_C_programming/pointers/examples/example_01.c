#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm3.h>

/* MPU RASR Access Permission (AP) encoding for ARMv7-M:
   0b000: Privileged no access, Unprivileged no access */
#define AP_NO_ACCESS   (0U << 24)

/* MPU RASR Size encoding: SIZE field = log2(region_size) - 1
For 1 Kb (1024 bytes) : log2(1024) = 10, so SIZE = 9 (0b001001)
   Bits [5:1] in RASR hold SIZE. */
#define REGION_SIZE_1024B   ((9U << 1) & 0x3E)

/* Bit positions in RASR */
#define RASR_ENABLE_Pos    0
#define RASR_XN_Pos        28  /* Execute Never */

void example_01(void)
{
    /* 1) Disable MPU */
    MPU->CTRL = 0;

    /* 2) Enable MemManage faults */
    SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;

    /* 3) Select region 0 */
    MPU->RNR = 0;

    /* 4) Set RBAR: base address aligned to region size (512B) */
    MPU->RBAR = 0x20000000U;

    /* 5) Configure RASR:
          - XN = 1 (Execute Never)
          - AP = 0 (No access for privileged/unprivileged)
          - TEX/S/C/B = 0 (Strongly ordered / normal defaults)
          - SRD = 0 (No subregion disable)
          - SIZE = 1024B (encoded as 9)
          - ENABLE = 1
    */
    MPU->RASR =
        (1U << RASR_XN_Pos) |    /* XN = 1 */
        AP_NO_ACCESS        |    /* No access */
        (0U << 19)           |   /* TEX = 0 */
        (0U << 18)           |   /* S = 0 */
        (0U << 17)           |   /* C = 0 */
        (0U << 16)           |   /* B = 0 */
        (0U << 8)            |   /* SRD = 0 */
        REGION_SIZE_1024B     |   /* SIZE field */
        (1U << RASR_ENABLE_Pos); /* Enable region */

    /* 6) Enable MPU with privileged default memory map */
    MPU->CTRL = (1U << 2) |  /* PRIVDEFENA: enable default map for priv. code */
                (1U << 0);   /* ENABLE: enable MPU */
				
    // write access to MPU protected region will trigger Usage Fault
    *(volatile uint32_t*)0x20000000 = 0x12345678;
  
  
    while(1){
    }

}