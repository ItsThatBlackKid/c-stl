#include <stdio.h>
#include <stdlib.h>

#include "../lib/linked_list.h"

int main()
{
    // example usage of linked liist
    List *list = create_list();
    int *data = malloc(sizeof(int));
    *data = -1;
    list_push_back(list, data);

    for (int i = 0; i < 10; i++)
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
    int* retrieved = list_get_data(list, 7);
    printf("data: %d\n", *retrieved);

    printf("clearing a list\n");
    list_clear_nodes(list);
    print_list(list);

    printf("end of exampes. freeing list\n");
    list_destroy(list);


    return 0;
}