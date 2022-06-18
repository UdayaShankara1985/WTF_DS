
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** array;

int
main()
{
   int idx;
   int *ptr;

   array = (int **)malloc(10 * sizeof(int));
   memset (array, 0, 10 * sizeof(int));
   for (idx = 0; idx < 10; idx ++){
        ptr = (int*) malloc(10 * sizeof(int));
        if (!ptr) exit(0);
        memset (ptr, 0, 10 * sizeof(int));
        array[idx] = ptr;
   }


//   **array = 10;

   for (int i = 0; i < 10; i ++){
      printf ("array[%d]: ", i);
      for (int j = 0; j < 10; j ++){
          printf(" %d ", array[i][j]);
      }
      putchar ('\n');
   }

 return 0;
}
