#include <stdio.h>
#include "tree.h"

int tree_height (tree *td)
{
   int l, r;
   if (td == NULL) return 0;

   l  = tree_height (td->left);
   r  = tree_height (td->right);
  
   return (l > r) ? l + 1 : r + 1;

}


#include "tree.h"

main()
{
  tree *td; 

  td = create_tree_node (1);
  td->left = create_tree_node (2);
  td ->right = create_tree_node (3);

  td->left->left = create_tree_node (3);
  td->left->right = create_tree_node (4);

  td ->right->left = create_tree_node (5);
  td ->right->right = create_tree_node (6);

  td ->right->right->right  = create_tree_node (6);

  printf ("HEIGHT OF  A TREE %d \n", tree_height (td));
}




