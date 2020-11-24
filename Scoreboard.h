#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdlib.h>

typedef struct user{
	char name[100];
	int maxScore;
	int totalGames;
	int totalScore;
	struct user *next;

} User;

User* FindUserWithName(User* head, char* nameToFind);

User* GetUserAtIndex(User* head, int index);

int GetIndexOfUserWithName(User* head, char* nameToFind);

int GetLength(User* head);

User* GetLastNode(User *head);

void PrintScoreboard(User *head);

void FreeAll(User* head);

void AddNode(User *head, char* name, int maxScore);

int UserIsInList(User* head, char* nameToFind);

void UpdateNodeWithName(User *head, char* name, int currentScore);

#endif
