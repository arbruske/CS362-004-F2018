
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


#define PLAYER_NUM 2
#define NUM_OF_COINS 2
#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define NUM_OF_CHOICES 3

int main() {

	printf("Steward Card Test: \n");

	struct gameState * stateOfGame;

	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, steward, cutpurse, sea_hag, tribute, smithy };
	int players = PLAYER_NUM;
	int numOfCoins = NUM_OF_COINS;
	int seed = SEED_AMOUNT;
	int initialH;
	int nH;

	//choice
	int ch = 1;
	int cointCntPrev;

	while (ch <= NUM_OF_CHOICES) {

		struct gameState * status;
		int i = 0;
		status = malloc(sizeof(struct gameState) * 1);
		initializeGame(players, k, seed, status);
		stateOfGame = status;

		cointCntPrev = stateOfGame->coins;
		initialH = stateOfGame->handCount[0];

		gainCard(steward, stateOfGame, players, 0);
		cardEffect(steward, 0, 0, 0, stateOfGame, 0, 0);
		nH = stateOfGame->handCount[0];
		printf("Player 1 Hand After Steward Card : ");
		while (i < stateOfGame->handCount[0]) {
			printf(" %d", stateOfGame->hand[0][i]);
			i++;
		}
		i = 0;
		printf("\n");

		if (ch == 1) {
			if (nH != initialH + numOfCoins) {
				printf("Warning: Test has Failed.\n");
			}
			else {
				printf("Successful: Test passed\n");
			}
		}
		else if (ch == numOfCoins) {
			printf("Testing Coin Functionality:\n");
			if (stateOfGame->coins != cointCntPrev + numOfCoins) {
				printf("Warning: Test has Failed.\n");
			}
			else {
				printf("Successful: Test passed\n");
			}
		}
		else {
			printf("TESTING CH 3 Functionality:\n");
			printf("Player 1 Hand After Steward Card :");
			while (i < stateOfGame->handCount[0]) {
				printf(" %d", stateOfGame->hand[0][i]);
				i++;
			}
			i = 0;
			printf("\n");
			if (nH != initialH - numOfCoins) {
				printf("Warning: Test has Failed.\n");
			}
			else {
				printf("Successful: Test passed\n");
			}
			while (i < stateOfGame->handCount[0]) {
				printf(" %d", stateOfGame->hand[0][i]);
				i++;
			}
			i = 0;
			printf("\n");
		}
		free(stateOfGame);
		ch++;
	}
	
}