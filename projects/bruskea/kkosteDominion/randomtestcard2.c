#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define PLAYER_AMOUNT 2
#define HAMOUNT 2
#define PLAYERONE 0
#define CAMOUNT 46
#define SEED_AMOUNT 1000
#define CARD_AMOUNT 10
#define CHOICES 3
#define TROUNDS 20
#define FIRST_CHOICE 1
#define SECOND_CHOICE 2
#define THIRD_CHOICE 3

//RANDOM TESTING STEWARD CARD

int main() {

	srand(time(NULL));
	printf("Random Test: Steward Card\n\n");

	struct gameState *stateOfGame;

	int k[CARD_AMOUNT] = { adventurer, embargo, gardens, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };

	int seed = SEED_AMOUNT;
	int players = PLAYER_AMOUNT;
	int prevCoinAmt;
	int currCoinAmt;

	//current deck
	int dCurr;
	//previous deck
	int dPrev;

	//current hand
	int hCurr;
	//previous hand
	int hPrev;
	

	int itr = 0;
	int itr2 = 0;

	while (itr < CHOICES) {
		while (itr2 < TROUNDS) {
			struct gameState *status;
			status = malloc(sizeof(struct gameState) * 1);

			initializeGame(players, k, seed, status);
			stateOfGame = status;

			if (itr == 0) {
				printf("\nBegin Testing Hand:\n");

				stateOfGame->handCount[0] = rand() % MAX_HAND;
				stateOfGame->deckCount[0] = rand() % MAX_DECK;		

				dPrev = stateOfGame->deckCount[0];
				hPrev = stateOfGame->handCount[0];
				gainCard(steward, stateOfGame, 2, 0);
				cardEffect(steward, FIRST_CHOICE, copper, copper, stateOfGame, stateOfGame->handCount[0] - 1, 0);
				//stewardCardEffect(FIRST_CHOICE, copper, copper, 0, stateOfGame, stateOfGame->handCount[0] - 1);

				dCurr = stateOfGame->deckCount[0];
				hCurr = stateOfGame->handCount[0];

				printf("Expected Hand: %d, Actual Hand: %d\n", hPrev + HAMOUNT, hCurr);

				if (hCurr != hPrev + HAMOUNT) {
					printf("Warning: Test failed. Hand count is not correct.\n");
				}
				else {		
					printf("Test Successful!\n");
				}

				printf("Expected: %d, Actual: %d\n", dPrev - HAMOUNT, dCurr);

				if (dCurr != dPrev - HAMOUNT) {
					printf("Warning: Test failed. Hand count is not correct.\n");
				}
				else {			
					printf("Test Successful!\n");
				}
			}
			else if (itr == 1) {
				printf("\nBegin Testing Coin Count\n");

				stateOfGame->coins = rand() % CAMOUNT;
				prevCoinAmt = stateOfGame->coins;
				hPrev = stateOfGame->handCount[0];

				gainCard(steward, stateOfGame, 2, 0);
				cardEffect(steward, SECOND_CHOICE, copper, copper, stateOfGame, stateOfGame->handCount[0] - 1, 0);
				//stewardCardEffect(SECOND_CHOICE, copper, copper, 0, stateOfGame, stateOfGame->handCount[0] - 1);
				hCurr = stateOfGame->handCount[0];
				currCoinAmt = stateOfGame->coins;
				printf("Expected Coin Count: %d, Actual Coin Count: %d\n", prevCoinAmt + HAMOUNT, currCoinAmt);

				if (currCoinAmt != prevCoinAmt + HAMOUNT) {
					printf("Warning: Test failed. Coin count is not correct.\n");			
				}
				else {
					printf("Test Successful!\n");
				}

				printf("\nHand count:\n");
				printf("Expected Hand Count: %d, Actual Hand Count: %d\n", hPrev, hCurr);
			}
			else {
				stateOfGame->handCount[0] = rand() % MAX_HAND;

				printf("\nHand Count:\n");

				hPrev = stateOfGame->handCount[0];
				gainCard(steward, stateOfGame, 2, 0);
				cardEffect(steward, THIRD_CHOICE, copper, copper, stateOfGame, stateOfGame->handCount[0] - 1, 0);
				//stewardCardEffect(THIRD_CHOICE, copper, copper, 0, stateOfGame, stateOfGame->handCount[0] - 1);
				hCurr = stateOfGame->handCount[0];

				printf("Expected Hand Count: %d, Actual Hand Count: %d\n", hPrev + HAMOUNT, hCurr);

				if (hCurr != hPrev + HAMOUNT) {
					printf("Warning: Test failed. Hand count is not correct.\n");
				}
				else {		
					printf("Test Successful!\n");
				}
			}
			free(stateOfGame);
			itr2++;
		}
		itr++;
	}
}