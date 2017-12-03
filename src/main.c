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

#if TEST_CORRECTNESS
void test_correctness(char* indata, char* outdata) {

    char * temp;

    list_t* list = new_queue();
    uint32_t pid = 0;
    double test_priority = 0;
    uint32_t test_pid = 0;

    char line[512];
    int i = 0;
    FILE* file = fopen(indata, "r");

    while (fgets(line, sizeof(line), file)) {
        temp = strtok(line," ");
        while (temp != NULL)
        {
            temp[strcspn(temp, "\n")] = '\0';

            if (i == 0) {
                test_pid = atoi(temp);
                i = 1;
            } else {
                test_priority = atof(temp);
                i = 0;
            }


            temp = strtok(NULL, " ");
        }
        enqueue(list, test_pid, test_priority);
    }

    fclose(file);

    file = fopen(outdata, "r");

    while (fgets(line, sizeof(line), file)) {
        temp = strtok(line," ");
        while (temp != NULL)
        {
            temp[strcspn(temp, "\n")] = '\0';

            if (i == 0) {
                test_pid = atoi(temp);
                i = 1;
            } else {
                test_priority = atof(temp);
                i = 0;
            }

            temp = strtok (NULL, " ");
        }

        pid = dequeue(list);
        printf("pid %u == test_pid %d\n", pid, test_pid);
        assert(pid == test_pid);
    }

    delete_list(list);

    printf("test correctness - Passed\n");
}
#else

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
    printf("[SINGLY_LINKED_LIST | BEST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[SINGLY_LINKED_LIST | BEST CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid;


        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST | BEST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST | BEST CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = 1;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG | BEST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG | BEST CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = test_pid % 41;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY | BEST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY | BEST CASE | DEQUEUE] %f seconds\n", time_taken);
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
    printf("[SINGLY_LINKED_LIST | AVERAGE CASE | ENQUEUE] %f seconds\n", time_taken);
    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[SINGLY_LINKED_LIST | AVERAGE CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST
    printf("[DOUBLY_LINKED_LIST | AVERAGE CASE | ENQUEUE] %f seconds\n", time_taken);
    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST | AVERAGE CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == DOUBLY_LINKED_LIST_AVG
    printf("[DOUBLY_LINKED_LIST_AVG | AVERAGE CASE | ENQUEUE] %f seconds\n", time_taken);
    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG | AVERAGE CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    printf("[ARRAY_PRIORITY | AVERAGE CASE | ENQUEUE] %f seconds\n", time_taken);
    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY | AVERAGE CASE | DEQUEUE] %f seconds\n", time_taken);
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
    printf("[SINGLY_LINKED_LIST | WORST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[SINGLY_LINKED_LIST | WORST CASE | DEQUEUE] %f seconds\n", time_taken);
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
    printf("[DOUBLY_LINKED_LIST | WORST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST | WORST CASE | DEQUEUE] %f seconds\n", time_taken);
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
    printf("[DOUBLY_LINKED_LIST_AVG | WORST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[DOUBLY_LINKED_LIST_AVG | WORST CASE | DEQUEUE] %f seconds\n", time_taken);
#elif DATA_STRUCTURE == ARRAY_PRIORITY
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        test_priority = 40;

        t = clock();
        enqueue(list, test_pid, test_priority);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY | WORST CASE | ENQUEUE] %f seconds\n", time_taken);

    time_taken = 0.0;
    for(test_pid = 0; test_pid < TOTAL_ELEMENTS; test_pid++) {
        t = clock();
        dequeue(list);
        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    printf("[ARRAY_PRIORITY | WORST CASE | DEQUEUE] %f seconds\n", time_taken);
#endif

    return list;
}
#endif

int main(int argc, char **argv) {
#if TEST_CORRECTNESS
    char* indata = argv[1];
    char* outdata = argv[2];
    test_correctness(indata, outdata);
#else
    list_t* list;

    TOTAL_ELEMENTS = atoi(argv[1]);

    list = test_best_case();
    delete_list(list);

    list = test_average_case();
    delete_list(list);

    list = test_worst_case();
    delete_list(list);
#endif

    return 0;
}
