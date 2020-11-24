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

/* test passing in a three users in the list 
        Test By: Matthew McArdle ID 1097041*/
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
    /* test passing in a two users in the list 
        Test By: Matthew McArdle ID 1097041*/
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
    /* test passing in a single user in the list 
        Test By: Matthew McArdle ID 1097041*/
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
    /* test passing in a null pointer
        Test By: Matthew McArdle ID 1097041*/
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
    
    /* test passing in a looping linked list
        Test By: Matthew McArdle ID 1097041*/
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
    /* test passing in an inncorrect data type 
        Test By: Matthew McArdle ID 1097041*/
     void TestIntegerUser()
     {
         int result = GetLength(10);
         printf("Result is %d\n", result);
    
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
			 
			 
			 /* test passing in a three users in the list 
        Test By: Matthew McArdle ID 1097041*/
    void TestDataFlowThreeUsers()
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
             printf("TEST PASSED :  TestDataFlowThreeUsers() is working fine for test input of three users, result is %d\n", result);
         } else {
             printf("TEST FAILED : TestDataFlowThreeUsers() is not working fine for test input of three users, result is %d\n", result);
         }
     }
    /* test passing in a two users in the list 
        Test By: Matthew McArdle ID 1097041*/
     void TestDataFlowTwoUsers()
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
             printf("TEST PASSED :  TestDataFlowTwoUsers() is working fine for test input of two users, result is %d\n", result);
         } else {
             printf("TEST FAILED : TestDataFlowTwoUsers() is not working fine for test input of two users, result is %d\n", result);
         }
     }
    /* test passing in a single user in the list 
        Test By: Matthew McArdle ID 1097041*/
     void TestDataFlowOneUser()
     {
         User *userPtr1 = malloc(sizeof(struct user));
         strcpy(userPtr1 -> name, "1");
         userPtr1 -> maxScore = 1;
         userPtr1 -> totalGames = 1;
         userPtr1 -> totalScore = 1;
         userPtr1 -> next = NULL;
    
         int result = GetLength(userPtr1);
         if (result == 1) {
             printf("TEST PASSED :  TestDataFlowOneUser() is working fine for test input of one user, result is %d\n", result);
         } else {
             printf("TEST FAILED : TestDataFlowOneUser() is not working fine for test input of one user, result is %d\n", result);
         }
     }
    /* test passing in a null pointer
        Test By: Matthew McArdle ID 1097041*/
     void TestDataFlowZeroUsers()
     {
         User *userPtr1 = NULL;
    
         int result = GetLength(userPtr1);
         if (result == 0) {
             printf("TEST PASSED :  TestZeroUsers() is working fine for test input of no user, result is %d\n", result);
         } else {
             printf("TEST FAILED : TestZeroUsers() is not working fine for test input of no user, result is %d\n", result);
         }
     }

			/*main function to test*/
			int main (int argc, char **argv){
				 User *head=malloc(sizeof(struct user));


				 TestThreeUsers();
				 TestTwoUsers();
				 TestOneUser();
				 TestZeroUsers();
				 
				 
				 TestDataFlowThreeUsers();
				 TestDataFlowTwoUsers();
				 TestDataFlowOneUser();
				 TestDataFlowZeroUsers();
				 
				 printf("%d -NullHead\n", NullHead(head));
				 
	 /* The below test cases cause the program to crash, these are the FAILURE cases, uncomment one to see the failure */
				
				//  printf("%d -LongName\n", LongName(head));
				//  printf("%d -infiniteHead\n", InfiniteHead(head));
				// TestLoopingUser();
				// TestIntegerUser();


				 free(head);
				 return 0;
			 }
