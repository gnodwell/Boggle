all: JustinKleinTests

JustinKleinTests.c: JustinKleinTests.c
	-gcc -ansi -Wall -c JustinKleinTests.c

JustinKleinTests: JustinKleinTests.o
	-gcc -asni -Wall JustinKleinTests.o -o JustinKleinTests

clean:
	-rm *.o JustinKleinTests