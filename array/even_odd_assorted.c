
/*   Programe to make all the even number from beg in sorted and odd numbers towards end in descending */

#include <stdio.h>
#include <stdbool.h>

// max array size
#define ARRAY_SIZE(a)   sizeof(a)/sizeof(a[0])

// fucntion to swap the data 
void swap (int *a , int *b);

//
//    function to sort the internal data 
//
int q_sort_internal (int *array, int low, int high, bool is_ascending)
{
    int i, j;
    int piv = array[high];

    i = low - 1; 
    if (low >= high) return low;

    for (j = low; j < high ; j++){ 
        if (is_ascending == true ){
           if (array[j] < piv){
               swap (&array[++i], &array[j]);
           }
        } else {
           if (array[j] > piv){
               swap (&array[++i], &array[j]);
           }
        }
    }

    swap (&array[++i], &array[high]);
    return i;
}


//
//   qsort : function to sort the array element 
//
void qsort(int *array, int low, int high, bool is_asc)
{
   int piv;
   if (low >= high) return ;

   piv = q_sort_internal(array, low, high, is_asc);
   
   qsort(array, low, piv-1, is_asc);
   qsort(array, piv+1, high, is_asc);
   
}

//
//  is_odd : function to check the value is odd 
// 
bool is_odd(int val)
{
   return ((val & 0x01) == 0x01);
} 

//
//  swap : function to swap the data 
/
void swap (int *a , int *b)  struct 
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

//
//   function to sort the value in the array 
//   sort_even_odd 
//
int sort_even_odd (int *array, int low, int high)
{
  int i, j ;

  for ( i = low, j = high ; i < j ; i++ ){
      if (!is_odd(array[i]))  continue;

      for ( ; j > i ; j--){
        if (!is_odd(array[j])) {
           swap (&array[i], &array[j--]); 
           break;
        }
      }
  }

   if (is_odd(array[i]) && i > 0 ) --i;
   return i;
}



void
main()
{
   int array[] = { 5,2,3,9,8,4,12, 24,32,23,2,324,234,2 };
   int n;

   n = sort_even_odd (array, 0, ARRAY_SIZE(array)-1);

   qsort (array, 0, n, true);
   qsort (array, n + 1, ARRAY_SIZE(array) - 1, false);

   for ( int idx = 0; idx < ARRAY_SIZE(array) ; idx ++)
       printf ("%d ", array[idx]);

   putchar('\n');

}


//
//   insert_into_q
//      function to insert into the queue 
//
void insert_into_q (Queue *Q, void *data)
{
    if (!q) return q;

   memcpy (q->w_ptr, data, q->ele_size);
   q->w_ptr += q->ele_size;

   return q;
}
