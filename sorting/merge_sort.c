
#include <stdio.h>
#include <stdlib.h>
struct _stack 
{
  int *array;
  int len;
  int *st_ptr;
  int item;
};

struct _stack* create_stack (int len)
{
   struct _stack *st = (struct _stack *)malloc  (sizeof(struct _stack));
   if (!st) return NULL;
  
   st->array = (int*)malloc (sizeof(int) * len);
   if (st->array == NULL) { 
       free (st) ; st = NULL; 
   }
   st->len = len;
   st->st_ptr = st->array;
   st->item = 0;

   return st;
}

void close_stack (struct _stack *st)
{
   free (st->array);
   st->array = NULL;

   free (st) ; st = NULL;
}

int push (struct _stack *st, int data)
{
   st->array[st->item] = data;
   st->item++;

   return 0;
}

int pop (struct _stack *st)
{
   st->item --;
   return st->array[st->item];
}



void merge_arrays ( int *x_array, int x_len, int *y_array, int y_len)
{
   struct _stack *st;
   int *push_ptr;
   int high;
   int max = (x_len > y_len) ? x_len : y_len;

   int *y_a = &y_array[y_len];
   int *x_a = &x_array[x_len];

   int x_l = x_len ; 
   int y_l = y_len;

   st = create_stack (x_len + y_len + 1);

   while (x_l && y_l) {
        push_ptr = (*x_a > *y_a) ? x_a ++ : y_a ++;
        push (st, *push_ptr);
   }
   
   while (x_l){
       --x_l ; push (st, *x_a --);
   }

   while (y_l){
       --y_l ; push (st, *y_a --);
   }

   for ( int idx = 0; idx < (x_len + y_len); idx ++) {
        x_array[idx] = pop (st);
   }
   close_stack (st);
}
