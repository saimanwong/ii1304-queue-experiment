#!/bin/bash
make
./obj/singly_linked_list_test_correctness src/test_correctness.input src/test_correctness.output
./obj/doubly_linked_list_test_correctness src/test_correctness.input src/test_correctness.output
./obj/doubly_linked_list_avg_test_correctness src/test_correctness.input src/test_correctness.output
./obj/array_priority_test_correctness src/test_correctness.input src/test_correctness.output
./obj/singly_linked_list 100
./obj/doubly_linked_list 100
./obj/doubly_linked_list_avg 100
./obj/array_priority 100
