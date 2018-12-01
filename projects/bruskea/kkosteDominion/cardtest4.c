
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//*****UNIT TEST FOR SMITHY CARD*********


#define SMITHCARDS 3
#define PLAYER_NUM 2
#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10

int main() {

	printf("Smithy Card Test: \n");

	struct gameState * stateOfGame;
	struct gameState * status;

	int seed = SEED_AMOUNT;
	int players = PLAYER_NUM;
	int initialH;
	int nH;
	int i = 0;
	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	status = malloc(sizeof(struct gameState) * 1);

	initializeGame(players, k, seed, status);
	stateOfGame = status;
	//begin testing

	initialH = stateOfGame->handCount[0];
	while (i < stateOfGame->handCount[0]) {
		printf(" %d", stateOfGame->hand[0][i]);
		i++;
	}
	i = 0;

	printf("\n");
	gainCard(smithy, stateOfGame, players, 0);
	cardEffect(smithy, 0, 0, 0, stateOfGame, 0, 0);
	nH = stateOfGame->handCount[0];

	while (i < stateOfGame->handCount[0]) {
		printf(" %d", stateOfGame->hand[0][i]);
		i++;
	}

	printf("\n");

	if (nH != (SMITHCARDS + initialH)) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}
}