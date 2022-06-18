

#include "list.h"

int list_count_recursive (struct node *head)
{

  if (head == NULL) return 0;
  
  return 1 + list_count_recursive(head->next);
}



int
main()
{
  struct node *head;
  struct node *n;

  head  = create_node_val (10);
  list_append (head, 20);
  list_append (head, 30);
  list_append (head, 40);
  list_append (head, 50);
  list_append (head, 60);

  printf ("list count %d \n", list_count_recursive (head));
  return 0;
}
