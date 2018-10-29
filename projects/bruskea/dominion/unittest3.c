#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define CARD_TEST 5
#define CHOSEN_PLAYER 0
#define PLAYER_AMOUNT 2


int main() {

	struct gameState * stateOfGame;
	int seed = SEED_AMOUNT;
	int cAmount;	
	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int aItr = 0;


	printf("numHandCards() Test:\n\n");

	while (aItr < CARD_TEST) {
		int bItr = 0;
		struct gameState *status;
		status = malloc(sizeof(struct gameState) * 1);
		initializeGame(PLAYER_AMOUNT, k, seed, status);
		stateOfGame = status;
		cAmount = aItr + 1;
		
		while (bItr < cAmount) {
			drawCard(CHOSEN_PLAYER, stateOfGame);
			bItr++;
		}

		assert(numHandCards(stateOfGame) == cAmount + CARD_TEST);
		free(stateOfGame);
		aItr++;
	}

	struct gameState *status;
	status = malloc(sizeof(struct gameState) * 1);
	initializeGame(PLAYER_AMOUNT, k, seed, status);
	stateOfGame = status;

	assert(numHandCards(stateOfGame) == CARD_TEST);
		
	return 0;
}
