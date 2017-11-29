#!/bin/bash

COUNTER=0
while [  $COUNTER -lt 25 ]; do
    echo "SINGLY LINKED LIST - COUNTER: $COUNTER" >> log
    ./singly_linked_list 10000 >> ./data/singly_linked_list_10000
    ./singly_linked_list 11000 >> ./data/singly_linked_list_11000
    ./singly_linked_list 12000 >> ./data/singly_linked_list_12000
    ./singly_linked_list 13000 >> ./data/singly_linked_list_13000
    ./singly_linked_list 14000 >> ./data/singly_linked_list_14000
    ./singly_linked_list 15000 >> ./data/singly_linked_list_15000
    ./singly_linked_list 16000 >> ./data/singly_linked_list_16000
    ./singly_linked_list 17000 >> ./data/singly_linked_list_17000
    ./singly_linked_list 18000 >> ./data/singly_linked_list_18000
    ./singly_linked_list 19000 >> ./data/singly_linked_list_19000
    ./singly_linked_list 20000 >> ./data/singly_linked_list_20000

    echo "DOUBLY LINKED LIST - COUNTER: $COUNTER" >> log
    ./doubly_linked_list 10000 >> ./data/doubly_linked_list_10000
    ./doubly_linked_list 11000 >> ./data/doubly_linked_list_11000
    ./doubly_linked_list 12000 >> ./data/doubly_linked_list_12000
    ./doubly_linked_list 13000 >> ./data/doubly_linked_list_13000
    ./doubly_linked_list 14000 >> ./data/doubly_linked_list_14000
    ./doubly_linked_list 15000 >> ./data/doubly_linked_list_15000
    ./doubly_linked_list 16000 >> ./data/doubly_linked_list_16000
    ./doubly_linked_list 17000 >> ./data/doubly_linked_list_17000
    ./doubly_linked_list 18000 >> ./data/doubly_linked_list_18000
    ./doubly_linked_list 19000 >> ./data/doubly_linked_list_19000
    ./doubly_linked_list 20000 >> ./data/doubly_linked_list_20000

    echo "DOUBLY LINKED LIST AVG - COUNTER: $COUNTER" >> log
    ./doubly_linked_list_avg 10000 >> ./data/doubly_linked_list_avg_10000
    ./doubly_linked_list_avg 11000 >> ./data/doubly_linked_list_avg_11000
    ./doubly_linked_list_avg 12000 >> ./data/doubly_linked_list_avg_12000
    ./doubly_linked_list_avg 13000 >> ./data/doubly_linked_list_avg_13000
    ./doubly_linked_list_avg 14000 >> ./data/doubly_linked_list_avg_14000
    ./doubly_linked_list_avg 15000 >> ./data/doubly_linked_list_avg_15000
    ./doubly_linked_list_avg 16000 >> ./data/doubly_linked_list_avg_16000
    ./doubly_linked_list_avg 17000 >> ./data/doubly_linked_list_avg_17000
    ./doubly_linked_list_avg 18000 >> ./data/doubly_linked_list_avg_18000
    ./doubly_linked_list_avg 19000 >> ./data/doubly_linked_list_avg_19000
    ./doubly_linked_list_avg 20000 >> ./data/doubly_linked_list_avg_20000

    echo "ARRAY PRIORITY - COUNTER: $COUNTER" >> log
    ./array_priority 10000 >> ./data/array_priority_10000
    ./array_priority 11000 >> ./data/array_priority_11000
    ./array_priority 12000 >> ./data/array_priority_12000
    ./array_priority 13000 >> ./data/array_priority_13000
    ./array_priority 14000 >> ./data/array_priority_14000
    ./array_priority 15000 >> ./data/array_priority_15000
    ./array_priority 16000 >> ./data/array_priority_16000
    ./array_priority 17000 >> ./data/array_priority_17000
    ./array_priority 18000 >> ./data/array_priority_18000
    ./array_priority 19000 >> ./data/array_priority_19000
    ./array_priority 20000 >> ./data/array_priority_20000
    let COUNTER=COUNTER+1 
done
