#include "list.h"
#include <stdio.h>
#include <stdlib.h>


struct node *create_node ()
{
  struct node *n ;

  n = (struct node *)malloc (sizeof(struct node));
  if (!n) return NULL;

  n->next = NULL;
  n->data = 0;

  return n;
}

struct node *create_node_val (int val)
{
   struct node *n;

   n = create_node ();
   if (!n) return NULL;

   n->data = val;
   return n;
}

struct node *list_init()
{
   struct node *n ; 

   n = create_node ();
   if (!n) return NULL; 
}


int list_push(struct node **head , int val)
{
  struct node   *n;

  n = create_node();
  n->data = val;

  n->next = *head;
  *head = n;

  return 0;
}

int list_append (struct node *head, int val)
{
   struct node *n, *l;

   n = create_node ();
   n->data = val;

   if (!head) return -1;
   for (l = head ; l && l->next ;l = l->next);
   l->next = n ;

   return 0;
}


struct node * array_to_list (const int *array, int len)
{
  int idx;
  struct node *head; 

  if (len <= 0) return NULL;

  head = create_node_val (array[0]);

  for (idx=1; idx < len ; idx++) {
     list_append (head, array[idx]);
  }

  return head;

}

struct node * get_next (struct node * node)
{
   if (!node) return NULL; 

   return node->next;
}

void print_list_n (struct node *head, char *statement)
{
   if (!head) { printf ("%s no list \n", statement) ; return ;}
   printf ("%s :list data { ", statement);

   while  (head) {
     printf ("%d ", head->data);
     head = head->next;
   }
   printf ("} ");
   printf ("\n");
}

void print_list (struct node *head)
{
   if (!head) { printf ("no list \n") ; return ;}
   printf ("list data { ");

   while  (head) {
     printf ("%d ", head->data);
     head = head->next;
   }
   printf ("} ");
   printf ("\n");
}

