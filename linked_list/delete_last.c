
#define get_next (n)   (n)->next


int delete_last (struct node *n )
{
   if (!n || n->next) return false;


   while (n->next->next) {
        n = get_next(n);
   }


   free (n->next); 
   n->next = NULL;

   return 0;
}
