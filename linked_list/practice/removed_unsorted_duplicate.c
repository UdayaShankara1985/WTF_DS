
#include "list.h"

void remove_duplicate (struct node *head)
{
   struct node *ptr1, *ptr2, *tmp;

   ptr1 = ptr2 = head;
   while (ptr1) {
        tmp = ptr1;
        ptr2 = get_next (ptr1);

        while (ptr2) {
           if (ptr2 ->data == ptr1->data) {
               tmp->next = ptr2->next;
               free (ptr2);
               ptr2 = tmp->next;
           } else {
              tmp = ptr2;
              ptr2 = get_next(ptr2);
           }
        }

     ptr1 = get_next (ptr1);
   }
}
    


main(int argc, char **argv)
{
  int array[] = { 1,2,5, 3, 4, 5,5,5,5, 9 , 11 };
  struct node *head, *n, *end;
  int loop_count = 0;
  bool is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  remove_duplicate (head);
  print_list (head);

}

