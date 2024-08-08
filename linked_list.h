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



