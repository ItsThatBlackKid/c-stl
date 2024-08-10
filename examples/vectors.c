#include "../lib/vec.h"
#include <stdio.h>


int main(void)
{
    vec *v = vec_create(10, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
         int *data =malloc(sizeof(int));
        *data = i;
        int pushed = vec_push(v, data);

        if(!pushed) {
            printf("Pushing failed for %d\n",  *data);
        }

        free(data);
    
    }

    vec_print(v);

    // push to back of vector
    int *data = malloc(sizeof(int));
    *data = 111;
    vec_push(v, data);

    vec_print(v);
    vec_remove(v, 10);
    vec_print(v);

    // remove from i-th position
    printf("removing element at 6-th index in array\n");
    vec_remove(v,6);
    vec_print(v);

    // insert at i-th position
    printf("inserting 24 at 6-th index in array\n");
    *data = 24;
    vec_insert(v,data, 6);
    vec_print(v);

    // insert at position greater than v->length;
    printf("insert 14 at 14-th index\n");
    *data = 14;
    vec_insert(v, data,14);
    vec_print(v);

    //insert at  i > v->capacity > v->length
    printf("insert 100 at 30-th index\n");
    *data = 100;
    vec_insert(v, data,30);
    vec_print(v);

    // pop vector
    printf("popping vector\n");
    int *popped = vec_pop(v);
    printf("popped:%d\n", *popped);
    vec_print(v);

    // copy vector
    printf("copying vector\n");
    vec* v2 = vec_clone(v);
    *data = 10;
    vec_push(v2,data);
    printf("original vec: ");
    vec_print(v);
    printf("copied vec: ");
    vec_print(v2);

    free(data);
    free(v);
}