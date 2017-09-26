FROM gcc:6

WORKDIR /usr/src/experiment/

COPY src src
COPY RUN_TESTS docker-entrypoint.sh ./
COPY Makefile.saiman  ./Makefile
RUN chmod +x docker-entrypoint.sh RUN_TESTS

ENTRYPOINT ["./docker-entrypoint.sh"]
