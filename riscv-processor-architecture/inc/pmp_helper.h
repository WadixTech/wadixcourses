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