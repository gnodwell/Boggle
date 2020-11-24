#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// The pre-set dice which keep their values between games.
typedef struct PresetDice {
	char *configurations;
	int position;
} PresetDice;

// The rolled dice which do not keep their values between games.
typedef struct RolledDice {
	char character;
	int position;
} RolledDice;


void InitializePresetDice(struct PresetDice* InputArrayOfDice);
void RollButNotShuffleDice(struct RolledDice* GameDice,
		struct PresetDice* InputArrayOfDice);

void ShuffleRolledDicePositions(struct RolledDice* GameDice);
void PrintGameBoard(struct RolledDice** GameBoard);
void RollDice(struct RolledDice** GameBoard,
		struct PresetDice* InputArrayOfDice);

void ConvertToBoard(char *letters, char ***board);
void PrintHcBoard(char boggle[][4]);

#endif
