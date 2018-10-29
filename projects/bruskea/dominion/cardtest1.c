
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


#define ADVENT_TREASURE_PLUS 2
#define SEED_AMOUNT 1000
#define PLAYER_NUM 2
#define CARD_AMOUNT 10

int main() {

	printf("Adventurer Card Test: \n");

	struct gameState * stateOfGame;
	struct gameState * status;

	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int players = PLAYER_NUM;
	int seed = SEED_AMOUNT;
	int initialH;
	int nH;
	int i = 0;
	int tH[MAX_HAND];

	status = malloc(sizeof(struct gameState) * 1);

	initializeGame(players, k, seed, status);
	stateOfGame = status;

	printf("Testing adventurer card\n\n");

	initialH = stateOfGame->handCount[0];

	while (i < stateOfGame->handCount[0]) {
		printf(" %d", stateOfGame->hand[0][i]);
		i++;
	}
	i = 0;
	printf("\n\n");

	gainCard(adventurer, stateOfGame, PLAYER_NUM, 0);
	adventurerCardEffect(0, 0, stateOfGame, tH);
	nH = stateOfGame->handCount[0];
	printf("Final Hand Count: %d\n", nH);
	printf("Player 1 Hand After Adventuer Card:");
	while (i < stateOfGame->handCount[0]) {
		printf(" %d", stateOfGame->hand[0][i]);
		i++;
	}
	i = 0;

	if (nH != (ADVENT_TREASURE_PLUS + initialH)) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Final Hand Count: %d\n", nH);
		printf("Player 1 Hand After Adventuer Card:");
		while (i < stateOfGame->handCount[0]) {
			printf(" %d", stateOfGame->hand[0][i]);
			i++;
		}
		printf("Successful: Test passed\n");	
	}
}
