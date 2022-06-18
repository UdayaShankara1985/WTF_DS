


int rotate_list_from_k (struct node *head, int k )
{

   struct node *new_head;
   struct node *r_head = head;


   while (head && k--){
       head = set_next(head);
   }

   new_head = head; 

   for ( n = new_head; n && n->next ; n = n->next);
   n->next = r_head;

   while (n && n->next) {
       if (n->next == new_head) {
           n->next = NULL; break;
       }

       n = set_next(n);
   }
   
}	
