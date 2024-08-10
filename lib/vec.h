#ifndef VEC_H
#define VEC_H
#include <stdlib.h>
#include <string.h>
typedef struct vec vec;

/**
 * @brief 
 *  A dynamic contiguous array of elements. 
 *  Capacity is doubled when full,.
 */

struct vec {
    void* data;
    size_t typeSize, capacity;
    int length;
};

vec* vec_create(size_t size, size_t typeSize);
int vec_insert( vec *v,  void *data, int index);
void* vec_get(vec* v, int index);
void* vec_pop( vec *v);
int vec_push( vec *v,  void *data);
int vec_insert_front( vec *v,  void *data);
int vec_set( vec *v, int i,  void *value);
int vec_remove( vec *v, int i) ;
int vec_copy(const vec *src,  vec *dest);
vec* vec_clone( const vec *v );
void vec_print(vec *v);

#endif