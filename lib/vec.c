#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

vec *vec_create(size_t capacity, size_t typeSize)
{
    vec *v = (vec *)malloc(sizeof(vec));
    if (v != NULL)
    {
        v->data = malloc(capacity * typeSize);
        if (v->data == NULL)
        {
            free(v);
            return NULL;
        }
        v->capacity = capacity;
        v->typeSize = typeSize;
        v->length = 0;
    }
    return v;
}
void *vec_get(vec *v, int i)
{
    if (i > v->length || i < 0)
    {
        return NULL;
    }
    return v->data + (i * v->typeSize);
}

/**
 * Inserts a new element at the specified index. If the capacity of the vector is not enough,
 * it doubles its capacity by allocating more memory. If the insertion fails due to insufficient
 * memory, this function returns -1; otherwise, it returns 1.
 *
 * @param v: The vector in which the element will be inserted.
 * @param data: The new element that needs to be inserted.
 * @param i: The index at which the element should be inserted.
 *
 * @return 1 if insertion is successful, -1 if memory allocation fails.
 */
int vec_insert(vec *v, void *data, int i)
{
    if ((void *)data == NULL)
    {
        return 0;
    }

    if (i >= v->capacity)
    {
        v->capacity = v->capacity * 2;
        v->data = realloc(v->data, v->capacity * v->typeSize);

        if (v->data == NULL)
            return -1;
    }

    if (i >= v->length)
    {
        int deltaLength = i - v->length;
        if(deltaLength > 0)
            memset(v->data + (i * v->typeSize), 0, deltaLength * v->typeSize);

        
        v->length += deltaLength + 1;
    }

    void *dest = memmove(v->data + i * v->typeSize, data, v->typeSize);
    if (dest == NULL)
        printf("Error in memmove\n");
    return 1;
};

/**
 * Pushes a new element to the end of the vector. If the capacity of the vector is not enough,
 * it doubles its capacity by allocating more memory. If the insertion fails due to insufficient
 * memory, this function returns -1; otherwise, it returns 1.
 *
 * @param v: The vector in which the element will be inserted.
 * @param data: The new element that needs to be inserted.
 *
 * @return 1 if insertion is successful, -1 if memory allocation fails.
 */
int vec_push(vec *v, void *data)
{
    return vec_insert(v, data, v->length);
};

int vec_insert_front(vec *v, void *data)
{
    return vec_insert(v, data, 0);
};

int vec_set(vec *v, int i, void *value)
{
    if (i > v->length || i < 0)
    {
        return 0;
    }

    if ((void *)value != NULL)
    {
        void *old = vec_get(v, i);
        if (old != NULL)
        {
            free(old);
        }
        memmove(v->data + i * v->typeSize, value, v->typeSize);
        return 1;
    }
    else
    {
        return vec_insert(v, 0, i);
    }
};

int vec_remove(vec *v, int i)
{
    if (i > v->length || i < 0)
    {
        return 0;
    }

    if (!vec_get(v, i))
        return -1;

    // memory is at the end of contiguous address block, so just decrement length.
    if (i == v->length - 1)
    {

        v->length--;
        return 1;
    }

    size_t size = v->typeSize; // get the correct size
    void *dest = memmove(v->data + i * size, v->data + ((i + 1) * size), (v->length - i - 1) * size);

    if (dest == NULL)
        return -1;

    v->length--;
    return 1;
};

int vec_pop(vec *v)
{
    int end = v->length - 1;
    return vec_remove(v, end);
};
int _vec_copy_to_empty(const vec *src, const vec *dest)
{
    if (dest != NULL || src == NULL)
        return 0;

    dest = vec_create(src->capacity, src->typeSize);
    memcpy(dest->data, src->data, src->length * src->typeSize);

    return 1;
}

int vec_copy(const vec *src, vec *dest)
{
    if (src == NULL)
        return 0;

    if (dest == NULL)
        return _vec_copy_to_empty(src, dest);

    if (dest->capacity < src->length || dest->typeSize != src->typeSize)
        return 0;
    memcpy(dest->data, src->data, src->length * src->typeSize);
    dest->length = src->length;
    return 1;
}
