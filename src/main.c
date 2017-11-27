#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/types.h>
#include "queues.h"

/* #define TOTAL_ELEMENTS 40000 */
int TOTAL_ELEMENTS;

/*
 * test0 - tests enqueue and dequeue correctness
 */
typedef struct {
    uint32_t test_pid;
    double test_priority;
} test_node;

int cmp(const void *x, const void *y) {
    test_node *xx = (test_node *)x;
    test_node *yy = (test_node *)y;

    if (xx->test_priority < yy->test_priority) return -1;
    if (xx->test_priority > yy->test_priority) return 1;
    return 0;
}

/* void test_correctness() { */
/*     double test_priority; */
/*     uint32_t test_pid; */
/*     test_node test_list[TOTAL_ELEMENTS]; */
/*     list_t* list = new_queue(); */
/*     uint32_t pid; */
/*     int i; */
/*  */
/*  */
/*     srand(time(NULL)); */
/*     for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) { */
/*         test_priority = rand() / (RAND_MAX / 40); */
/*  */
/*         enqueue(list, test_pid, test_priority); */
/*         test_list[test_pid].test_pid = test_pid; */
/*         test_list[test_pid].test_priority = test_priority; */
/*         #<{(| printf("Enqueued - test_pid: %d, test_priority: %f\n", test_pid, test_priority); |)}># */
/*     } */
/*  */
/*     qsort (test_list, TOTAL_ELEMENTS, sizeof(test_node), cmp); */
/*  */
/*     #<{(| print_list(list); |)}># */
/*     for(i = 0; i < TOTAL_ELEMENTS; i++) { */
/*         test_priority = test_list[i].test_priority; */
/*         test_pid = test_list[i].test_pid; */
/*         pid = dequeue(list); */
/*  */
/*         assert(pid == test_pid); */
/*     } */
/*  */
/*     delete_list(list); */
/*     printf("test0 correctness - Passed\n"); */
/* } */

list_t* test_best_case() {
    double test_priority;
    uint32_t test_pid;
    clock_t t;
    float time_taken = 0.0;

    list_t* list = new_queue();

#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = TOTAL_ELEMENTS - test_pid;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[SINGLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid;


        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid % 41;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY] %f seconds\n", time_taken);
#endif

    return list;
}

list_t* test_average_case() {
    double test_priority;
    uint32_t test_pid;
    clock_t t;
    double time_taken = 0;
    list_t* list = new_queue();

    srand(time(NULL));
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = rand() / (RAND_MAX / 40);

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }

#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    printf("[SINGLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    printf("[DOUBLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    printf("[DOUBLY_LINKED_LIST_AVG] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    printf("[ARRAY_PRIORITY] %f seconds\n", time_taken);
#endif
    return list;
}


list_t* test_worst_case() {
    double test_priority;
    uint32_t test_pid;
    clock_t t;
    float time_taken = 0.0;

    list_t* list = new_queue();

#if DATA_STRUCTURE == SINGLY_LINKED_LIST
    /*
     * Priority increments
     */
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[SINGLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    /*
     * Priority decrements
     */
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = TOTAL_ELEMENTS - test_pid;


        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    enqueue(list, 0, TOTAL_ELEMENTS*2);
    enqueue(list, 1, 0);
    for(test_pid = 2; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid - 1;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = 40;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY] %f seconds\n", time_taken);
#endif

    return list;
}

int main(int argc, char **argv) {
    list_t* list;

    TOTAL_ELEMENTS = atoi(argv[1]);

    /* test_correctness(); */

    list = test_best_case();
    delete_list(list);

    list = test_average_case();
    delete_list(list);

    list = test_worst_case();
    delete_list(list);

    return 0;
}
