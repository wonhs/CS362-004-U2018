#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testAdventurer()
//
// This card reveals cards from your deck until 2 Treasure cards 
// are revealed. Then the revealed treasure cards go into your hand 
// and discard the other revealed cards into the discard pile.
////////////////////////////////////////////////////////////////////
void testAdventurer()
{
	struct gameState G, G2;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	/////////////////////////////////////////////////////////////
	//First Condition
	//  Deck has 5 cards.
	//  Hand has 5 cards.
	//  Discard has 0 cards
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	
	/*
	printf("Before:\n");
	printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);
	*/
	
	G.deckCount[G.whoseTurn] = 5;
	G.handCount[G.whoseTurn] = 5;
	G.discardCount[G.whoseTurn] = 0;
	
	int prevDeck = 5;
	int prevHand = 5;
	int prevDis = 0 ;
	
	int test = 0;
	
	int choice1 = 7;
	int choice2 = 8;
	int choice3 = 9;
	int handPo = 3;
	
	int result = cardEffect(adventurer, choice1, choice2, choice3, &G, handPo, 0);
	
	int afterDeck = G.deckCount[G.whoseTurn];
	int afterHand = G.handCount[G.whoseTurn];
	int afterDis = G.discardCount[G.whoseTurn];
	
	/*
	printf("After:\n");
	printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);
	*/
	
	if( ((prevDeck + prevHand + prevDis) == (afterDeck + afterHand + afterDis)) && (prevHand + 2 == afterHand))
	{
		printf("OK: Card Number changed in an allowable manner.\n");
		test = 1;
	}
	else
	{
		printf("BUG: Card Number changed inapproriately.\n");
	}
	
	
	
	
	if(result == 0 && test)
		printf("testAdventurer(): PASS When 5 in deck, 5 in hand, and 0 in discard pile.\n\n"); 
	else
		printf("testAdventurer(): FAIL When 5 in deck, 5 in hand, and 0 in discard pile.\n\n");
	
	/////////////////////////////////////////////////////////////
	//Second Condition
	//  Deck has 0 cards.
	//  Hand has 5 cards.
	//  Discard has 5 cards
	//  Without any cards in the deck.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	
	G2.deckCount[G2.whoseTurn] = 0;
	G2.handCount[G2.whoseTurn] = 5;
	G2.discardCount[G2.whoseTurn] = 5;
	
	/*
	printf("Before:\n");
	printf("Deck Count: %d \n", G2.deckCount[G.whoseTurn]);
	printf("Hand Count: %d \n", G2.handCount[G.whoseTurn]);
	printf("Discard Count: %d \n", G2.discardCount[G.whoseTurn]);
	*/

	
	prevDeck = 0;
	prevHand = 5;
	prevDis = 5;
	
	test = 0;
	
	choice1 = 7;
	choice2 = 8;
	choice3 = 9;
	handPo = 3;
	
	result = cardEffect(adventurer, choice1, choice2, choice3, &G2, handPo, 0);
	
	afterDeck = G2.deckCount[G2.whoseTurn];
	afterHand = G2.handCount[G2.whoseTurn];
	afterDis = G2.discardCount[G2.whoseTurn];
	
	/*
	printf("After:\n");
	printf("Deck Count: %d \n", G2.deckCount[G2.whoseTurn]);
	printf("Hand Count: %d \n", G2.handCount[G2.whoseTurn]);
	printf("Discard Count: %d \n", G2.discardCount[G2.whoseTurn]);
	*/
	
	if( ((prevDeck + prevHand + prevDis) == (afterDeck + afterHand + afterDis)) && (prevHand + 2 == afterHand))
	{
		printf("OK: Card Number changed in an allowable manner.\n");
		test = 1;
	}
	else
	{
		printf("BUG: Card Number changed inapproriately.\n");
	}
	
	
	
	
	if(result == 0 && test == 1)
		printf("testAdventurer(): PASS When 5 in deck, 5 in hand, and 0 in discard pile.\n"); 
	else
		printf("testAdventurer(): FAIL When 5 in deck, 5 in hand, and 0 in discard pile.\n");
}

	

int main(int argc, char *argv[])
{
	testAdventurer();
	return 0;
}