#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100

typedef struct dNode {
	char* key;
    struct dNode *next;
}DNode;

char * CopyStr (const char *);
unsigned Hash(const char *s);

DNode * LookUp (DNode ** dictionary, int hashSize, const char *key);

DNode * Insert (DNode ** dictionary, int hashSize, const char * key);

void FreeDictionary (DNode ** dictionary, int hashSize);

#endif
