

int is_polindrom_rec (struct node ** left, struct node *right)
{
    if (right == NULL ) return TRUE;

    ret = is_polindrom_rec (&left , right->next);
    if (ret != TRUE)  return false;

    if (left->data != right->data)
          return false; 

    *left = (*left)->next;
    return true;
}

// recursive
int is_a_polin (struct node *head)
{
     is_poli = is_polindrom_cur (&head, head);
}



// 
