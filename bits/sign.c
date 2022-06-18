
#include <stdio.h>

bool is_positive(int a )
{
   bool sign ;

   sign = ((a >> 31) & 0x01) ? true : false;
   return sign;
}
