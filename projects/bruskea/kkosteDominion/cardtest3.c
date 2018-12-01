#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


#define PLAYER_NUM 2
#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define NUM_OF_ROUNDS 4
#define NUM_PREV_HAND 5

int main() {

	printf("CutPurse Test: \n");

	struct gameState * stateOfGame;

	int k[CARD_AMOUNT] = { adventurer, gardens, embargo, village, minion, steward, cutpurse, sea_hag, tribute, smithy };
	int seed = SEED_AMOUNT;
	int players = PLAYER_NUM;
	int nH;
	int prevH;
	int totalPlayers = 1;
	int coinCntPrev;
	int cCnt;
	
	while (totalPlayers < NUM_OF_ROUNDS) {
		struct gameState *status;
		int aItr = 0;
		int bItr = 0;

		status = malloc(sizeof(struct gameState) * 1);
		initializeGame(players, k, seed, status);
		stateOfGame = status;

		coinCntPrev = stateOfGame->coins;
		gainCard(cutpurse, stateOfGame, players, 0);
		printf("Previous Coin: %d\n", coinCntPrev);
		printf("Previous Round: ");

		while (aItr < stateOfGame->handCount[0]) {
			printf(" %d", stateOfGame->hand[0][aItr]);
			aItr++;
		}
		

		printf("\n\n");
		printf("Other Player Rounds before CutPurse Activated:\n\n");
		prevH = NUM_PREV_HAND;

		int presentRound;
		aItr = 1;

		while (aItr < totalPlayers + 1) {
			endTurn(stateOfGame);
			presentRound = whoseTurn(stateOfGame);
			printf("Present Round: %d\n", presentRound);
			printf("Player %d: ", aItr + 1);

			while (bItr < stateOfGame->handCount[aItr]) {
				printf(" %d", stateOfGame->hand[aItr][bItr]);
				bItr++;
			}

			printf("\n\n");
			aItr++;

		}
		aItr = 0;
		bItr = 0;
	

		endTurn(stateOfGame);
		printf("Present Round: %d\n", whoseTurn(stateOfGame));

		cardEffect(cutpurse, 0, 0, 0, stateOfGame, 0, 0);
		cCnt = stateOfGame->coins;

		printf("Current Coins: %d\n", cCnt);
		printf("Player 1 Total Hand Count: %d\n", stateOfGame->handCount[0]);

		nH = stateOfGame->handCount[0];
		printf("Results After Round: ");

		while (aItr < stateOfGame->handCount[0]) {
			printf(" %d", stateOfGame->hand[0][aItr]);
			aItr++;
		}
		aItr = 1;

		if (nH != prevH) {
			printf("Warning: Test has failed!\n");		
		}
		else {
			printf("Test Successful.\n");
		}

		printf("\n\nOther Player Rounds after CutPurse Activated:\n\n");
		while (aItr < totalPlayers + 1) {
			endTurn(stateOfGame);
			printf("Player %d: ", aItr + 1);

			while (bItr  < stateOfGame->handCount[aItr]) {
				printf(" %d", stateOfGame->hand[aItr][bItr]);
				bItr++;
			}
			bItr = 0;
			printf("\n\n");
			nH = stateOfGame->handCount[aItr];

			if (nH != prevH - 1) {
				printf("Warning: Test Hand Count has failed for Player %d.\n", aItr + 1);
			}
			else {
				printf("Test Hand Count Successful for player %d\n", aItr + 1);
				
			}
			aItr++;
		}

		printf("\n");
		free(stateOfGame);
		totalPlayers++;
	}
}