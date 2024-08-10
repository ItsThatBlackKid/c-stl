#include <stdio.h>
#include <stdlib.h>

#include "../lib/linked_list.h"

int compare_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    // example usage of linked liist
    List *list = create_list();
    int *data = malloc(sizeof(int));
    *data = -1;
    list_push_back(list, data);

    for (int i = 10; i > -1; i--)
    {
        int *tempData = malloc(sizeof(int));
        *tempData = i + 1;
        list_push_back(list, tempData);
    }

    print_list(list);

    printf("remove node at pos: 2\n");
    list_remove_at(list, 2);
    print_list(list);

    printf("get data at index 7\n");
    int *retrieved = list_get(list, 7);
    printf("data: %d\n", *retrieved);

    printf("sorting a list\n");
    list_sort(list, &compare_int);
    print_list(list);

    printf("clearing a list\n");
    list_clear_nodes(list);
    print_list(list);

    printf("end of exampes. freeing list\n");
    list_destroy(list);

    return 0;
}