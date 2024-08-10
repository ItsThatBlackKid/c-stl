#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



Node *createNode(void *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

List *createList() {
    List *newList = malloc(sizeof(Node));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
};

void addNode(List *list, void *data) {
    Node *newNode = createNode(data);
    if (list->head == NULL && list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        (list->size)++;
    };
};

void printList(List *list) {
    int index = 0;
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("Element %d: %d\n", index, *((int* )currentNode->data));
        currentNode = currentNode->next;
        index++;
    };
};

void freeList(List *list) {
    Node *currentNode = list->head;
    while (currentNode!= NULL) {
        free(currentNode);
        currentNode = NULL;
        currentNode = currentNode->next;
    };
    free(list);
};

void freeNode(Node *node) {
    free(node->data);
    free(node);
};

Node *getNode(List *list, int index) {
    if(index < 0 || index >= list->size) {
        return NULL;
    }

    Node *currentNode = list->head;
    for(int i=0; i<index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

int main() {
    // example usage of linked liist
    List *list = createList();
    int *data = malloc(sizeof(int));
    *data = 10;
    addNode(list, data);

    for (int i = 0; i < 10; i++) {
        int *tempData = malloc(sizeof(int));
        *tempData = i + 1;
        addNode(list, tempData);
    }


    printList(list);

    printf("Hello, World!\n");
    return 0;
}
