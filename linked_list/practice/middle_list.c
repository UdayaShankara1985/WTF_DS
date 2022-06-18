
#include "list.h"

struct node * get_middle (struct node *head)
{
   struct node *fast, *slow;
   if (!head) return NULL;

   slow = fast = head;

   while (fast->next && fast->next->next ){
      slow = get_next (slow);
      fast = fast->next->next;
   }
   return slow;
}


int
main(int argc, char **argv)
{
  int array[] = { 1, 23 ,4,2,3,4,5, 7};
  struct node *head, *n;
  int count = 0;

   

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);
  n = get_middle (head);
  if (n)
    printf("middle node %d \n", n->data);

}

