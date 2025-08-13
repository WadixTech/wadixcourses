#include <stdio.h>
#include <stdint.h>
#include <helper.h>

int __attribute__((cmse_nonsecure_entry)) s_image_entry1(int x)
{
  return 1;
}

int __attribute__((cmse_nonsecure_entry)) s_image_entry2(int y)
{
  return 2;
}

int __attribute__((cmse_nonsecure_entry)) s_image_entry3(int z)
{
  return 3;
}