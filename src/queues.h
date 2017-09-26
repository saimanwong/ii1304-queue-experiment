#ifndef QUEUES
#define QUEUES

#define TRUE 1

#define PRIORITY_SIZE 40

#define SINGLY_LINKED_LIST 1
#define DOUBLY_LINKED_LIST 2
#define DOUBLY_LINKED_LIST_AVG 3
#define ARRAY_PRIORITY 4

#include "queues.h"


typedef struct node_t {
#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    struct node_t* next;
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    struct node_t* next;
    struct node_t* previous;
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    struct node_t* next;
    struct node_t* previous;
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    struct node_t* next;
#endif
    int32_t pid;
    double priority;
} node_t;


typedef struct list_t {
#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    node_t* first;
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    node_t* first;
    node_t* last;
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    node_t* first;
    node_t* last;
    double mean;
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    node_t* priority_list[PRIORITY_SIZE + 1];
#endif

    uint32_t size;
} list_t;

void print_list(list_t* list);
list_t* new_queue();
list_t* enqueue(list_t* list, int32_t node, double priority);
int32_t dequeue(list_t* list);
void delete_list(list_t* list);
#endif
