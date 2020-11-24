#include <string.h>
#include "Dictionary.h"
#include <stdio.h>

/*code refactoring completed by Justin Klein ID 1096403*/

/*form hash value for string s*/
/*this produces a starting value in the dictionary array*/
unsigned Hash(const char *s) {
	unsigned hashVal;
	for (hashVal = 0; *s != '\0'; s++)
		hashVal = *s + 31 * hashVal;
	return hashVal ;
}

/*look up given value in dictionary*/
/*loop through dictionary until key is found*/
/*if key is found return np in which it is located*/
/*if key is not found, return NULL*/ 
DNode * LookUp (DNode ** dictionary, int hashSize, const char *key) {
	DNode * np;
	unsigned int hashVal = Hash(key);
	for (np = dictionary [hashVal % hashSize]; np !=NULL; np = np->next)
		if (strcmp (key, np->key) == 0)
			return np;
       	/*not found*/	
	return NULL; 
}

/*Insert given np into dictionary*/
/*if np is NULL it returns NULL*/
/*If not it returns np*/
DNode * Insert (DNode ** dictionary, int hashSize,  const char * key) {
	unsigned int hashVal;
	DNode *np;

	if ((np = LookUp (dictionary, hashSize, key)) == NULL ) { 
		np = (DNode *) malloc (sizeof (*np));

		if (np == NULL || (np->key = CopyStr (key)) == NULL)
			return NULL;

		hashVal = Hash (key) % hashSize;

		np->next = dictionary [hashVal];
		dictionary [hashVal] = np;
	}
	return np;
}

/*Frees memory alocated for DNode ** dictionary*/
void FreeDictionary (DNode ** dictionary, int hashSize) {
	int i;
	for (i=0; i<hashSize; i++) { 
		/*if there is an entry at position i*/
		if (dictionary [i]!=NULL) { 
			DNode *head = dictionary[i]; 
			DNode *current = head;
			while (current != NULL) {
				DNode * temp = current;
				current = current->next;
				free (temp);
			}
			/*BUG Fix*/
			dictionary[i] = NULL;  
		}
	}
}

/*make a copy of s*/
char *CopyStr(const char *s) { 
	char *p;
	int len = strlen(s);

	p = (char *) malloc(len+1); /* +1 for ?\0? */
	if (p != NULL)
		strncpy(p, s, len);
	p[len] = '\0';

	return p;
}
