

int reverse_group (struct node * head , int k)
{

   struct node *n  = head;
   int count = 0;


   if (!head) return NULL;

   while(current && count <= k ){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count ++;
   }


   if (next){
       head->next = reverse_group (next, k);
   }

   return prev;

}


