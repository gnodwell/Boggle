#include <stdio.h>
#include <string.h>
#include "WordChecker.h"
#include <ctype.h>

char GetLetter(int i, int j, struct RolledDice **gameBoard){
    return gameBoard[i][j].character;
}

int AbidesRules(int i, int j, char *word, struct RolledDice** gameBoard, int subLen, int **visited){
	int adjCell;
// 	char currentLetter = word[subLen];
// 	int ans = (subLen == (strlen(word)-1));


	if(subLen == (strlen(word)-1)){
		return 1;
	}

	// right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};

// 	int newX;
// 	int newY;

	char findLetter;
	findLetter = word[subLen + 1];
	int result = 0;

		for(adjCell = 0; adjCell < 8; adjCell++){
			int newX = i + allX[adjCell];
			int newY = j + allY[adjCell];
			if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == GetLetter(newX, newY, gameBoard) && !visited[newX][newY]){
				visited[newX][newY] = 1;
				++subLen;
				result = AbidesRules(newX, newY, word, gameBoard, subLen, visited);
			if(result){
				return 1;
			}else{
			--subLen;
			}

			}

		}

		return 0;
}


int WordChecker(struct RolledDice **gameBoard, char *word){

	int m;
	int n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(m = 0; m < 4; m++){
		for(n = 0; n < 4; n++){
			if(m == 0 && n == 0){
				visited[m][n] = 1;
			}else{
			visited[m][n] = 0;
			}
		}
	}

		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if(AbidesRules(row, col, word, gameBoard, 0, visited)){
						free(visited[0]);
						free(visited[1]);
						free(visited[2]);
						free(visited[3]);
					return 1;

				}
			}

		}

	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;

}

char TestGetLetter(int i, int j, char **boggle){

	return boggle[i][j];
}



int TestAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited){
	int adjCell;
	// use subLen as index to see what letter to find
	char currentLetter = word[subLen];
// 	int ans = (subLen == (strlen(word)-1));
	if(subLen == (strlen(word)-1)){
		return 1;
	}

	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};

// 	int newX;
// 	int newY;

	char findLetter;
		if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == TestGetLetter(i,j,gameBoard)){
			 findLetter = word[subLen + 3];
			 subLen++;
			 subLen++;
			 currentLetter = word[subLen];
		}else{
			findLetter = word[subLen + 1];
		}
		int result = 0;

		for(adjCell = 0; adjCell < 8; adjCell++){
			int newX = i + allX[adjCell];
			int newY = j + allY[adjCell];
			if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == TestGetLetter(newX, newY, gameBoard) && !visited[newX][newY]){
				visited[newX][newY] = 1;
				++subLen;
				result = TestAbidesRules(newX, newY, word, gameBoard, subLen, visited);
				if(result){
					return 1;
				}else{
					--subLen;
					}
			}
		}
		return 0;
}


int TestWordChecker(char **boggle, char *word){
/* 	int row, letter, col, m, n;
*/
    int m , n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(m = 0; m < 4; m++){
		for(n = 0; n < 4; n++){
			if(m == 0 && n == 0){
				visited[m][n] = 1;
			}else{
				visited[m][n] = 0;
			}
		}
	}
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if(TestAbidesRules(row, col, word, boggle, 0, visited)){
						free(visited[0]);
						free(visited[1]);
						free(visited[2]);
						free(visited[3]);
					return 1;

				}
			}

		}

	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;


}

int HcWordChecker(char boggle[][4], char *word){

/*	int row, letter, col, m, n;
*/
    int m, n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(m = 0; m < 4; m++){
		for(n = 0; n < 4; n++){
			if(m == 0 && n == 0){
				visited[m][n] = 1;
			}else{
				visited[m][n] = 0;
			}
		}
	}

		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if(HcAbidesRules(row, col, word, boggle, 0, visited)){
						free(visited[0]);
						free(visited[1]);
						free(visited[2]);
						free(visited[3]);
					return 1;

				}
			}

		}

	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;

}


int HcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited){
	int adjCell;
	char currentLetter = word[subLen];
// 	int ans = (subLen == (strlen(word)-1));
	if(subLen == (strlen(word)-1)){
		return 1;
	}

	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
// 	int newX;
// 	int newY;

	char findLetter;
		if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == HcGetLetter(i,j,boggle)){
			 findLetter = word[subLen + 3];
			 subLen++;
			 subLen++;
			 currentLetter = word[subLen];

		}else{
			findLetter = word[subLen + 1];
		}
		int result = 0;

		for(adjCell = 0; adjCell < 8; adjCell++){
			int newX = i + allX[adjCell];
			int newY = j + allY[adjCell];
			if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == HcGetLetter(newX, newY, boggle) && !visited[newX][newY]){
				visited[newX][newY] = 1;
				++subLen;
				result = HcAbidesRules(newX, newY, word, boggle, subLen, visited);

				if(result){
					return 1;
				}else{
					--subLen;
				}

			}

		}

		return 0;
	}



char HcGetLetter(int i, int j, char boggle[][4]){

	return boggle[i][j];
}
