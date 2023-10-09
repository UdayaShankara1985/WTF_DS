/* 
 * quick sort is pivotal based sorting. 
 *  chooses the pivot and partions smaller values to the left and 
 *  greater values to the right and recurse (devide and conquere)
 */


void swap (int *x, int *y)
{
   int z = *y; *y = *x; *x = z;
}


int partition (int *array, int low, int high)
{
   int *pivot = &array[high];

   int min = low - 1;

   for ( int l_iter = low; l_iter < high ; l_iter++){
       if (array[l_iter] < *pivot){
          ++min;
          swap (&array[l_iter], &array[min]);
       }
   }

   swap (&array[++min], pivot);
   return min;
}


void quick_sort (int *array, int low, int high)
{
   
     if (low >= high) return ;

     int pi = partition (array, low, high);
    
     quick_sort (array, 0, pi-1);
     quick_sort (array, pi + 1 , high);
}



void q_sort (int *array, int len)
{
   quick_sort (array, 0, len-1);
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
  q_sort(array, sizeof(array)/sizeof(array[0]));
  print_array(array, sizeof(array)/sizeof(array[0]));
}
