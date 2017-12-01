#!/bin/bash

COUNTER_X=0
COUNTER_Y=0
while [  $COUNTER_X -lt 50 ]; do
    while [ $COUNTER_Y -le 10 ]; do
	TOT_ELEMENT=$((10000 + $COUNTER_Y * 5000))
        echo "SINGLY LINKED LIST - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./singly_linked_list $TOT_ELEMENT >> ./data/singly_linked_list_$TOT_ELEMENT
    
        echo "DOUBLY LINKED LIST - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./doubly_linked_list $TOT_ELEMENT >> ./data/doubly_linked_list_$TOT_ELEMENT
    
        echo "DOUBLY LINKED LIST AVG - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./doubly_linked_list_avg $TOT_ELEMENT >> ./data/doubly_linked_list_avg_$TOT_ELEMENT
    
        echo "ARRAY PRIORITY - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./array_priority $TOT_ELEMENT >> ./data/array_priority_$TOT_ELEMENT
        let COUNTER_Y=COUNTER_Y+1
    done
    let COUNTER_Y=0
    let COUNTER_X=COUNTER_X+1 
done
