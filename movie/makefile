CC=gcc

all: movie.o tests build

.PHONY: movie.o tests build

movie.o:
	$(CC) -c src/movie.c -o ../build/movie.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
