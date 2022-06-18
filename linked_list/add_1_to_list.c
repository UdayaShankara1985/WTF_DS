
//
//   Programe to add 


struct node * reverese_list (struct node *head)
{
  struct node *prev = NULL, *next = NULL, *current = head;


  while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
  }

  return prev;

}



void add_1_list (struct node *head, const int count)
{

    struct node *l, *n ; 

    l = reverse_list (head);

    for ( n = l ; n ; n = n->next){
       n->data += 1;
       carry = (n->data >= 10) ?  1 : 0;
       n->data %= 10;
    }

    if (carry) { 
          n->next = malloc (struct node);
          if (!n->next) exit(-2);

          n->next->next = NULL;
          n->data = 1;
    }

    h = reverse_list (l);
    return h ;

}

