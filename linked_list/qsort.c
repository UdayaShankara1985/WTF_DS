#include <stdio.h>
void swap( int *a, int *b)
{
  int tmp = *b;

  *b = *a; 
  *a = tmp;
}

int partion_sort (int *data, int l, int h)
{
   int piv = data[h];
   int i = l- 1;
   int j;

   for (j = l; j < h ; j++ ){
      if (data[j] > piv) {
         swap (&data[++i], &data[j]);
      }
   }

   swap (&data[i+1], &data[h]);
   return i+1;
}

int qsort (int *data, int low , int high)
{
  int pi;

  if (low >= high) return  0;

  pi = partion_sort (data, low, high);

  qsort (data, low, pi-1);
  qsort (data, pi+1, high);
}

void
main()
{
   int array[] = { 23,4,52,1,34,3};
   
   qsort (array, 0, 5);
   
   for ( int idx = 0 ; idx < (sizeof(array)/sizeof(array[0])) ; idx ++)
         printf("%d ", array[idx]);
   putchar ('\n');
}
