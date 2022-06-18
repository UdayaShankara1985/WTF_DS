
#include "list.h"

#if 0
int count_nodes_loop (struct node *head)
{
  struct node *n;
  int len = 0;

  for ( n = head, len = 0; n ; ){
     n = get_next (n);
     len ++;
     if (n == head) break;
  }

  if (n) return len ;
  else return -1;
  
}
int list_loop_len (struct node *head)
{
  struct node *fast, *slow;

  slow = fast = head;
  while (slow && fast && fast->next) {
      slow = get_next (slow);
      fast = fast->next->next ;

      if (slow == fast) return count_nodes_loop (slow);
  }

   return -1;
}

#else 

int list_get_len (struct node *head, struct node *beg, struct node *end)
{
  int len ;

  for ( ; beg && beg != end ; beg = get_next(beg)){
      len ++;
  }

  return len ;
}

int list_loop_len (struct node *head)
{
   int prev_len = -1;
   int cur_len = 0;

   struct node *beg, *end;

   beg = end = head;

   while (prev_len < cur_len && beg && end) {
       end = get_next (end);
       prev_len = cur_len ;
       cur_len = list_get_len (head, beg, end);
   }

   if (!end) return -1;
   else return (prev_len - cur_len + 1);
}

#endif

int
main(int argc, char **argv)
{
  int array[] = { 1, 23 ,4,2,3,4,5, 7};
  struct node *head, *n, *end;
  int loop_count = 0;
  int is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  for ( end  = head; end -> next ; end = get_next (end));

  n = head;
  while (loop_count -- ){
     if (n) n = get_next(n);
     else break;
  }

  print_list (n);

  end->next = n;

  is_loop = list_loop_len(head);
  printf ("loop %d \n", is_loop);

}

