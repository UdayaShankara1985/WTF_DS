
#include <stdio.h>
typedef unsigned int uint32_t;


int swap_bits (uint32_t value , int pos1, int pos2)
{
    if (((value >> pos1) & 0x01) ^ (((value >> pos2) & 0x01))){
       value = value ^ (0x1 << pos1);
       value = value ^ (0x1 << pos2);
    }

    return value;
}

void
main()
{
  int val = 0x1 << 5;

  printf ("%d \n", swap_bits (val, 5, 0));
  return ;
}
