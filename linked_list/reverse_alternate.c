


int reverse_alternate_group (struct node *head, const int k)
{
    while (current && i < k ) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }

    head->next = current;


   i = k ;
   while (current && i --){
       current = current->next;
   }

   if (current) 
       current->next = reverse_alternate_group (current->next, k);


   return prev;
}
