#!/bin/bash
FILE_PATH_DATA=$1
mkdir -p $FILE_PATH_DATA
COUNTER_Y=0
while [ $COUNTER_Y -le 10 ]; do
    TOT_ELEMENT=$((10000 + $COUNTER_Y * 5000))
    echo "[VALGRIND] SINGLY LINKED LIST - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
    valgrind --log-file=${FILE_PATH_DATA}/singly_linked_list_${TOT_ELEMENT}.dat ./obj/singly_linked_list $TOT_ELEMENT

    echo "[VALGRIND] DOUBLY LINKED LIST - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
    valgrind --log-file=${FILE_PATH_DATA}/doubly_linked_list_${TOT_ELEMENT}.dat ./obj/doubly_linked_list $TOT_ELEMENT 

    echo "[VALGRIND] DOUBLY LINKED LIST AVG - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
    valgrind --log-file=${FILE_PATH_DATA}/doubly_linked_list_avg_${TOT_ELEMENT}.dat ./obj/doubly_linked_list_avg $TOT_ELEMENT

    echo "[VALGRIND] ARRAY PRIORITY - COUNTER: $COUNTER_X, TOT_ELEMENT: $TOT_ELEMENT" >> log
    valgrind --log-file=${FILE_PATH_DATA}/array_priority_${TOT_ELEMENT}.dat ./obj/array_priority $TOT_ELEMENT
    let COUNTER_Y=COUNTER_Y+1
done
