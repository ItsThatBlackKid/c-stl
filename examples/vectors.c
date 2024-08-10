#include "../lib/vec.h"
#include <stdio.h>


void vec2d_examples() {
    // 2D vector example:
    vec *tensor = vec_create(10, sizeof(vec) + 5 * sizeof(int)); // 10 rows, 5 cols
    for (int i = 0; i < tensor->capacity; i++)
    {
        vec *row = vec_create(5, sizeof(int)); // 5 cols in each row
        for (int j = 0; j < 5; j++)
        {
            int *data = malloc(sizeof(int));
            *data = i + j;
            vec_push(row, data);
        }
        vec_push(tensor, row);
    }

    vec2d_print(tensor);
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

    // add to the front of vector
    printf("adding 10 at beginning\n");
    *data = 10;
    vec_push_front(v, data);
    vec_print(v);

    //set element at i-th position
    printf("set element at 4-th index\n");
    *data = 25;
    vec_set(v, data, 4);
    vec_print(v);

    // add an element at pos v->capacity * 2 + 1
    printf("adding 44 at position 80\n");
    *data = 44;
    vec_insert(v, data, v->capacity *2  + 1 );
    vec_print(v);

    free(data);
    free(v);


    vec2d_examples();
}