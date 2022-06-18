#include <stdio.h>
#include "tree.h"

int abs_diff (int a , int b)
{
    int ret;

    ret = ( a > b ) ? a - b : b - a ;
    return ret;
}

int max (int a , int b)
{
   int ret;

   ret = (a > b ) ? a : b;
   return ret;
}

int tree_height (tree *td)
{
   if (!td) return 0;

   return 1 + max(tree_height(td->left) , tree_height(td->right));
}

bool height_balanced (tree *td)
{
   bool ret;
   if (!td) return ;

   ret = (abs_diff(tree_height (td->left), tree_height(td->right)) <= 1) ? true: false;
   return ret;
}

main()
{
  tree *td, *td1; 

  td = create_tree_node (1);
  td->left = create_tree_node (2);
  td ->right = create_tree_node (3);

  td->left->left = create_tree_node (3);
  td->left->right = create_tree_node (4);

  td ->right->left = create_tree_node (5);
  td ->right->right = create_tree_node (6);

  td ->right->right->right  = create_tree_node (6);

  printf ("height balanced %d \n", height_balanced (td));
}




