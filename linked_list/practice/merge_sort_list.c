
#include "list.h"


struct node * sorted_merge (struct node *n1, struct node *n2)
{
    struct node *res;

    if (n1 == NULL) return n2;
    else if (n2 = NULL) return n1;

    if (n1->data <= n2->data) {
        res  = n1;
        res->next = sorted_merge (n1->next, n2);
    } else {
        res = n2;
        res->next = sorted_merge (n1, n2->next);
    }

   return res;
}

void
split_list (struct node *head, struct node **first , struct node **second)
{
   struct node *slow, *fast;
   slow = fast = head;


   while (fast) {
      fast = get_next (fast);
      if (fast) {
          slow = get_next (slow);
          fast = get_next (fast);
      }
   }

   *first = head;
   *second = slow->next;
   slow->next = NULL;

   return;
}


void merge_sort (struct node **head)
{
    struct node *list = *head;
    struct node *l1, *l2;

    if (list == NULL || list->next == NULL ) return ;

    split_list (list, &l1, &l2);

    merge_sort (&l1);
    merge_sort (&l2);

    *head = sorted_merge (l1, l2);
}

int
main(int argc, char **argv)
{
  int array[] = { 1, 2,3,4,4,3,2,1 };
  struct node *head, *n, *end;
  int loop_count = 0;
  bool is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  merge_sort (&head);
  print_list (head);
}

