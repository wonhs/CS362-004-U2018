#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testSmithy()
//
// Effect of smithy card.  It draws 3 cards into the player's hand,
// and discards the used card.  If the card is not trashed, it goes
// into the played card deck. 
////////////////////////////////////////////////////////////////////
void testSmithy()
{
	struct gameState G, G2;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	/////////////////////////////////////////////////////////////
	//First Condition
	//  Deck has 5 cards
	//  Discard pile has 0 cards
	//  Hand has 5 cards
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	
	G.deckCount[G.whoseTurn] = 5;
	G.handCount[G.whoseTurn] = 5;
	G.discardCount[G.whoseTurn] = 0;
	
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	
	int choice1 = 7;
	int choice2 = 8;
	int choice3 = 9;
	int handPo = 3;
	
	int result = cardEffect(smithy, choice1, choice2, choice3, &G, handPo, 0);
	
	int newDeckCount = G.deckCount[G.whoseTurn];
	int newHandCount = G.handCount[G.whoseTurn];
	int newDiscardCount =G.discardCount[G.whoseTurn];
	
	if (newDeckCount == 2)
	{
		printf("Deck Count: 5 --> %d\n", newDeckCount);
		printf("Deck count changed properly.\n");
		test1 = 1;
	} 
	else
	{
		printf("Deck Count: 5 --> %d\n", newDeckCount);
		printf("Deck count didn't change properly.\n");
	}
	
	if (newHandCount == 7)
	{
		printf("Hand Count: 5 --> %d\n", newHandCount);
		printf("Hand count changed properly.\n");
		test1 = 2;
	}
	else
	{
		printf("Hand Count: 5 --> %d\n", newHandCount);
		printf("Hand count didn't change properly.\n");
	}
	
	if (newDiscardCount == 1)
	{
		printf("Discard Count: 0 --> %d\n", newDiscardCount);
		printf("Discard count changed properly.\n");
		test1 = 3;
	}
	else
	{
		printf("Discard Count: 0 --> %d\n", newDiscardCount);
		printf("Discard count didn't change properly.\n");
	}
	
	if(result == 0 && test1 && test2 && test3)
		printf("testSmithy(): PASS When 5 in deck, 5 in hand, and 5 in discard pile.\n"); 
	else
		printf("testSmithy(): FAIL When 5 in deck, 5 in hand, and 5 in discard pile.\n\n");
	
	/////////////////////////////////////////////////////////////
	//Second Condition
	//  Deck has 0 cards
	//  Discard pile has 5 cards
	//  Hand has 5 cards
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	
	G2.deckCount[G.whoseTurn] = 0;
	G2.handCount[G.whoseTurn] = 5;
	G2.discardCount[G.whoseTurn] = 5;
	
	test1 = 0;
	test2 = 0;
	test3 = 0;
	
	choice1 = 7;
	choice2 = 8;
	choice3 = 9;
	handPo = 3;
	
	result = cardEffect(smithy, choice1, choice2, choice3, &G2, handPo, 0);
	
	newDeckCount = G2.deckCount[G2.whoseTurn];
	newHandCount = G2.handCount[G2.whoseTurn];
	newDiscardCount =G2.discardCount[G2.whoseTurn];
	
	
	if (newDeckCount == 2)
	{
		printf("Deck Count: 0 --> %d\n", newDeckCount);
		printf("Deck count changed properly.\n");
		test1 = 1;
	} 
	else
	{
		printf("Deck Count: 0 --> %d\n", newDeckCount);
		printf("Deck count didn't change properly.\n");
	}
	
	if (newHandCount == 7)
	{
		printf("Hand Count: 5 --> %d\n", newHandCount);
		printf("Hand count changed properly.\n");
		test1 = 1;
	}
	else
	{
		printf("Hand Count: 5 --> %d\n", newHandCount);
		printf("Hand count didn't change properly.\n");
	}
	
	if (newDiscardCount == 1)
	{
		printf("Discard Count: 5 --> %d\n", newDiscardCount);
		printf("Discard count changed properly.\n");
		test1 = 1;
	}
	else
	{
		printf("Discard Count: 5 --> %d\n", newDiscardCount);
		printf("Discard count didn't change properly.\n");
	}
	
	if(result == 0 && test1 && test2 && test3)
		printf("testSmithy(): PASS When 0 in deck, 5 in hand, and 5 in discard pile.\n"); 
	else
		printf("testSmithy(): FAIL When 0 in deck, 5 in hand, and 5 in discard pile.\n\n");
}	
	

int main(int argc, char *argv[])
{
	testSmithy();
	return 0;
}