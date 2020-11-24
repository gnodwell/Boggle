all: Tests

Tests.c: Tests.c
	-gcc -ansi -Wall -c Tests.c

Tests: Tests.o
	-gcc -Wall Tests.o -o Tests

clean:
	-rm *.o Tests