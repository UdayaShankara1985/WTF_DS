
#include "list.h"

int is_element_present( struct node *head, int val)
{
   if (!head) return false;

   return (head->data == val) ? true : is_element_present (head->next, val) ;
}


int
main()
{
  int array[] = { 1, 23 ,4,2,3,4,5,12,34};

  struct node *head;

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));

  if (is_element_present (head, 12) == 1) printf("present ");
  else printf ("not present");
  
}

