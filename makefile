all: hall movie counter main kino

hall:
	gcc -c hall/src/hall.c -o build/hall.o

movie:
	gcc -c movie/src/movie.c -o build/movie.o

counter:
	gcc -c counter/src/counter.c -o build/counter.o
	
main:
	gcc -c main/main.c -o build/main.o

kino:
	gcc -o kino build/movie.o build/counter.o build/main.o build/hall.o
