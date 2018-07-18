#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testGainCard()
//
// Player gains a card.  Depending on the toFlag parameter value,
// a card can be added to different places, discard pile, deck, or 
// a player's hand. For card supply card #4(copper) was utilized
// for this unit test.
////////////////////////////////////////////////////////////////////

void testGainCard()
{
	struct gameState G, G2, G3;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	/////////////////////////////////////////////////////////////
	//First Condition
	//  toFlag: 0
	//  discard card count should increase.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	G.handCount[G.whoseTurn] = 5;
	G.supplyCount[copper] = 5;
	int toFlag = 0;

	int previousHand = G.handCount[G.whoseTurn];
	int previousDeck = G.deckCount[G.whoseTurn];
	int previousDiscard = G.discardCount[G.whoseTurn];
	
	int result = gainCard(copper, &G, toFlag, G.whoseTurn);
	
	int afterHand = G.handCount[G.whoseTurn];
	int afterDeck = G.deckCount[G.whoseTurn];
	int afterDiscard = G.discardCount[G.whoseTurn];
	
	int test1 = 0;
	
	if(previousDiscard + 1 == afterDiscard)
	{
		printf("Good: Discard count increased properly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Discard Count\n");
	}
	
	if(result == 0 && (G.discardCount[G.whoseTurn] == previousDiscard + 1))
		printf("gainCard(): PASS when toFlag is 0.\n\n"); 
	else
		printf("gainCard(): FAIL when toFlag is 0.\n\n");
	

	
	
	
	/////////////////////////////////////////////////////////////
	//Second Condition
	//  toFlag: 1
	//  Deck card count should increase
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	G2.handCount[G2.whoseTurn] = 5;
	G2.supplyCount[copper] = 5;
	toFlag = 1;

	previousHand = G2.handCount[G2.whoseTurn];
	previousDeck = G2.deckCount[G2.whoseTurn];
	previousDiscard = G2.discardCount[G2.whoseTurn];
	
	result = gainCard(copper, &G2, toFlag, G2.whoseTurn);
	
	afterHand = G2.handCount[G2.whoseTurn];
	afterDeck = G2.deckCount[G2.whoseTurn];
	afterDiscard = G2.discardCount[G2.whoseTurn];
	test1 = 0;
	
	if(previousDeck + 1 == afterDeck)
	{
		printf("Good: Deck card count increased properly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Discard Count\n");
	}
	
	
	if(result == 0 && (G2.discardCount[G2.whoseTurn] == previousDiscard + 1))
		printf("gainCard(): PASS when toFlag is 0.\n\n"); 
	else
		printf("gainCard(): FAIL when toFlag is 0.\n\n");
	

	

	/////////////////////////////////////////////////////////////
	//Third Condition
	//  toFlag: 2
	//  Hand card count should increase.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G3);
	G3.handCount[G3.whoseTurn] = 5;
	G3.supplyCount[copper] = 5;
	toFlag = 2;

	previousHand = G3.handCount[G3.whoseTurn];
	previousDeck = G3.deckCount[G3.whoseTurn];
	previousDiscard = G3.discardCount[G3.whoseTurn];
	
	result = gainCard(copper, &G3, toFlag, G3.whoseTurn);
	
	afterHand = G3.handCount[G3.whoseTurn];
	afterDeck = G3.deckCount[G3.whoseTurn];
	afterDiscard = G3.discardCount[G3.whoseTurn];
	
	if(previousHand + 1 == afterHand)
	{
		printf("Good: Hand card count increased properly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Discard Count\n");
	}
	
	
	if(result == 0 && (G3.deckCount[G3.whoseTurn] == previousDeck + 1))
		printf("gainCard(): PASS when toFlag is 1.\n\n"); 
	else
		printf("gainCard(): FAIL when toFlag is 1.\n\n");

	
}	
	

int main(int argc, char *argv[])
{
	testGainCard();
	return 0;
}

