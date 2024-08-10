#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "linked_list.h"
#include "queue.h"

typedef struct {
    queue* q;
    /**
     * @brief Comparison function for priority queue
     *  Returns -1 if a < b, 0 if a == b, and +1 if a > b
     */
    int (*compare)(const void *, const void *); 
} pq;


pq *pq_create(int (*compare)(const void *, const void *));
void pq_destroy(pq *);
int pq_insert(pq*, void*);
int pq_remove(pq*, void*);
int pq_peek(pq*, void*);
int pq_size(pq*);


#endif
