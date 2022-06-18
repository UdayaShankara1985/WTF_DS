
#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree__m
{
  struct tree__m  *left;
  struct tree__m  *right;

  int data;
}tree;


tree* create_tree_node (int data);

int insert_tree_node (tree *td, int data);

void print_tree_inorder (tree *td,int idx);
tree* array_to_tree (int *array , int low , int high);


#endif
