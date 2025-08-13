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