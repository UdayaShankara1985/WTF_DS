

#include <stdio.h>

struct node 
{
  struct node         *next;           // next pointer
  char                data[0];         // data 
};

typedef struct hash__ 
{
   struct node          *array[HASH_MAX];         // hash array 
   int                  (*get_key)(void  *data);  // cb function to get the key 
   int                  size ;                    // size of each member
}HASH;


// ini function 
HASH* init_hash (int max, int (*_get_key)(void *data))
{
   HASH *hash;

   hash = (HASH*)malloc (sizeof (HASH));
   if (!hash) return NULL;

   memset (hash->array, 0, HASH_MAX *sizeof(struct node));
   hash->get_key = _get_key;
 
   return hash;
}

// function to insert value into the hash 
int insert_to_hash (HASH *h, void *data)
{
   int key;
   struct node *n;
   if (!h) return -1;

   key  = h->get_key (data);
   
   n = (struct node *)malloc (sizeof(struct node));
   if (!n) return -2;

   n->next = NULL;   
   memcpy (n->data, data, h->size);
   
   n->next = h->array[key % HASH_MAX];
   h->array[key%HASH_MAX] = n;

   return 0;
}

// fucntion to check the data is present 
bool is_value_present (HASH *h, void *data)
{
   struct node *n;
   if (!h) return NULL;

   key = h->get_key(data);

   for ( n = h->array[key%HASH_MAX] ; n ; n = n->next){
       if (memcmp(n->data, data, h->size) == 0) 
           return true;
   }

   return false;
}




