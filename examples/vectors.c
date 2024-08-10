#include "../lib/vec.h"
#include <stdio.h>

void vec_print(vec *v) {
    int size = v->length;
    int capacity = v->capacity;

    printf("vec: length=%d, capacity=%d, contents=", size, capacity);

    printf("[");
    for (int i = 0; i < size; ++i) {
        int *data = (int* )vec_get(v, i);
        if (data == NULL) {
            printf("NULL");
        }
        else
            printf("%d",*data);


        if( i != size -1) {
            printf(", ");
        }
    }
    printf("]\n");
}

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

    // //insert at  i > v->capacity > v->length
    // *data = 100;
    // vec_insert(v, data,30);
    // vec_print(v);


    free(data);
    free(v);
}