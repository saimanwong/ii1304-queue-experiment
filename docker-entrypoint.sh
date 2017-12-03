#!/bin/bash
make

./run-correectness-test.sh
./run-time-test.sh
./run-valgrind-test.sh
