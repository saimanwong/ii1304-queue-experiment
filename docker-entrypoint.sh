#!/bin/bash
make
./obj/singly_linked_list_test_correctness src/test_correctness.in src/test_correctness.out
./obj/doubly_linked_list_test_correctness src/test_correctness.in src/test_correctness.out
./obj/doubly_linked_list_avg_test_correctness src/test_correctness.in src/test_correctness.out
./obj/array_priority_test_correctness src/test_correctness.in src/test_correctness.out
./obj/singly_linked_list 100
./obj/doubly_linked_list 100
./obj/doubly_linked_list_avg 100
./obj/array_priority 100
