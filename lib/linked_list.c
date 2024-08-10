#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(void *data, Node *prev, Node *next)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
};

List *create_list()
{
    List *newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
};

void list_push_back(List *list, void *data)
{
    ++list->size;
    if (list->head == NULL)
    {
        list->head = create_node(data, NULL, NULL);
    }
    else if (!list->tail)
    {
        list->tail = create_node(data, list->head, NULL);
        list->head->next = list->tail;
    }
    else
    {
        Node *new_node = create_node(data, list->tail, NULL);
        list->tail->next = new_node;

        list->tail = new_node;
    }
};

void print_list(List *list)
{
    int index = 0;
    Node *currentNode = list->head;
    printf("list: size=%d [", list->size);
    while (currentNode != NULL)
    {
        printf("%d", *((int *)currentNode->data));

        if (index != list->size - 1)
        {
            printf(", ");
        }
        currentNode = currentNode->next;
        index++;
    };
    printf("]\n");
};

void freeList(List *list)
{
    Node *currentNode = list->head;
    while (currentNode != NULL)
    {
        free(currentNode);
        currentNode = NULL;
        currentNode = currentNode->next;
    };
    free(list);
};

void free_node(Node *node)
{
    free(node->data);
    free(node);
};

Node *list_find_node(List *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    if (index == list->size - 1)
    {
        return list->tail;
    }
    else if (index == 0)
    {
        return list->head;
    }

    // decide where to start searching from.
    int reverse = (index > list->size / 2); // splits list in half
    int pos = reverse ? list->size -1: 0;
    Node *curr_node = reverse ? list->tail : list->head;

    // searches either from 0..(n-1)/2 or n..n/2
    while (curr_node != NULL)
    {
        if (pos == index)
            break;

        pos += reverse ? -1 : 1;                                 // determine traversal direction.
        curr_node = reverse ? curr_node->prev : curr_node->next; // traverse from O to n/2 or (n/2 - n -1)
    }

    return curr_node;
}

void *list_get_data(List *list, int index)
{
    Node *node = list_find_node(list, index);
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        return node->data;
    }
};

void list_destroy(List *list)
{
    list_clear_nodes(list);
    free(list);
}

void list_clear_nodes(List *list)
{
    Node *curr = list->head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free_node(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int list_remove_at(List *list, int pos)
{
    Node *node = list_find_node(list, pos);
    if(list == NULL ||  node == NULL) return 0;

    // set the head or next of the previous node to point at the next one.
    if(node->prev == NULL) list->head = node->next;
    else node->prev->next = node->next;

    // set the tail or prev of the previous node to point at the previous one.
    if(!node->next) list->tail = node->prev;
    else node->next->prev = node->prev;

    free_node(node);
    list->size--;
    return 1;
}