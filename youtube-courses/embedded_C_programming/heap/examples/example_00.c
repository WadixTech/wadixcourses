#include <stdio.h>
#include <stdint.h>
#include <helper.h>
#include <core_cm4.h>

#define BUFFER_SIZE 5
uint8_t *buffer = NULL;

void example_00(void)
{
  /* Allocate memory from the C heap */
  uint8_t *buffer = (uint8_t *)malloc(BUFFER_SIZE);

  if (buffer == NULL)
  {
      /* Allocation failed: heap exhausted */
      while (1){
      }
  }

  uint8_t index = 0;
  /* Use the allocated memory */
  while (index < BUFFER_SIZE)
  {
    buffer[index++] = index;
  }
  
  /* ... do work with buffer ... */

  /* Free the memory when done */
  free(buffer);
  
  while(1){
  }
}