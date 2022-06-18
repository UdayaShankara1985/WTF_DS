


#include "tree.h"

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

main()
{
   tree *t;
   int array[] = { 1,2 ,3, 4};

   t = array_to_tree (array, 0, ((sizeof(array)/sizeof (array[0])) - 1));

   print_tree_inorder (t, 0);
   show_matrix ();
}

