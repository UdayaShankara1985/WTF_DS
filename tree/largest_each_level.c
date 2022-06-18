


#include "tree.h"

int tree_height (tree *td)
{
   int l, r;
   if (td == NULL) return 0;

   l  = tree_height (td->left);
   r  = tree_height (td->right);
  
   return (l > r) ? l + 1 : r + 1;

}


int node_array[100] = {0};


void largest_value_in_each_level(tree *td, int level)
{ 
   if (td == NULL) return;

   if (node_array[level] < td->data) {
      node_array[level] = td->data;
   }

   largest_value_in_each_level (td->left, level + 1);
   largest_value_in_each_level (td->right, level + 1);
}


main()
{
   tree *t;
   int t_height;
   int array[] = { 1,2 ,3, 4, 50, 12,12,342,1,3,231};

   t = array_to_tree (array, 0, ((sizeof(array)/sizeof (array[0])) - 1));

   print_tree_inorder (t, 0);
   show_matrix ();
   largest_value_in_each_level (t, 0);

   t_height = tree_height (t);
   for ( int idx = 0; idx < t_height ; idx ++) {
       printf ("level[%d] : %d \n",idx,  node_array[idx]);
   }
}



return (a > b ) ? a - b  : b - a  ; 
