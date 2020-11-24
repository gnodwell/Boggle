/*Edited by Amardeep Singh*/

/* includes */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "Scoreboard.h"

/*
 * Finds and returns a pointer to the User in the linked list beginning with
 * head which has the name nameToFind. If such a User is not in the Linked
 * List, it will return NULL. Helper function to IncrementScore.
 */
User* FindUserWithName(User* head, char* nameToFind)
{
	if (head == NULL)
	{
		return head;
	}
	User *current = head ;
	while (current != NULL)
	{
		if (strcmp(current->name, nameToFind) == 0)
		{
			return current;
		}
		current = (current)->next;
	}
	return NULL;
}

/* frees every element of the linked list */
void FreeAll(User* head)
{
	if (head -> next == NULL)
	{
		free(head);
	}
	else
	{
		User *current = head->next;
		User *previous = head;
		while (current != NULL)
		{
			free(previous);
			previous = current;
			current = (current)->next;
		}
	}
}


/* Returns the element at a given index */
User* GetUserAtIndex(User* head, int index)
{
	if (head == NULL)
	{
		return NULL;
	}
	User *current = head;
	int count = 0;
	while (current != NULL)
	{
		if (count == index + 1)
		{
			return current;
		}
		current = (current)->next;
		count++;
	}
	return NULL;
}

/* Returns the index of a element by passing a name to compare */
int GetIndexOfUserWithName(User* head, char* nameToFind)
{
	if (head == NULL && head->name != nameToFind)
	{
		return -1;
	}
	User *current = head;
	int count = 0;
	while (current != NULL)
	{
		if (strcmp(current->name, nameToFind))
		{
			return count;
		}
		current = (current)->next;
		count++;
	}
	return -1;
}

/*
 * Finds whether or not a an existing user is already in the list. Of they are,
 * returns 1. If not, returns 0.
 */
int UserIsInList(User* head, char* nameToFind)
{
	User *current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, nameToFind) == 0)
		{
			return 1;
		}
		current = (current)->next;
	}
	return 0;
}

/* Returns the length of the linked list */
int GetLength(User* head)
{
	if (head == NULL)
	{
		return 0;
	}
	User *current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		if (current->next == NULL)
		{
			return count;
		}
		current = (current)->next;
	}
	return 0;
}

/*
 * Helper function. Finds the last node in the linked list and returns it.
 * Returns NULL if called with an empty head, although such a case is not used
 * in the main function AddNode.
 */
User* GetLastNode(User *head)
{
	if (head == NULL)
	{
		return head;
	}
	User *current = head;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			return current;
		}
		current = (current)->next;
	}
	return NULL;
}

/* Prints all the elements of the linked list as a scoreboard */
void PrintScoreboard(User *head)
{
	fprintf(stdout, "\n");
	/* formats print statments as a scoreboard */
	fprintf(stdout, "---- SCORE BOARD ---- \n");
	if (head -> next != NULL)
	{
		User *current = head -> next;
		while (current != NULL)
		{
			printf("\n");
			printf("Player name: %s \n", current->name);
			printf("High score: %d \n", current->maxScore);
			printf("Games played: %d \n", current->totalGames);
			printf("Total score: %d \n", current->totalScore);
			printf("\n");
			printf("--------------------- \n");

			if (current->next == NULL)
			{
				break;
			}
			current = (current)->next;
		}
	}
}


/* adds a user to the score by inserting into the linked list */
void AddNode(User *head, char* name, int maxScore)
{
	User *userPtr = NULL;
	if (head != NULL)
	{
		 userPtr = malloc(sizeof(struct user));
	}
	strcpy(userPtr->name, name);
	userPtr->maxScore = maxScore;
	userPtr->totalGames = 1;
	userPtr->totalScore = maxScore;
	userPtr->next = NULL;

	if (head == NULL)
	{
		head = userPtr;
	}
	else
	{
		GetLastNode(head)->next = userPtr;
	}
}


/* updates user in the list with a new current score */
void UpdateNodeWithName(User *head, char* name, int currentScore)
{
	if (UserIsInList(head, name) == 1)
	{
	    /* uses function to compare name */
		User *userPtr = FindUserWithName(head, name);
		if (currentScore > (userPtr->maxScore))
		{
			userPtr->maxScore = currentScore;
		}
		userPtr->totalGames += 1;
		userPtr->totalScore += currentScore;
	}
}


void TestThreeUsers()
{
	User *userPtr1 = malloc(sizeof(struct user));
	User *userPtr2 = malloc(sizeof(struct user));
	User *userPtr3 = malloc(sizeof(struct user));
    strcpy(userPtr1 -> name, "1");
    strcpy(userPtr2 -> name, "2");
    strcpy(userPtr3 -> name, "3");
    userPtr1 -> maxScore = 1;
    userPtr2 -> maxScore = 2;
    userPtr3 -> maxScore = 3;
    userPtr1 -> totalGames = 1;
    userPtr2 -> totalGames = 2;
    userPtr3 -> totalGames = 3;
    userPtr1 -> totalScore = 1;
    userPtr2 -> totalScore = 2;
    userPtr3 -> totalScore = 3;
    userPtr1 -> next = userPtr2;
    userPtr2 -> next = userPtr3;
    userPtr3 -> next = NULL;
    
    int result = GetLength(userPtr1);
    if (result == 3) {
        printf("TEST PASSED :  TestThreeUsers() is working fine for test input of three users, result is %d\n", result);
    } else {
        printf("TEST FAILED : TestThreeUsers() is not working fine for test input of three users, result is %d\n", result);
    }
}

void TestTwoUsers()
{
    User *userPtr1 = malloc(sizeof(struct user));
    User *userPtr2 = malloc(sizeof(struct user));
    strcpy(userPtr1 -> name, "1");
    strcpy(userPtr2 -> name, "2");
    userPtr1 -> maxScore = 1;
    userPtr2 -> maxScore = 2;
    userPtr1 -> totalGames = 1;
    userPtr2 -> totalGames = 2;
    userPtr1 -> totalScore = 1;
    userPtr2 -> totalScore = 2;
    userPtr1 -> next = userPtr2;
    userPtr2 -> next = NULL;
    
    int result = GetLength(userPtr1);
    if (result == 2) {
        printf("TEST PASSED :  TestTwoUsers() is working fine for test input of two users, result is %d\n", result);
    } else {
        printf("TEST FAILED : TestTwoUsers() is not working fine for test input of two users, result is %d\n", result);
    }
}

void TestOneUser()
{
    User *userPtr1 = malloc(sizeof(struct user));
    strcpy(userPtr1 -> name, "1");
    userPtr1 -> maxScore = 1;
    userPtr1 -> totalGames = 1;
    userPtr1 -> totalScore = 1;
    userPtr1 -> next = NULL;
    
    int result = GetLength(userPtr1);
    if (result == 1) {
        printf("TEST PASSED :  TestOneUser() is working fine for test input of one user, result is %d\n", result);
    } else {
        printf("TEST FAILED : TestOneUser() is not working fine for test input of one user, result is %d\n", result);
    }
}

void TestZeroUsers()
{
    User *userPtr1 = NULL;

    int result = GetLength(userPtr1);
    if (result == 0) {
        printf("TEST PASSED :  TestZeroUsers() is working fine for test input of no user, result is %d\n", result);
    } else {
        printf("TEST FAILED : TestZeroUsers() is not working fine for test input of no user, result is %d\n", result);
    }
}


void TestLoopingUser()
{
    User *userPtr1 = malloc(sizeof(struct user));
    strcpy(userPtr1 -> name, "1");
    userPtr1 -> maxScore = 1;
    userPtr1 -> totalGames = 1;
    userPtr1 -> totalScore = 1;
    userPtr1 -> next = userPtr1;
    
    int result = GetLength(userPtr1);
    printf("Result is %d\n", result);
}

void TestIntegerUser()
{
    int result = GetLength(10);
    printf("Result is %d\n", result);

}

int main(int argc, char *argv[]) {
    TestThreeUsers();
    TestTwoUsers();
    TestOneUser();
    TestZeroUsers();
    TestIntegerUser();
    TestLoopingUser();
}
