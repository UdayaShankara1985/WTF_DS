
#include "list.h"
#include <stdlib.h>

#if 0

struct node * n_th_node_end (struct node *head, int nth)
{
   struct node *end;
   struct node *n;
   int count ;

   n = end = head;

   for ( count = 0; end && count < nth-1 ; end = end->next, count ++);
   print_list (end);
   if (!end) return NULL;

   for ( ; n && end->next ; n = get_next(n), end = get_next(end));
   return n;
}
#endif


struct node *get_nth_node_recursive (struct node *head, int nth, int *count)
{
   struct node *n;
   if (!head)  { (*count) = 0; return NULL; }

   n = get_nth_node_recursive (head->next, nth, count);
   (*count) ++;

   if (*count == nth) return head;
   else return n;

}

struct node * n_th_node_end (struct node *head, int nth)
{
   struct node * n ;
   int count = 0;
   
   n = get_nth_node_recursive (head, nth, &count);
   return n;
}

int
main(int argc, char **argv)
{
  int array[] = { 1, 23 ,4,2,3,4,5};
  struct node *head, *n;
  int count = 0;

  if (argc < 2) return -1;
   
  count = atoi (argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  n = n_th_node_end (head, count);
  if (!n) { printf ("no node \n");  return -1;}

  printf ("data %d \n",  n->data);
}

