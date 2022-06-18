
#include <stdio.h>

typedef struct 
{
   int        page_no;
   void      *page_addr;
}hkey_t;

// Cache node 
struct cache_node
{
   struct cache_node     *next;
   struct cache_node     *prev;
   hkey_t                hkey;
   int                   hit_count;
   int                   page_no;
   void                  *cache_bkptr;
   void                  page_data[0];
};

struct hash_node 
{
   struct hash_node    *next;
   hkey_t              h_key;
};


void* hash_get_page (hash_table *h_table , int page_no);
void* hash_insert_page (hash_table *h_table, void *cache_page);
int hash_remove_page (hash_table *h_table, int page_no);

// hash table 
struct hash_table 
{
  int                  hash_max;
  struct hash_node     *cache_node[HASH_MAX];
  int  (*get_key)(void  *cache_page);
};


// Cache table 
typedef struct _cache
{
  struct hash_table   h_table[HASH_MAX];
  struct cache_node   *head;
  int                 hit_count;
  int                 page_fault;
}cache;


cache * cache_init (int cache_size, int hash_size, int (*get_key)(void *page));
int cache_refresh (cache *cache, int page_no);

