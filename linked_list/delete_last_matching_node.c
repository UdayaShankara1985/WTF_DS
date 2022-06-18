

int delete_last_occ (struct node  ** head, int data)
{

    struct node **n_to_delete = NULL;

     while (*head) {
         if ((*head)->data == data){
             n_to_delete = head;
         }

         head = &(*head)->next;
     }

    if (n_to_delete){
        struct node *n_to_free = *head;
        *head = n_to_free->next;
        free (n_to_free);
    }

    return 0;
}



// function to delete the node 
int delete_last_matching (struct node *head )
{
   struct node *n_to_delete = &dummy;

   if (head->data == data){
        n_to_delete = head;
   }

   while (head->next){
     if (head->next->data == data){
         n_to_delete = head;
     }

   
}
