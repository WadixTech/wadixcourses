#include <stdio.h>
#include <stdint.h>


static inline uint32_t add(int a,int b)
{
  volatile uint32_t res = 0;
  res = a + b;
  return res;
}