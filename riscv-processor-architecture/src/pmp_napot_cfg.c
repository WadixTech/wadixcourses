#include <stdio.h>
#include <stdint.h>


__attribute__((always_inline)) void __set_pmp_napot_reg_0(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 0 */ \n\t"
          "csrrs zero, pmpaddr0, a0 \n\t"
          "/* configure pmp cfg0 */ \n\t"
          "csrrs zero, pmpcfg0, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_1(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 1 */ \n\t"
          "csrrs zero, pmpaddr1, a0 \n\t"
          "/* configure pmp cfg0 */ \n\t"
          "csrrs zero, pmpcfg0, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_2(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 2 */ \n\t"
          "csrrs zero, pmpaddr2, a0 \n\t"
          "/* configure pmp cfg0 */ \n\t"
          "csrrs zero, pmpcfg0, a1 \n\t"
          );
}
  
__attribute__((always_inline)) void __set_pmp_napot_reg_3(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 3 */ \n\t"
          "csrrs zero, pmpaddr3, a0 \n\t"
          "/* configure pmp cfg0 */ \n\t"
          "csrrs zero, pmpcfg0, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_4(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 4 */ \n\t"
          "csrrs zero, pmpaddr4, a0 \n\t"
          "/* configure pmp cfg1 */ \n\t"
          "csrrs zero, pmpcfg1, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_5(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 5 */ \n\t"
          "csrrs zero, pmpaddr5, a0 \n\t"
          "/* configure pmp cfg1 */ \n\t"
          "csrrs zero, pmpcfg1, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_6(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 6 */ \n\t"
          "csrrs zero, pmpaddr6, a0 \n\t"
          "/* configure pmp cfg1 */ \n\t"
          "csrrs zero, pmpcfg1, a1 \n\t"
          );
}

__attribute__((always_inline)) void __set_pmp_napot_reg_7(uint32_t addr_encoded, uint32_t config)
{
  
  __asm__("/* configure pmp addr 7 */ \n\t"
          "csrrs zero, pmpaddr7, a0 \n\t"
          "/* configure pmp cfg1 */ \n\t"
          "csrrs zero, pmpcfg1, a1 \n\t"
          );
}
