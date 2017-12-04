FROM gcc:6

WORKDIR /usr/src/experiment/

COPY src ./src
COPY RUN_TESTS.sh ./docker-entrypoint.sh
COPY Makefile test_correctness.sh test_running_time.sh test_valgrind.sh ./
RUN apt-get update && \
        apt-get install -y --no-install-recommends \
        python \
        valgrind

ENTRYPOINT ["./docker-entrypoint.sh"]
