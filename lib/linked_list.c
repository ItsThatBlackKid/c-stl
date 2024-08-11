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

int list_push_back(List *list, void *data)
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

    return 1;
};

int list_push_front(List *list, void *data)
{
    ++list->size;
    if (list->head == NULL)
    {
        return list_push_back(list, data);
    }

    Node *new_node = create_node(data, NULL, list->head);
    list->head->prev = new_node;
    list->head = new_node;

    return 1;
}
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
    node->data = NULL; // free
    free(node);
}
void swap_data(Node *a, Node *b) {
    void *tmp = a->data;
    a->data  = b->data;
    b->data  = tmp;
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
    int pos = reverse ? list->size - 1 : 0;
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

void *list_get(List *list, int index)
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

void *list_remove_at(List *list, int pos)
{
    Node *node = list_find_node(list, pos);
    if (list == NULL || node == NULL)
        return NULL;

    void *data = node->data;
    // set the head or next of the previous node to point at the next one.
    if (node->prev == NULL)
        list->head = node->next;
    else
        node->prev->next = node->next;

    // set the tail or prev of the previous node to point at the previous one.
    if (!node->next)
        list->tail = node->prev;
    else
        node->next->prev = node->prev;

    free_node(node);
    list->size--;
    return data;
}

int list_set(List *list, int pos, void *data)
{
    Node *node = list_find_node(list, pos);

    if (!node)
        return 0;

    node->data = data;
    return 1;
}

int list_empty(List *list)
{
    return !list || !list->head;
};

void *list_pop_front(List *list)
{
    return list_remove_at(list, 0);
};

Node* sorted_merge_nodes(Node* a, Node* b, int (*compare)(void*, void*)) {
    Node* res = NULL;
    if(a == NULL) { return b;}
        else if (b == NULL) {return a;}

    if(compare(a->data, b->data) <=0 ) {
        res = a;
         res->next = sorted_merge_nodes(a->next,b, compare);
         return res;
    } else {
        res = b;
        res->next = sorted_merge_nodes(a,b->next, compare);
    }

    return res;
}

List* sorted_merge(List* a, List* b, List* l1, int (*compare)(void*, void*)) {
    l1->head = sorted_merge_nodes(a->head,b->head, compare);
    return l1;
}

void split_nodes(Node* head, Node** frontRef, Node** rightRef) {
    Node* fast;
    Node* slow;
    slow = head;
    fast = slow->next;

    while (fast != NULL ) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = head;
    *rightRef = slow->next;
     slow->next = NULL;
}

void merge_sort_stuff(Node** headRef, int (*compare)(void*, void*)) {
    Node* head = *headRef;
    Node* left; Node* right;

    if( head == NULL || head->next == NULL) return;

    split_nodes(head,&left,&right);

    merge_sort_stuff(&left, compare);
    merge_sort_stuff(&right,compare);

    *headRef = sorted_merge_nodes(left,right, compare);
}

List *list_detach(List *list, int start, int end)
{
    int range = end - start + 1;
    if (!list || range < 0 || start < 0 || end >= list->size)
        return NULL;
    List *split_list = create_list();

    if (range == 0)
    {
        if (start == 0)
        {
            list_push_front(split_list, list->head->data);
            return split_list;
        }
        else if (end == list->size - 1)
        {
            list_push_back(split_list, list->tail->data);
            return split_list;
        }
    }

    int index = 0;
    Node *curr = list->head;
    while (curr != NULL)
    {
        if (index >= start && index <= end)
        {
            list_push_back(split_list, curr->data);
        }
        curr = curr->next;
        index++;
    }

    return split_list;
}

List *list_split(List *list, int front)
{
    return front ? list_detach(list, 0, (list->size / 2)) : list_detach(list, (list->size / 2) + 1, list->size - 1);
}

List *list_merge(List *list1, List *list2)
{
    List *merged = create_list();
    if (!list1 || !list2 || !merged)
        return NULL;

    merged->head = list1->head;
    merged->tail = list1->tail;
    merged->tail->next = list2->head; // list 1 tail forms the middle of the merged.
    merged->size = (list1->size + list2->size);
    return merged;
}

void list_sort(List *list, int (*cmp)(void *, void *))
{
    if (list_empty(list) || list->head == NULL)
        return;

    merge_sort_stuff(&list->head, cmp);
}