/* includes */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct user{
	char name[100];
	int maxScore;
	int totalGames;
	int totalScore;
	struct user *next;

} User;

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

/* test function to see what happens if we pass in a *head
   that constantly links to itself, passing in an empty User pointer
	 Test By: Justin Klein ID 1096403 */
	 int InfiniteHead (User *head){
		 strcpy(head->name, "head");
		 head->maxScore=100;
		 head->totalGames=3;
		 head->totalScore=600;
		 head->next=head;
		 return (GetLength(head));
	 }

	 /* test function to see what happens if we pass in a *head
	    that's null, passing in an empty User pointer
	 	 Test By: Justin Klein ID 1096403 */
	 	 int NullHead (User *head){
	 		 strcpy(head->name, "\0");
	 		 head->maxScore=0;
	 		 head->totalGames=0;
	 		 head->totalScore=0;
	 		 head->next=NULL;
	 		 return (GetLength(head));
	 	 }

		 /* test function to see what happens if we pass in a name
				that's longer than 100 chars, passing in an empty User pointer
			 Test By: Justin Klein ID 1096403 */
			 int LongName (User *head){

				 int i=0;
				 char longName[101];
				 for (i=0; i< 101; i++){
					 longName[i]='a';
				 }

				 strcpy(head->name,longName);
				 head->maxScore=0;
				 head->totalGames=0;
				 head->totalScore=0;
				 head->next=NULL;
				 return (GetLength(head));
			 }

			/*main function to test*/
			int main (int argc, char **argv){
				 User *head=malloc(sizeof(struct user));
				 printf("%d -infiniteHead\n", InfiniteHead(User *head));
				 printf("%d -NullHead\n", NullHead(User *head));
				 printf("%d -LongName\n", LongName(User *head));
				 free(head);
				 return 0;
			 }
