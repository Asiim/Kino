CC=gcc

all: hall_tests.o	runall.o unity.o unity_fixture.o

hall_tests.o:
	$(CC) -c hall_tests.c -o ../build/hall_tests.o

runall.o:
	$(CC) -c runall.c -o ../build/runall.o

unity.o:
	$(CC) -c ../../unity/unity.c -o ../build/unity.o

unity_fixture.o:
	$(CC) -c ../../unity/unity_fixture.c -o ../build/unity_fixture.o
