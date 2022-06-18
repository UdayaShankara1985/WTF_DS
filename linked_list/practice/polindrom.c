
#include "list.h"

bool list_is_polindrom (struct node **left, struct node *right)
{
    bool is_poli;
    if (right == NULL) return true;

    is_poli = list_is_polindrom (left, right->next);
    printf ("left  %d right %d \n", (*left)->data, right->data);
    if (is_poli == true){
        if ((*left)->data == right->data){
            *left = (*left)->next;
            return true;
        }
    }
    
   return false;
}


bool is_polindrom (struct node *head)
{
    list_is_polindrom ( &head, head);
}

int
main(int argc, char **argv)
{
  //int array[] = { 1, 23 ,4,2,3,4,5, 7};
//  int array[] = { 1, 2,3,4,3,2,1 };
  int array[] = { 1, 2,3,4,4,3,2,1 };
  struct node *head, *n, *end;
  int loop_count = 0;
  bool is_loop; 

  if (argc >= 2) loop_count = atoi(argv[1]);

  head = array_to_list (array, sizeof(array)/sizeof(array[0]));
  print_list (head);

  is_loop = is_polindrom(head);
  printf ("loop %d \n", is_loop);
  print_list (head);

}

