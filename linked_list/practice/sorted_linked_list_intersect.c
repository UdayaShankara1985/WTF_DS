
#include "list.h"


// head1 =   { x1, x2 ,x3, x8, x9 };
// head2 =   { x2, x3 ,x5 };

#if 0
struct node *sorted_intersect (struct node *head1, struct node *head2)
{
    if ( !head1 || !head2) return NULL;
    struct node *head, list_head ;
    head = &list_head;

    memset (&list_head, 0, sizeof(list_head));

    while (head1 && head2) {
       if (head1->data == head2->data){
          list_append (head, head1->data);
          head1 = get_next (head1); 
          head2 = get_next (head2); 
       }
       else if (head1->data < head2->data) {
           head1 = get_next (head1);
       }  else  
           head2 = get_next (head2);

    }
    return head->next;
}
#endif


void 
get_sorted_node (struct node **head, struct node *n1, struct node *n2)
{
    if (!head || !n1 || !n2) return ;

    if (n1->data < n2->data) 
        return get_sorted_node (head,n1->next, n2);
    else if (n1->data > n2->data)
        return get_sorted_node (head, n1, n2->next);

     list_append (*head, n1->data);
     return get_sorted_node (head, n1->next , n2->next);
}

struct node *sorted_intersect (struct node *head1, struct node *head2)
{
   struct node dummyNode;
   struct node *head = &dummyNode;

   if (!head1 || !head2) return NULL;

   memset (&dummyNode, 0, sizeof(head));
   get_sorted_node (&head, head1, head2);
 
   return head->next;
}


main(int argc, char **argv)
{
  int array1[] = { 1,2,3, 4, 5,6,7,8 };
  int array2[] = { 0,3, 4, 7, 9 };

  struct node *head1,*head2, *new_list;
  int loop_count = 0;
  bool is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head1 = array_to_list (array1, sizeof(array1)/sizeof(array1[0]));
  head2 = array_to_list (array2, sizeof(array2)/sizeof(array2[0]));

  print_list (head1);
  print_list (head2);

  new_list = sorted_intersect (head1, head2);
  print_list (new_list);

}

