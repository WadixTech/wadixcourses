#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>


uint8_t SPI_Init_V1(void)
{
  return 1;
}

uint8_t SPI_Init_V2(void)
{
  return 2;
}

typedef struct SPI_DRIVER_PTR {
	uint8_t (*Init)(void);
} SPI_DRIVER_PTR;

SPI_DRIVER_PTR SPI_DRV_V1 =
{
  SPI_Init_V1
};

SPI_DRIVER_PTR SPI_DRV_V2 =
{
  SPI_Init_V2
};

SPI_DRIVER_PTR current_spi_driver;

uint8_t result_1 = 0;
uint8_t result_2 = 0;
void example_01(void)
{
  current_spi_driver = SPI_DRV_V1;
  result_1 = current_spi_driver.Init();
  current_spi_driver = SPI_DRV_V2;
  result_2 = current_spi_driver.Init();
  while(1){
  }
}