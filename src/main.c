#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/types.h>
#include "queues.h"

#define TOTAL_ELEMENTS 20




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

void test_queue() {
    double test_priority;
    uint32_t test_pid;
    test_node test_list[TOTAL_ELEMENTS];
    list_t* list = new_queue();
    uint32_t pid;
    int i;


    srand(time(NULL));
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = rand() / (RAND_MAX / 40);

        enqueue(list, test_pid, test_priority);
        test_list[test_pid].test_pid = test_pid;
        test_list[test_pid].test_priority = test_priority;
        printf("Enqueued - test_pid: %d, test_priority: %f\n", test_pid, test_priority);
    }

    qsort (test_list, TOTAL_ELEMENTS, sizeof(test_node), cmp);

    print_list(list);
    for(i = 0; i < TOTAL_ELEMENTS; i++) {
        test_priority = test_list[i].test_priority;
        test_pid = test_list[i].test_pid;
        pid = dequeue(list);

        assert(pid == test_pid);
        printf("PASSED --- PID %d == %d\n",pid, test_pid);
    }

    delete_list(list);
}

void simple_queue() {
    list_t* list = new_queue();
    enqueue(list, 1, 15);
    /* enqueue(list, 2, 16); */
    /* enqueue(list, 3, 13); */
    print_list(list);

}

int main(int argc, char **argv) {
    test_queue();
    /* simple_queue(); */
    /* list_t* list = new_queue(); */
    /* enqueue(list, 5, 41); */

    return 0;
}
