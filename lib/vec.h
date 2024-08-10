#ifndef VEC_H
#define VEC_H
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 *  A dynamic contiguous array of elements. 
 *  Capacity is doubled when full,.
 */

typedef struct  {
    void* data;
    size_t typeSize, capacity;
    int length;
} vec;

typedef struct {
    vec* grid;
    size_t typeSize; // size of each element in bytes
    size_t rows; // number of rows
    size_t cols; // number of columns
    size_t capacity; // number of elements in the array
    size_t size; // number of elements currently in use
} vec2d;

vec* vec_create(size_t capacity, size_t typeSize);
int vec_insert( vec *v,  void *data, int index);
void* vec_get(vec* v, int index);
void* vec_pop( vec *v);
int vec_push( vec *v,  void *data);
int vec_push_front( vec *v,  void *data);
int vec_set( vec *v, void* data,  int i );
int vec_remove( vec *v, int i) ;
int vec_copy(const vec *src,  vec *dest);
vec* vec_clone( const vec *v );
void vec_print(vec *v);
void vec_print_els(vec *v, int new_line);
void vec2d_print(vec*v );
#endif