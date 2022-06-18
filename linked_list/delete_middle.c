


int delete_middle (struct node *head)
{

     struct node *speed_1x, *speed_2x;


     for ( ; speed_2x || speed_2x->next ; ) {
            speed_1x = speed_1x ->next;
            if (speed_2x -> next)
                speed_2x = speed_2x ->next->next;
            else break;
           
     }

     speed_1x->prev->next = speed_1x->next->prev;
     speed_1x->next->prev = speed_1x->prev->next;
     free (speed_1x);

}
