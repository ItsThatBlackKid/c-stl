#include "queue.h"

queue* queue_create(size_t capacity) {
    queue* q = (queue*)malloc(sizeof(queue));
    if(!q) return NULL;

    q->elements = create_list();
    if(!q->elements) {
        free(q);
        return NULL;
    }

    q->capacity = capacity;
    return q;
}


int queue_push(queue* q, void* data) {
    return list_push_back(q->elements, data);
}

void*  queue_pop(queue* q) {
    return list_pop_front(q->elements);
}

int queue_is_empty(const queue* q) {
    return list_is_empty(q->elements);
}

void queue_destroy(queue* q) {
    list_destroy(q->elements);
    free(q);
}

