docker run --rm -it \
    -v $PWD/src:/src \
    -v $PWD/docker-entrypoint.sh:/docker-entrypoint.sh \
    -v $PWD/Makefile:/Makefile \
    --entrypoint /docker-entrypoint.sh \
    gcc
