
#include "tree.h"
#include <stdlib.h>

tree*  create_tree_node (int data)
{
   tree *td;

   td = (tree*)calloc(1, sizeof (tree));
   if (!td)  return NULL;

   td->data = data;

   return td;
}

struct array_matrix
{
  int level[20];
  int l_pos;
}aMatrix[10] = { 0 };


void print_tree_inorder (tree *td,int idx)
{
    if (!td) return ;
    struct array_matrix *a_m;

//    printf("%d \n", td->data);
  
    a_m = &aMatrix[idx]; 

    a_m->level[a_m->l_pos++] = td->data;

    idx ++;
    print_tree_inorder (td->left, idx);
    print_tree_inorder (td->right, idx);
}

void show_matrix ()
{
  int i, j;

  for (i = 0; i < 10; i ++) {
      if (aMatrix[i].level[0] == 0) break;
      for (j = 0; j < 20; j ++) {
          if (aMatrix[i].level[j] == 0) break;
          printf (" %d ", aMatrix[i].level[j]);
      }
      putchar('\n');
 }

 return ;
}

tree* array_to_tree (int *array , int low , int high)
{
    tree *n;
    int mid;

    if (low > high) return NULL;

    mid = ((low  + high) / 2) +  ((low + high) % 2);

    n = create_tree_node (array[mid]);
    
    n->left = array_to_tree (array, low, mid-1);
    n->right = array_to_tree (array, mid + 1, high);

    return n;
}
