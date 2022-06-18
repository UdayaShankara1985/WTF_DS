
#include "list.h"

void pair_wise_swap (struct node **head)
{
   struct node *prev, *cur, *next, *h; 

   h = cur = *head ; 
   prev = NULL;

   h = get_next (h);
   if (!h) return ;

/*   1--  2 3 4 5 5 */
//   2  1 3
//      1 5 
   while (cur && cur->next) {
       if (prev) 
           prev->next = cur ->next ->next;
       prev = cur;
       next = cur->next;
       next->next = cur;
       cur->next = cur->next->next;
       cur = get_next (cur);
   }
   cur->next = NULL;

   *head = h;
}


main(int argc, char **argv)
{
  int array[] = { 1,2,3, 4, 5,5,5,5, 9 , 11 };
  struct node *head, *n, *end;
  int loop_count = 0;
  bool is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  pair_wise_swap (&head);
  print_list (head);

}

