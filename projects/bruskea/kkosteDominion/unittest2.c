#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define MESET_NUM 23
#define PLAYER_NUM 2
#define GOLD_SUPPLY_AMOUNT 25
#define CHOSEN_PLAYER 0


int main()
{
    printf("gainCard() Test \n");

    struct gameState stateOfGame;
    int seed = SEED_AMOUNT;
	int players = PLAYER_NUM;

	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, steward, cutpurse, sea_hag, tribute, smithy };

    memset(&stateOfGame, MESET_NUM,sizeof(struct gameState));
    initializeGame(players, k, seed, &stateOfGame);

	stateOfGame.supplyCount[gold] = 0;

	if (gainCard(gold, &stateOfGame, 0, 0) != -1) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}

	stateOfGame.supplyCount[gold] = GOLD_SUPPLY_AMOUNT;

    printf("\nDeck Gain Card:\n");
    int dGain = stateOfGame.deckCount[0];
    gainCard(gold, &stateOfGame, 1, CHOSEN_PLAYER);
	dGain++;

	if (dGain != stateOfGame.deckCount[0]) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}

    printf("\n Hand Gain Card: \n");
    int hGain = stateOfGame.handCount[0];
    gainCard(gold, &stateOfGame, 2, CHOSEN_PLAYER);
	hGain++;
	
	if (hGain != stateOfGame.handCount[0]) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}

    printf("\n Discard:\n");
    int dCard = stateOfGame.discardCount[0];
    gainCard(gold, &stateOfGame, 0, CHOSEN_PLAYER);
	dCard++;

	if (dCard != stateOfGame.discardCount[0]) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}

    printf("\n Decrease Gold Supply By 1: \n");
    int dGold = stateOfGame.supplyCount[gold];
    gainCard(gold, &stateOfGame, 0, CHOSEN_PLAYER);
	dGold--;

	if (dGold != stateOfGame.supplyCount[gold]) {
		printf("Warning: Test has Failed.\n");
	}
	else {
		printf("Successful: Test passed\n");
	}

    return 0;
}