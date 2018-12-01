#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define PAMOUNT 2
#define CARD_AMOUNT 10
#define SEED_AMOUNT 1000
#define TROUNDS 20
#define DPREV 3
#define HPREV 2

//RANDOM TESTING SMITHY CARD


int main() {

	printf("Random Testing: Smithy Card\n\n");

	srand(time(NULL));

	struct gameState *stateOfGame;
	int seed = SEED_AMOUNT;
	int players = PAMOUNT;
	
	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };
	
	//current deck
	int dCurr;
	//previous deck
	int dPrev;
		
	//current hand
	int hCurr;
	//previous hand
	int hPrev;
	

	int itr = 0;

	while (itr < TROUNDS) {
		struct gameState *status;
		status = malloc(sizeof(struct gameState) * 1);

		initializeGame(players, k, seed, status);
		stateOfGame = status;

		stateOfGame->handCount[0] = rand() % MAX_HAND;
		stateOfGame->deckCount[0] = rand() % MAX_DECK;

		printf("\nBegin Smithy Random Test:\n");
		dPrev = stateOfGame->deckCount[0];
		hPrev = stateOfGame->handCount[0];

		cardEffect(smithy, 0, 0, 0, stateOfGame, 0, 0);

		dCurr = stateOfGame->deckCount[0];
		hCurr = stateOfGame->handCount[0];

		printf("Expected Hand: %d, Actual Hand: %d\n", hPrev + HPREV, hCurr);

		if (hCurr != hPrev + HPREV) {
			printf("Warning: Test failed. Hand count is not correct.\n");
		}
		else {
			printf("Test Successful!\n");	
		}

		printf("Expected Deck: %d, Actual Deck: %d\n", dPrev - DPREV, dCurr);

		if (dCurr != dPrev - DPREV) {
			printf("Warning: Test failed. Deck count is not correct.\n");
		}
		else {
			printf("Test Successful!\n");
		}

		itr++;
	}

	free(stateOfGame);
}