all: hall.o movie.o counter.o main.o kino

hall.o:
	gcc -c ../hall/src/hall.c -o hall.o

movie.o:
	gcc -c ../movie/src/movie.c -o movie.o

counter.o:
	gcc -c ../counter/src/counter.c -o counter.o

main:
	gcc -c ../main/main.c -o main.o

kino:
	gcc -o ../kino movie.o counter.o main.o hall.o
