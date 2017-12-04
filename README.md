# Experiment II1304
## Run experiments on host machine
__Requirements__:
 - make (required)
 - gcc (required)
 - python (optional, but required to run correctness test)
 - valgrind (optional, but required to run memory test)

-- Run the entire experiment:
```bash
$ ./RUN_TESTS.sh
```
The script runs a correctness, running time and memory test, respectively.
Correctness test prints out results in terminal.
Running time test stores the results in directory `./data_running_time`, and runs 50 iterations.
Memory test stores results in the directory `./data_valgrind`.

--- Run separate experiments

Correctness test
```bash
$ make
$ ./run_correctness.sh <NUMBER_OF_ELEMENTS>
```

Running time test (best, average and worst case)
```bash
$ make
$ ./run_running_time.sh <DATA_DIR> <ITERATIONS>
```

Memory test
```bash
$ make
$ ./run_valgrind.sh <DATA_DIR>
```
## Run experiments with Docker on host machine
__Requirements__:
 - Docker (required)
 
1) Create an image:
```bash
$ docker build -t <IMAGE_NAME> .
```
-- Run entire experiment in container and interactive mode with bash
```bash
$ docker run -it --entrypoint bash <IMAGE_NAME>
```
-- Run entire experiment in container to store data on host machine
```bash
$ docker run \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_running_time \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_valgrind \
    <IMAGE_NAME>
```
-- Run entire experiment in container to store data on host machine in the background
```bash
$ docker run -d \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_running_time \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_valgrind \
    <IMAGE_NAME>
```
-- Run separate experiment in container to store data on host machine
```bash
$ docker run --entrypoint test_correctness.sh <IMAGE_NAME>
```
```bash
$ docker run --entrypoint test_running_time.sh \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_running_time \
    <IMAGE_NAME>
```
```bash
$ docker run --entrypoint test_valgrind.sh \
    -v <DIRECTORY_NAME>:/usr/src/experiment/data_valgrind \
    <IMAGE_NAME>
```

## Description

## [Mission (in Swedish)](https://www.kth.se/social/course/II1304/page/uppgift-lasaret-1516/)
Du skall utvärdera fyra olika implementationer av prioritetsköer som baseras på länkade listor. Prioritetsköer används bland annat för att implementera mängden framtida händelser (eng. pending event set) i händelsestyrda simuleringar och som ready-köer i schemaläggning av processer och trådar.

Utvärderingen skall kunna användas för att ligga till grund för val av prioritetsköimplementation i generella fall. Därför måste din utvärdering omfatta både analytiska och exekveringsmässiga bästa-, värsta- och normalfallsprestanda för de olika datastrukturerna för användningsfall både som shemaläggningskö för processer/trådar med heltalsprioriteter i ett begränsat intervall och för användning som händelselista för händelsestyrd simulering. 

Elementen i listorna skall hållas ordnae efter prioritet. Om flera element i listan har identiskt samma prioritet skall de ordnas i FIFO-ordning - dvs. när de tas ut ur listan skall de tas ut i FIFO-ordning.

För användning som händelselista i en simulering skall prioriteten implementeras som en tidsstämpel av datatypen double. Lågt numeriskt värde betyder hög prioritet (i.e. en händelse som ligger nära i tiden har högre prioritet än en som kommer att inträffa längre fram i tiden). Simuleringen kan modelleras som att man tar ut den händelse som har högst prioritet (lägst tidsstämpel T) ur kön. Detta skall generera 0-N nya händelser med nya tidsstämplar T+increment() där increment() är ett icke-negativt tal genererat från någon form av (stokastisk) distribution (som i sin enklaste form kan returnera ett konstant värde). De nya tidsstämplar som genereras kan naturligtvis vara olika för varje ny händelse som skapas. Skulle två händelser med identiska tidsstämplar genereras så skall de läggas in i kön i den ordning de genererades.

Du skall själv implementera algoritmerna i programmeringsspråket C.
Prioritetsköerna som skall utvärderas är:

1. En enkellänkad lista där insättningar av nya element sker framifrån.
2. En dubbellänkad lista med insättning av nya element från slutet av listan.
3. En dubbellänkad lista där insättning av ett nytt element sker framifrån om prioriteten på det nya elementet är högre än medelvärdet av prioriteterna på det första och sista elementet i listan. Annars sker insättning från slutet av listan.
4. En prioritetskö specialanpassad för schemaläggning av processer/trådar där prioriteterna är heltal i intervallet [0,40] där lågt numeriskt värde är hög prioritet. För varje prioritet skall finnas en kö. Varje delkö betjänas enligt FIFO. 

