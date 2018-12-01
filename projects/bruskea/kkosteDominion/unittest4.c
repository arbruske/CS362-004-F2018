#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define CARD_TEST 5
#define CHOSEN_PLAYER 0
#define PLAYER_AMOUNT 2

int main()
{

    struct gameState *stateOfGame;
    int players = PLAYER_AMOUNT;
    int seed = SEED_AMOUNT;
	int count = 0;

	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };


	printf("supplyCount() Test:\n");
	struct gameState *status;
	status = malloc(sizeof(struct gameState) * 1);
	initializeGame(PLAYER_AMOUNT, k, seed, status);
	stateOfGame = status;

	

	

    return 0;
}