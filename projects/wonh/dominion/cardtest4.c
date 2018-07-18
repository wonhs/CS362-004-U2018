#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// feastEffect()
//
// This card reveals cards from your deck until 2 Treasure cards 
// are revealed. Then the revealed treasure cards go into your hand 
// and discard the other revealed cards into the discard pile.
////////////////////////////////////////////////////////////////////
void testFeastEffect()
{
	struct gameState G;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	initializeGame(numPlayer, k, randomSeed, &G);
	
	int prevHand = G.handCount[G.whoseTurn];
	int prevDeck = G.deckCount[G.whoseTurn];
	int prevDiscard = G.discardCount[G.whoseTurn];

	int choice1 = mine;
	int choice2 = gardens;
	int choice3 = mine;
	int handPo = 3;
	
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	
	//printf("BEFORE:\n");
	//printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	//printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	//printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);
	
	
	int result = cardEffect(feast, choice1, choice2, choice3, &G, handPo, 0);
	
	int postHand = G.handCount[G.whoseTurn];
	int postDeck = G.deckCount[G.whoseTurn];
	int postDiscard = G.discardCount[G.whoseTurn];
	
	//printf("AFTER:\n");
	//printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	//printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	//printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);


	
	if(prevHand - 1 == postHand)
	{
		printf("OK: Hand count changed correctly.\n");
		test1 = 1;
	}
	else
		printf("BUG: Hand count changed inappropriately.\n");
	
	if(prevDeck - 1 == postDeck)
	{
		printf("OK: Deck count changed correctly.\n");
		test2 = 1;
	}
	else
		printf("BUG: Deck count changed inappropriately.\n");
	
	if(prevDiscard + 1 == postDiscard)
	{
		printf("OK: Discard count changed correctly.\n");
		test3 = 1;
	}
	else
		printf("BUG: Discard count changed inappropriately.\n");
	
	if(result == 0 && test1 && test2 && test3)
		printf("testFeastEffect(): PASS - All counts are updated appropriately..\n\n"); 
	else
		printf("testFeastEffect(): FAIL - States changed inappropriately.\n\n");

}

	

int main(int argc, char *argv[])
{
	testFeastEffect();
	return 0;
}

