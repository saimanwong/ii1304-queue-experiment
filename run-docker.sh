docker run --rm -it \
    -v $PWD/src:/src \
    -v $PWD/docker-entrypoint.sh:/docker-entrypoint.sh \
    -v $PWD/run-correctness-test.sh \
    -v $PWD/run-time-test.sh \
    -v $PWD/run-valgrind-test.sh.sh \
    -v $PWD/run-correctness-test.sh \
    -v $PWD/Makefile:/Makefile \
    --entrypoint /docker-entrypoint.sh \
    gcc
