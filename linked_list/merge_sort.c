

// this is comment 

struct node * sorted_merge (struct node *n1, struct node *n2)
{
  struct node *res;

  if (n1 == NULL) return n2;
  if (n2 == NULL) return n1;


  if (n1->data <= n2->data){
      res  = n1;
      n1->next = sorted_merge (res->next, n2);
  } else {
      res  = n2;
      n2->next = sorted_merge (n1,res->next);
  }

  return res;
}


void split_list (struct node *head, struct node **l_left, struct node *l_right)
{

   *l_left = head;
   *l_right = NULL;

   if (!head) return ;

   speed_2x = get_next (speed_2x);

   while (speed_2x) {
       speed_2x = get_next (speed_2x);
       if (speed_2x->next) {
          speed_2x = get_next (speed_2x);
          speed_1x = get_next (speed_1x);
       }
   }

   *l_right = speed_1x->next;
   speed_1x->next = NULL;

   return ;
}


void  merge_sort (struct node **head )
{
  
    struct node *p1, *p2;

    if (!head || !*head) return ;

    split_list (head, &p1, &p2);

    merge_sort(p1);
    merge_sort(p2);

    *head = sorted_merge (p1, p2);
    return 0;
}


