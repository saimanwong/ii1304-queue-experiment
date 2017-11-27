#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <sys/types.h>
#include "queues.h"

/*
 * Prints out the entire list
 */
void print_list(list_t* list) {
#if DATA_STRUCTURE == ARRAY_PRIORITY
    int i;
    node_t* current;
    for(i = 0; i <= PRIORITY_SIZE; i++) {
        current = list->priority_list[i];
        while(current != NULL) {
            printf("%d %f\n", current->pid, current->priority);
            current = current->next;
        }
    }
#else
    node_t* current = list->first;
    while(current != NULL) {
        printf("%d %f\n", current->pid, current->priority);
        current = current->next;
    }
#endif
}

list_t* new_queue() {
#if DATA_STRUCTURE == ARRAY_PRIORITY
    int i;
#endif

    list_t* list = malloc(sizeof(list_t));
    list->size = 0;

#if DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    list->mean = 0;
#endif

#if DATA_STRUCTURE == ARRAY_PRIORITY
    for(i = 0; i <= PRIORITY_SIZE; i++) {
        list->priority_list[i] = NULL;
    }
#endif
    return list;
}


/*
 * Delete the entire list
 */
void delete_list(list_t* list) {
    node_t* to_remove;

#if DATA_STRUCTURE != ARRAY_PRIORITY
    if(list->size > 0) {
        to_remove = list->first;
        list->first = list->first->next;
        free(to_remove);
        list->size--;
        delete_list(list);
    }
    else {
        free(list);
    }

#else

    int i;
    node_t* current;
    for(i = 0; i <= PRIORITY_SIZE; i++) {
        current = list->priority_list[i];
        while(current != NULL) {
            to_remove = current;
            current = current->next;
            list->size--;
            free(to_remove);
        }
    }
    free(list);
#endif



}


#if HELPER_FUNCTION
void helper_remove(list_t* list) {
    node_t* to_remove = NULL;
    if(list->first == list->last) {
        /*
         * It was the last node in the list.
         */
        assert(list->size == 0);
        free(list->first);
        list->first = NULL;
        list->last = NULL;
    }
    else{
        /*
         * Repoint and free the memory allocation.
         */
        to_remove = list->first;
        list->first = list->first->next;
        free(to_remove);
    }
}
#endif

/*
 * Dequeues the element with highest priority (low numerical value)
 */
int32_t dequeue(list_t* list) {
    int32_t to_return = 0;
#if DATA_STRUCTURE == ARRAY_PRIORITY
    int i;
    node_t* to_remove;
    for(i = 0; i <= PRIORITY_SIZE; i++) {
        to_remove = list->priority_list[i];
        if(to_remove != NULL) {
            to_return = to_remove->pid;
            list->priority_list[i] = list->priority_list[i]->next;
            free(to_remove);
            list->size--;
            break;
        }
    }
#endif

#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    node_t* to_remove;
    if(list->first != NULL) {
        to_return = list->first->pid;
    }
    else {
        assert(list->size == 0);
        free(list->first);
        list->first = NULL;

        return -1;
    }

    to_remove = list->first;
    list->first = list->first->next;
    free(to_remove);
    list->size--;
#endif

#if DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    if(list->first) {
        /*
         * There is a node to dequeue.
         */
        to_return = list->first->pid;
        if(list->first == list->last) {
            list->mean = list->first->priority;
        }
        else {
            list->mean = (list->first->next->priority
                    + list->last->priority) / 2;
        }
        --list->size;
    }
    helper_remove(list);
#endif

#if DATA_STRUCTURE == DOUBLY_LINKED_LIST
    if(list->first) {
        to_return = list->first->pid;
    }
    --list->size;
    helper_remove(list);
#endif

    return to_return;
}





#if HELPER_FUNCTION
void helper_insert(list_t* list, node_t* current, node_t* to_insert) {
    if(current->priority <= to_insert->priority) {
        to_insert->previous = current;
        to_insert->next = current->next;
        current->next = to_insert;

        if(to_insert->next == NULL) {
            list->last = to_insert;
        }
        else {
            to_insert->next->previous = to_insert;
        }
    }
    else {
        to_insert->next = current;
        to_insert->previous = current->previous;
        current->previous = to_insert;

        if(to_insert->previous == NULL) {
            list->first = to_insert;
        }
        else {
            to_insert->previous->next = to_insert;
        }
    }
}
#endif


/*
 * Puts the element in the right location
 */
list_t* enqueue(list_t* list, int32_t node, double priority) {
    node_t* current;

#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    node_t* temp = NULL;
#endif

    node_t* to_insert = malloc(sizeof(node_t));
    to_insert->pid = node;
    to_insert->priority = priority;


#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    if(list && list->size == 0) {
        to_insert->next = NULL;
        list->first = to_insert;
    }
    else {
        current = list->first;

        while(current->priority <= priority && current->next != NULL) {
            temp = current;
            current = current->next;
        }

        if(current->priority <= priority) {
            to_insert->next = current->next;
            current->next = to_insert;
        }
        else {
            if (current == list->first) {
                to_insert->next = current;
                list->first = to_insert;
            }
            else {
                temp->next = to_insert;
                to_insert->next = current;
            }
        }
    }
#endif

#if DATA_STRUCTURE == DOUBLY_LINKED_LIST
    if(list && list->size == 0) {
        to_insert->next = NULL;
        to_insert->previous = NULL;
        list->first = to_insert;
        list->last = to_insert;
    }
    else {
        current = list->last;
        while(current->priority > priority && current->previous != NULL) {
            current = current->previous;
        }

        helper_insert(list, current, to_insert);
    }

#endif

#if DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    if(list && list->size == 0) {
        /*
         * This is the first and last node in the list
         */
        to_insert->next = NULL;
        to_insert->previous = NULL;
        list->first = to_insert;
        list->last = to_insert;
    }
    else if(priority < list->mean) {
        /*
         * Insert from front
         */
        current = list->first;
        while(current->priority <= priority && current->next != NULL) {
            current = current->next;
        }

        helper_insert(list, current, to_insert);

    }
    else{
        /*
         * Insert from rear
         */
        current = list->last;
        while(current->priority > priority && current->previous != NULL) {
            current = current->previous;
        }

        helper_insert(list, current, to_insert);
    }

    list->mean = (list->first->priority +
            list->last->priority) / 2;
#endif

#if DATA_STRUCTURE == ARRAY_PRIORITY
    if (priority <= PRIORITY_SIZE) {
        current = list->priority_list[(int)priority];

        to_insert->next = NULL;
        if(current == NULL) {
            list->priority_list[(int)priority] = to_insert;
        }
        else{
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = to_insert;
        }

    }
    else {
        printf("ERROR: Maximum priority is %d\n", PRIORITY_SIZE);
    }
#endif

    list->size++;
    return list;
}
