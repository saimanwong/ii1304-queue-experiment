#!/bin/bash

COUNTER=0
while [  $COUNTER -lt 100 ]; do
    echo "SINGLY LINKED LIST - COUNTER: $COUNTER" >> log
    ./singly_linked_list 10000 >> ./data/singly_linked_list_10000
    ./singly_linked_list 15000 >> ./data/singly_linked_list_15000
    ./singly_linked_list 20000 >> ./data/singly_linked_list_20000
    ./singly_linked_list 25000 >> ./data/singly_linked_list_25000
    ./singly_linked_list 30000 >> ./data/singly_linked_list_30000
    ./singly_linked_list 35000 >> ./data/singly_linked_list_35000
    ./singly_linked_list 40000 >> ./data/singly_linked_list_40000
    ./singly_linked_list 45000 >> ./data/singly_linked_list_45000
    ./singly_linked_list 50000 >> ./data/singly_linked_list_50000

    echo "DOUBLY LINKED LIST - COUNTER: $COUNTER" >> log
    ./doubly_linked_list 10000 >> ./data/doubly_linked_list_10000
    ./doubly_linked_list 15000 >> ./data/doubly_linked_list_15000
    ./doubly_linked_list 20000 >> ./data/doubly_linked_list_20000
    ./doubly_linked_list 25000 >> ./data/doubly_linked_list_25000
    ./doubly_linked_list 30000 >> ./data/doubly_linked_list_30000
    ./doubly_linked_list 35000 >> ./data/doubly_linked_list_35000
    ./doubly_linked_list 40000 >> ./data/doubly_linked_list_40000
    ./doubly_linked_list 45000 >> ./data/doubly_linked_list_45000
    ./doubly_linked_list 50000 >> ./data/doubly_linked_list_50000

    echo "DOUBLY LINKED LIST AVG - COUNTER: $COUNTER" >> log
    ./doubly_linked_list_avg 10000 >> ./data/doubly_linked_list_avg_10000
    ./doubly_linked_list_avg 15000 >> ./data/doubly_linked_list_avg_15000
    ./doubly_linked_list_avg 20000 >> ./data/doubly_linked_list_avg_20000
    ./doubly_linked_list_avg 25000 >> ./data/doubly_linked_list_avg_25000
    ./doubly_linked_list_avg 30000 >> ./data/doubly_linked_list_avg_30000
    ./doubly_linked_list_avg 35000 >> ./data/doubly_linked_list_avg_35000
    ./doubly_linked_list_avg 40000 >> ./data/doubly_linked_list_avg_40000
    ./doubly_linked_list_avg 45000 >> ./data/doubly_linked_list_avg_45000
    ./doubly_linked_list_avg 50000 >> ./data/doubly_linked_list_avg_50000

    echo "ARRAY PRIORITY - COUNTER: $COUNTER" >> log
    ./array_priority 10000 >> ./data/array_priority_10000
    ./array_priority 15000 >> ./data/array_priority_15000
    ./array_priority 20000 >> ./data/array_priority_20000
    ./array_priority 25000 >> ./data/array_priority_25000
    ./array_priority 30000 >> ./data/array_priority_30000
    ./array_priority 35000 >> ./data/array_priority_35000
    ./array_priority 40000 >> ./data/array_priority_40000
    ./array_priority 45000 >> ./data/array_priority_45000
    ./array_priority 50000 >> ./data/array_priority_50000
    let COUNTER=COUNTER+1 
done
