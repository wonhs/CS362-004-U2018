#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testDrawCard()
//
// draws a new card into the current player's hand, thus increments
// the handcount by one and will decrement the deck count.  If deck
// is 0 before drawcard is called, the deck pile number will be 
// swapped with the discarded count.
////////////////////////////////////////////////////////////////////

void testDrawCard()
{
	struct gameState G, G2;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	/////////////////////////////////////////////////////////////
	//First Condition
	//  Deck has one or more cards
	//  In the test case, deck count is 5, and the discard pile
	//  has 0 cards.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	
	G.deckCount[G.whoseTurn] = 5;
	G.discardCount[G.whoseTurn] = 0;
	
	int test1 = 0;
	int test2 = 0;
	
	int originalHandCount = G.handCount[G.whoseTurn];
	int originalDeckCount = G.deckCount[G.whoseTurn];
	int result = drawCard(G.whoseTurn, &G);
	
	if( originalHandCount + 1 == G.handCount[G.whoseTurn])
	{
		printf("Good: Hand count increased by 1.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect\n");
	}
	
	if( originalDeckCount - 1 == G.deckCount[G.whoseTurn])
	{
		printf("Good: Deck count Decreased by 1.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect\n");
	}

	
	if(result == 0 && test1 && test2)
		printf("drawCard(): PASS when deck count is 1 or more, and discard count is 0.\n\n"); //deck count is 5 in the test case
	else
		printf("drawCard(): FAIL when deck count is 1 or more, and discard count is 0\n\n");
	
	
	/////////////////////////////////////////////////////////////
	//Second Condition
	//  Deck has 0 cards with 5 cards in the discard pile.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	
	G2.deckCount[G.whoseTurn] = 0;
	G2.discardCount[G.whoseTurn] = 5;
	
	test1 = 0;
	test2 = 0;
	
	originalHandCount = G2.handCount[G2.whoseTurn];
	originalDeckCount = G2.deckCount[G2.whoseTurn];
	int originalDiscardCount = G2.discardCount[G.whoseTurn];
	result = drawCard(G.whoseTurn, &G);
	
	if( G2.deckCount[G.whoseTurn] == originalDiscardCount - 1)
	{
		printf("Good: Deck count refilled by discard pile.  Number updated correctly .\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Deck count incorrect\n");
	}
	
	if( originalHandCount - 1 == G2.handCount[G2.whoseTurn])
	{
		printf("Good: Hand count increased by 1.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect\n");
	}

	
	if(result == 0 && test1 && test2)
		printf("drawCard(): PASS when deck count is 0, and discard count is 1 or more.\n\n"); //deck count is 5 in the test case
	else
		printf("drawCard(): FAIL when deck count is 0, and discard count is 1 or more.\n\n");

}



int main(int argc, char *argv[])
{
	testDrawCard();
	return 0;
}

