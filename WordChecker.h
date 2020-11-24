#include <string.h>
#include "BoardGenerator.h"
#include <stdlib.h>


int WordChecker(struct RolledDice **gameBoard, char *word);
int AbidesRules(int i, int j, char *word, struct RolledDice** gameBoard, int subLen, int **visited);
char GetLetter(int i, int j, struct RolledDice **gameBoard);

int TestWordChecker(char **boggle, char *word);
int TestAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited);
char TestGetLetter(int i, int j, char **boggle);

int HcWordChecker(char boggle[][4], char *word);
char HcGetLetter(int i, int j, char boggle[][4]);
int HcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited);



