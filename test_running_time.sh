#!/bin/bash

FILE_PATH_DATA=$1
ITERATIONS=$2

mkdir -p $FILE_PATH_DATA

COUNTER_X=0
COUNTER_Y=0
while [  $COUNTER_X -lt $ITERATIONS ]; do
    while [ $COUNTER_Y -le 10 ]; do
	TOT_ELEMENT=$((10000 + $COUNTER_Y * 5000))
        echo "[RUNNING TIME] SINGLY LINKED LIST - COUNTER: ${COUNTER_X}/${ITERATIONS}, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./obj/singly_linked_list $TOT_ELEMENT >> ${FILE_PATH_DATA}/singly_linked_list_${TOT_ELEMENT}.dat
    
        echo "[RUNNING TIME] DOUBLY LINKED LIST - COUNTER: ${COUNTER_X}/${ITERATIONS}, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./obj/doubly_linked_list $TOT_ELEMENT >> ${FILE_PATH_DATA}/doubly_linked_list_${TOT_ELEMENT}.dat
    
        echo "[RUNNING TIME] DOUBLY LINKED LIST AVG - COUNTER: ${COUNTER_X}/${ITERATIONS}, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./obj/doubly_linked_list_avg $TOT_ELEMENT >> ${FILE_PATH_DATA}/doubly_linked_list_avg_${TOT_ELEMENT}.dat
    
        echo "[RUNNING TIME] ARRAY PRIORITY - COUNTER: ${COUNTER_X}/${ITERATIONS}, TOT_ELEMENT: $TOT_ELEMENT" >> log
        ./obj/array_priority $TOT_ELEMENT >> ${FILE_PATH_DATA}/array_priority_${TOT_ELEMENT}.dat
        let COUNTER_Y=COUNTER_Y+1
    done
    let COUNTER_Y=0
    let COUNTER_X=COUNTER_X+1 
done
