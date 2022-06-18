#include <stdio.h>
#include "tree.h"

bool tree_mirror(const tree *td1, const tree *td2)
{
    if (td1 == 	NULL && td2 == NULL) return true;
    if (td1 == 	NULL || td2 == NULL) return false;

    if (td1->data != td2->data) return false;
  
    return (tree_mirror (td1->left, td2->right) && tree_mirror (td1->right, td2->left));
    
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


  td1 = create_tree_node (1);
  td1->left = create_tree_node (3);
  td1 ->right = create_tree_node (2);

  td1->left->left = create_tree_node (6);
  td1->left->right = create_tree_node (5);

  td1 ->right->left = create_tree_node (4);
  td1 ->right->right = create_tree_node (3);


  printf ("mirror %d \n", tree_mirror(td, td1));
}




