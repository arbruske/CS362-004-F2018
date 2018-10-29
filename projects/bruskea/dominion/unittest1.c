#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

// TESTING isGameOver()
#define PLAYER_NUM 2
#define SEED_AMOUNT 1000
#define NUM_MEMSET 23
#define PASS_CRITERIA 1
#define CARD_AMOUNT 10

int main()
{   
	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	int players = PLAYER_NUM;
	int seed = SEED_AMOUNT;
    struct gameState stateOfGame;
    
    memset(&stateOfGame, NUM_MEMSET, sizeof(struct gameState));
    initializeGame(players, k, seed, &stateOfGame);
    
	printf("Test: isGameOver():\n");

	stateOfGame.supplyCount[province] = 0;

	if (isGameOver(&stateOfGame) != PASS_CRITERIA) {
		printf("Warning: Test has failed. \n");
	}
	else {
		printf("Test Successful! \n");
	}
  
	stateOfGame.supplyCount[province] = 1;
	stateOfGame.supplyCount[0] = 0;
	stateOfGame.supplyCount[1] = 0;
	stateOfGame.supplyCount[2] = 0;

	if (isGameOver(&stateOfGame) != PASS_CRITERIA) {
		printf("Warning: Test has failed. \n");
	}
	else {
		printf("Test Successful! \n");
	}

    return 0;
}