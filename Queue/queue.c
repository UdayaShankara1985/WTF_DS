
#include "queue.h"

static void reset_queue( Queue *q)
{
  q->total_no = 0 ;
  q->rear_rp  = q->rear_wp = q->array + (sizeof(int) * q->max);
  q->front_rp = q->front_wp = q->array;

}

Queue* init_queue (int max)
{
   Queue *q ;

   q = (Queue *)malloc (sizeof(Queue) + (sizeof(int) * max));
   if (!q) return q;

   q->total_no = 0;
   q->max = max;
   q->rear_rp  = q->rear_wp = q->array + (sizeof(int) * max);
   q->front_rp = q->front_wp = q->array;


   return q;
}

int enqueue_front (Queue *q, int val)
{
   if (QUEUE_FULL(q)) return 0;

   if (q->front_wp == q->rear_wp){
       return 0;
   }

   *q->front_wp++ = val;

   q->total_no ++;

   return 0;
}

int dequeue_front (Queue *q, int *val)
{
   if (QUEUE_EMPTY(q)) return 0;

   *val = *q->front_rp++;
   q->total_no --;

   if (QUEUE_EMPTY(q)) {
      reset_queue(q);
   }

   return 0;
}

int enqueue_rear(Queue *q, int val)
{
   if (QUEUE_FULL(q)) return 0;

   if (q->front_wp == q->rear_wp){
       return 0;
   }

   *q->rear_wp -- = val;
   q->total_no ++;

   return 0;
}

int dequeue_rear (Queue *q, int *val)
{
   if (QUEUE_EMPTY(q)) return 0;

   *val = *q->rear_rp--;
   q->total_no --;

   if (QUEUE_EMPTY(q)) {
      reset_queue(q);
   }

   return 0;
}
void main()
{
   
}

