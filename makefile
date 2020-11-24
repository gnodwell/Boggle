all: Test

Test.c: Test.c
	-gcc -ansi -Wall -c Test.c

Test: Test.o
	-gcc -asni -Wall Test.o -o Test

clean:
	-rm *.o Test