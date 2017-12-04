#!/bin/bash

echo "CORRECTNESS TEST STARTING..."
sleep 5
./test_correctness.sh 20000
sleep 5
echo "CORRECTNESS TEST FINISHED"


echo "VALGRIND TEST STARTING..."
sleep 5
./test_valgrind.sh data_valgrind
sleep 5
echo "VALGRIND TEST FINISHED..."

echo "RUNNING TIME TEST STARTING (this test may take a while to finish)..."
sleep 5
./test_running_time.sh data_running_time 50
echo "RUNNING TIME TEST FINISHED..."
