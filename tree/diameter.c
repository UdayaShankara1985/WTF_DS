#include <stdio.h>
#include "tree.h"


int max (int a, int b )
{
   return (a > b) ? a : b ;
}

int tree_height (tree *td)
{
   int l, r;
   
   if (td == NULL) return 0;

   l  = tree_height (td->left);
   r  = tree_height (td->right);
  
   return (l > r) ? l + 1 : r + 1;

}

int tree_diameter (const tree *td)
{
    if (td == NULL ) return 0;
    int l_height, r_height , l_diameter, r_diameter ;

    l_height = tree_height (td->left);
    r_height = tree_height (td->right);

    l_diameter = tree_diameter (td->left);
    r_diameter = tree_diameter (td->right);

    return ( max( l_height + r_height + 1, max( l_diameter, r_diameter)));
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

  td ->right->right->left = create_tree_node (6);
  td ->right->right->left->left = create_tree_node (6);


  td1 = create_tree_node (1);
  td1->left = create_tree_node (3);
  td1 ->right = create_tree_node (2);

  td1->left->left = create_tree_node (6);
  td1->left->right = create_tree_node (5);

  td1 ->right->left = create_tree_node (4);
  td1 ->right->right = create_tree_node (3);


  print_tree_inorder (td, 0);
  show_matrix ();
  printf ("mirror %d \n", tree_diameter(td));
}




