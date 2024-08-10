#ifndef QUEUE_H
#define QUEUE_H
#include "vec.h"
#include "linked_list.h"

typedef struct {
    List *elements;
    size_t capacity;
} queue;

queue* queue_create(size_t capacity);
int queue_push(queue *q, void *data);
void* queue_pop(queue *q);
void* queue_front(queue *q);
int queue_is_empty(queue *q);
void queue_destroy(queue *q);

#endif
