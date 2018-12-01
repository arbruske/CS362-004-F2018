#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define MIN 2
#define MAX 4
#define HAMOUNT 2
#define TROUNDS 20
#define RDECK 15



int main() {
	srand(time(NULL));

	struct gameState *stateOfGame;
	
	int seed = SEED_AMOUNT;
	int itr = 0;
	int handPrev;
	int players;

	int k[CARD_AMOUNT] = { adventurer, embargo, gardens, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };
	
	int hTemp[MAX_HAND];

	printf("\nRandom Test: Adventurer Card\n");

	while (itr < TROUNDS) {
		struct gameState *status;
		status = malloc(sizeof(struct gameState) * 1);
		players = rand() % MAX + MIN;
		initializeGame(players, k, seed, status);
		stateOfGame = status;
		handPrev = stateOfGame->handCount[0];

		printf("Hand:\n");
		stateOfGame->deckCount[0] = rand() % RDECK;
		gainCard(adventurer, stateOfGame, HAMOUNT, 0);
		cardEffect(adventurer, 0, 0, 0, stateOfGame, 0, 0);

		printf("Expected Hand: %d, Actual Hand: %d\n", handPrev + HAMOUNT, stateOfGame->handCount[0]);

		if (handPrev + HAMOUNT != stateOfGame->handCount[0]) {
			printf("Warning: Test failed. Hand count is not correct.\n");
		}
		else {
			printf("Test Successful!\n");
		}

		free(stateOfGame);
		itr++;
	}
	printf("\nAdventurer Card Random Test Complete.\n");
}