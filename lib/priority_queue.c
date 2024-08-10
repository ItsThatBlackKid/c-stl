#include "priority_queue.h"

pq *pq_create(int (*compare)(void *, void *), int (*destroy)(void *))
{
    pq *p = malloc(sizeof(pq));
    p->compare = &compare;

    return p;
}

int pq_insert(pq *p, void *data)
{
    if (p == NULL || data == NULL)
    {
        return 0;
    }

    // front of queue == data
    if (p->compare(list_get(p->q->elements, 0), data) == 0)
    {
        return list_push_front(p->q, data);
    }
    // back of queue == data
    else if (p->compare(data, list_get(p->q->elements, p->q->elements->size)) == 0)
    {
        return list_push_back(p->q, data);
    }

    // data is somewhere in the middle of queue
    if(!queue_insert(p->q, data)) return -1;
    list_sort(p->q->elements, p->compare);
    return 1;
}
