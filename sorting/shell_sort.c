
#include <stdio.h>

void insertion_sort_with_gap (int *array, int a_len, int gap )
{
   int j;

   for ( int i = gap ; i <= a_len ; i++){
       int key = array[i];

       for ( j = i ; j > gap ; j -= gap){
           if (array[j-gap] > key){
              array[j] = array[j-gap];  
           }
           else break;
       } 
       array[j] = key;
   }
}

void shell_sort (int *array, int a_len )
{
    int sub_arr_gap;
    
    if (a_len <= 1 ) return ;

    for ( sub_arr_gap = a_len / 2; sub_arr_gap > 0 ; sub_arr_gap /= 2) {
        insertion_sort_with_gap (array, a_len , sub_arr_gap);
    }
    return ;
}

void print_array (int *array, int len)
{
   for (int idx = 0; idx < len ; idx ++) printf ("%d ", array[idx]);
   putchar('\n');
}

int main ()
{
  int array[] = {1,3,4,5,23,45,23,23412,23};

  print_array(array, sizeof(array)/sizeof(array[0]));
  //insertion_sort_with_gap(array, sizeof(array)/sizeof(array[0]), 1);
  shell_sort(array, sizeof(array)/sizeof(array[0]));
  print_array(array, sizeof(array)/sizeof(array[0]));
}
