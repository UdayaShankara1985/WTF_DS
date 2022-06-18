
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdlib.h>

#include <stdio.h>

#define QUEUE_FULL(q)    (q->max == q->total_no)
#define QUEUE_EMPTY(q)   (q->total_no == 0)

typedef struct queue 
{
   int total_no;
   int max;
   int *rear_rp;
   int *rear_wp;

   int *front_rp;
   int *front_wp;
   int array[0];
}Queue;


Queue * init_queue( int max);

int enqueue_front (Queue *q, int val);
int dequeue_front (Queue *q, int *val);

int enqeue_rear (Queue *q, int val);
int dequeue_rear (Queue *q, int *val);

#endif

