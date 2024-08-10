
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

// node data structure that accepts any data type
struct node
{
    void *data;
    Node *next;
    Node *prev;
};

struct list
{
    Node *head;
    Node *tail;
    int size;
};

/**
 * List functions
 */

List *create_list();
void list_push_back(List *list, void *data);
/**
 * @brief Removes node at pos in O(n/2) time. Or O(1) if pos == size - 1 || pos == 0.
 *
 * @param list
 * @param pos
 * @return int negative if pos is out of bounds. 1 if successful.
 */
int list_remove_at(List *list, int pos);
/**
 * @brief Retrieves node at index in O(n/2) time
 *
 * @param list - list to search in
 * @param index - i-th position of node.
 * @return Node* - node at index
 */
Node *list_find_node(List *list, int index);
/**
 * @brief Retrieves data at index in O(n/2) time
 *
 * @param list
 * @param index
 * @return void*
 */
void *list_get_data(List *list, int index);
/**
 * @brief Frees memory used by list and all nodes.
 *
 * @param list - list to destroy
 */
void list_destroy(List *list);
/**
 * @brief Frees memory used by all nodes. DANGER: Memory used by list is not freed.
 *
 * @param list - list of nodes to clear
 */
void list_clear_nodes(List *list);
void print_list(List *list);

/**
 * Node functions
 *
 */

Node *create_node(void *data, Node *prev, Node *next);
/**
 * @brief Frees memory used by node. DANGER: Destroys memory used by data
 *
 * @param node - node to destroy
 *
 */
void free_node(Node *node);
#endif
