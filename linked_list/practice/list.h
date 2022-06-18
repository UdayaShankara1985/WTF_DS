#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#ifndef __LIST_H__
#define __LIST_H__

struct node 
{
  struct node *next;
  int data;
};


struct node *create_node (void);
struct node *list_init();
int list_push(struct node **n, int val);
int list_append (struct node *head, int val);
struct node *create_node_val (int val);
struct node * array_to_list (const int *array, int len);
struct node * get_next (struct node * node);
void print_list (struct node *head);

#endif
