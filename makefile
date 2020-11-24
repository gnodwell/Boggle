CC = gcc
CFLAGS = -std=c99 -pedantic -Wall

all: Boggle



Boggle: Boggle.o BoardGenerator.o Dictionary.o Scoreboard.o WordChecker.o
	$(CC) $(CFLAGS) Boggle.o BoardGenerator.o Dictionary.o Scoreboard.o WordChecker.o -o Boggle

Boggle.o: Boggle.c *.h
	$(CC) $(CFLAGS) -c Boggle.c -o Boggle.o

Board_Generator.o: BoardGenerator.c
	$(CC) $(CFLAGS) -c BoardGenerator.c -o BoardGenerator.o

Dictionary.o: Dictionary.c
	$(CC) $(CFLAGS) -c Dictionary.c -o Dictionary.o

Scoreboard.o: Scoreboard.c
	$(CC) $(CFLAGS) -c Scoreboard.c -o Scoreboard.o

WordChecker.o: WordChecker.c
	$(CC) $(CFLAGS) -c WordChecker.c -o WordChecker.o

clean:
	rm -i Boggle *.o
	