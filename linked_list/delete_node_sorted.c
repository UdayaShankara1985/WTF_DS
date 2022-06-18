

int delete_duplicate_node (struct node *head)
{

    for  (n = head ; n ; ) {
         if (n->next){
             if (n->data == n->next->data){
                 temp => n->next;                 
                 n->next = n->next->next;
                 free (temp);
             }

             n = (n->next) ? n->next : NULL;
         }

         
    }
}
