# C STL
This is a collection of STL data structures implemented in C.

## Running Examples
The following make targets are available for running the examples:
- `make vec`: builds the vector example program.
    - Run with: `./vec`
- `make list`: builds the list example program.
    - Run with: `./list`



## Data Structures
### Vector ( [vector.h](./lib/vector.h) )
[Vector](https://en.wikipedia.org/wiki/Vector_(data_structure))
A dynamic array data structure that grows and shrinks in size as needed.
- Operations:
    - `vec* vec_create(size_t capacity, int typeSize)`: Creates a vector with the given capacity.
        - typeSize is the size of each element in bytes. Used in pointer arithmetic to determine how many elements are in the array.
        - Returns NULL on error
        - Returns a pointer to the new vector
    - `int vec_insert(vec* v, void* data, int index)`: Inserts an element at index.

    - `void* vec_get(vec* v, int index)`: Gets an element from the vector by its index.
    - `int vec_pop(vec* v)`: Removes and returns the last element in the vector.
    - `int vec_push(vec* v, void* data)`: Adds a new element to the end of the vector.
    - `int vec_push_front(vec* v, void* data)`: Adds a new element to the front of the vector.
    - `int vec_set(vec* v, int index, void* data)`: Sets an existing element in the vector at its given index.
    - `int vec_remove(vec* v, int index)`: Removes and returns a value from the vector by its index.
    - `vec* vec_clone(vec* v)`: Creates a copy of the vector.
- Util functions:
    - `void vec_print(vec* v)`: Prints out each element in the vector, and the vector's properties.


Here is the completed linked list section:

## Linked List ( [linked_list.h](./lib/linked_list.h) )
[Linked List](https://en.wikipedia.org/wiki/Linked_list)
A double linked list data structure that contains a head pointer to the first node of the list, and a tail pointer to the last node in the list.
- Operations:
    - `List* create_list()`: Creates an empty list with no nodes.
    - `void list_push_back(List* list, void* data)`: Inserts a new element at the end of the list.

    - `int list_remove_at(List* list, int pos)`: Removes node at position in O(n/2) time. Or O(1) if pos == size - 1 || pos == 0.
        - Returns negative if pos is out of bounds. 1 if successful.
    - `Node* list_find_node(List* list, int index)`: Retrieves node at index in O(n/2) time.

    - `void* list_get_data(List* list, int index)`: Retrieves data at index in O(n/2) time.
    - `void list_destroy(List* list)`: Frees memory used by list and all nodes.
    - `void list_clear_nodes(List* list)`: Frees memory used by all nodes. DANGER: Memory used by list is not freed.
    - `void print_list(List* list)`: Prints out each element in the list, and the list's properties.

- Util functions:
    - `Node* create_node(void* data, Node* prev, Node* next)`: Creates a new node with the given data and pointers to its previous and next nodes.
    - `void free_node(Node* node)`: Frees memory used by node. DANGER: Destroys memory used by data