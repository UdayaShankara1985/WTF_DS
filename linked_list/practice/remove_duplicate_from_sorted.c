
#include "list.h"

void remove_duplicate (struct node *head)
{
  struct node *n, *tmp;
   for (n =head ; n ; n = get_next (n)) {
       while (n->next && (n->data == n->next->data)){
           tmp = n->next;
           n->next = n->next->next;
           free (tmp);
       }
   }
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

  remove_duplicate (head);
  print_list (head);

}

