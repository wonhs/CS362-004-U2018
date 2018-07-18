#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testDiscardCard()
//
// Player discards a card.  If trash flag is less than 1, a card 
// goes to the played pile.  Then the played card becomes -1.  
// If the card was last of the hand or only card, the player's
// hand count decrements.  If not, the card goes to the discard pile
// then the last card takes the spot.  But the last card spot gets
// assigned by -1.  Then the player's hand counts decrements.
////////////////////////////////////////////////////////////////////

void testDiscardCard()
{
	struct gameState G, G2, G3, G4;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	/////////////////////////////////////////////////////////////
	//First Condition
	//  Trash Flag: 1
	//	Last card in hand discarded
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	G.handCount[G.whoseTurn] = 5;
	int handPos = 4; //last hand
	int trashFlag = 1;
	
	int previousHandCount = G.handCount[G.whoseTurn];
	int previousPlayedCount = G.playedCardCount;
	int previousPlayedCard = G.hand[G.whoseTurn][handPos];
	
	int result = discardCard(handPos, G.whoseTurn, &G, trashFlag);
	
	int afterHandCount = G.handCount[G.whoseTurn];
	int afterPlayedCount = G.playedCardCount;
	int afterPlayedCard = G.hand[G.whoseTurn][handPos];
	
	int test1 = 0;
	int test2 = 0;
	
	if( afterHandCount == previousHandCount - 1)
	{
		printf("Good: Hand count updated correctly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect.\n");
	}
	
	if( afterPlayedCard ==  -1)
	{
		printf("Good: Last played card updated correctly.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Last played card updated incorrect.\n");
	}
	
	
	if(result == 0 && test1 && test2 )
		printf("discardCard(): PASS when trash flag is 1, and last card in hand is discarded.\n\n"); 
	else
		printf("discardCard(): FAIL when trash flag is 1, and last card in hand is discarded.\n\n");
	

	
	
	/////////////////////////////////////////////////////////////
	//Second Condition
	//  Trash Flag: 1
	//  Only Card in hand discarded
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	G2.handCount[G2.whoseTurn] = 1;
	handPos = 0; //last hand
	trashFlag = 1;
	
	previousHandCount = G2.handCount[G2.whoseTurn];
	previousPlayedCount = G2.playedCardCount;
	previousPlayedCard = G2.hand[G.whoseTurn][handPos];
	
	result = discardCard(handPos, G2.whoseTurn, &G2, trashFlag);
	
	afterHandCount = G2.handCount[G2.whoseTurn];
	afterPlayedCount = G2.playedCardCount;
	afterPlayedCard = G2.hand[G2.whoseTurn][handPos];
	
	test1 = 0;
	test2 = 0;
	
	if( afterHandCount == previousHandCount - 1)
	{
		printf("Good: Hand count updated correctly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect.\n");
	}
	
	if( afterPlayedCard ==  -1)
	{
		printf("Good: Last played Hand Position updated correctly.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Last played Hand Position updated incorrect.\n");
	}
	
	
	if(result == 0 && test1 && test2 )
		printf("discardCard(): PASS when trash flag is 1, and the only card in hand is discarded.\n\n"); 
	else
		printf("discardCard(): FAIL when trash flag is 1, and the only card in hand is discarded.\n\n");
	
	
	/////////////////////////////////////////////////////////////
	//Third Condition
	//  Trash Flag: 1
	//	Card being discarded is neither only nor last card.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G3);
	G3.handCount[G3.whoseTurn] = 5;
	handPos = 3; 
	trashFlag = 1;
	
	previousHandCount = G3.handCount[G3.whoseTurn];
	previousPlayedCount = G3.playedCardCount;
	previousPlayedCard = G3.hand[G3.whoseTurn][handPos];
	int previousLastCard = G3.hand[G3.whoseTurn][4];
	
	result = discardCard(handPos, G3.whoseTurn, &G3, trashFlag);
	
	afterHandCount = G3.handCount[G3.whoseTurn];
	afterPlayedCount = G3.playedCardCount;
	afterPlayedCard = G3.hand[G3.whoseTurn][handPos];
	int afterTheLastCard = G3.hand[G3.whoseTurn][previousHandCount - 1];
	
	test1 = 0;
	test2 = 0;
	int test3 = 0;
	
	if( afterHandCount == previousHandCount - 1)
	{
		printf("Good: Hand count updated correctly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect.\n");
	}
	
	if( afterTheLastCard ==  -1)
	{
		printf("Good: Last played card updated correctly.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Last played card updated incorrect.\n");
	}
	
	if( previousLastCard ==  afterPlayedCard)
	{
		printf("Good: Played hand position updated correctly.\n");
		test3 = 1;
	}
	else
	{
		printf("BUG: Played hand position NOT updated correctly.\n");
	}
	
	
	if(result == 0 && test1 && test2 && test3)
		printf("discardCard(): PASS when trash flag is 1, and the card is neither the only or the last one.\n\n"); 
	else
		printf("discardCard(): FAIL when trash flag is 1, and the card is neither the only or the last one.\n\n");
	
	/////////////////////////////////////////////////////////////
	//Fourth Condition
	//  Trash Flag: 0
	//	Last card in hand discarded
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G4);
	G4.handCount[G4.whoseTurn] = 5;
	handPos = 4; 
	trashFlag = 0;
	
	previousHandCount = G4.handCount[G4.whoseTurn];
	previousPlayedCount = G4.playedCardCount;
	previousPlayedCard = G4.hand[G4.whoseTurn][handPos];
	previousLastCard = G4.hand[G4.whoseTurn][4];
	
	result = discardCard(handPos, G4.whoseTurn, &G4, trashFlag);
	
	afterHandCount = G4.handCount[G4.whoseTurn];
	afterPlayedCount = G4.playedCardCount;
	afterPlayedCard = G4.hand[G4.whoseTurn][handPos];
	
	
	test1 = 0;
	test2 = 0;
	test3 = 0;
	
	if( afterHandCount == previousHandCount - 1)
	{
		printf("Good: Hand count updated correctly.\n");
		test1 = 1;
	}
	else
	{
		printf("BUG: Hand count incorrect.\n");
	}
	
	if( afterPlayedCard ==  -1) //updated
	{
		printf("Good: Last played card updated correctly.\n");
		test2 = 1;
	}
	else
	{
		printf("BUG: Last played card updated incorrect.\n");
	}
	
	if( G4.playedCards[previousPlayedCount] ==  previousPlayedCard)
	{
		printf("Good: Last played in played pile becomes the previously played card.\n");
		test3 = 1;
	}
	else
	{
		printf("Played Count:  %d\n", previousPlayedCount);
		printf("After Played Count:  %d\n", afterPlayedCount);
		printf("BEFORE:  %d\n", G4.playedCards[previousPlayedCount]);
		printf("AFTER:  %d\n", previousPlayedCard);
		printf("BUG:  Last played in played pile not updated correctly.\n");
	}
	
	
	if(result == 0 && test1 && test2 && test3)
		printf("discardCard(): PASS when trash flag is 1, and the card is neither the only or the last one.\n\n"); 
	else
		printf("discardCard(): FAIL when trash flag is 1, and the card is neither the only or the last one.\n\n");
}	
	

int main(int argc, char *argv[])
{
	testDiscardCard();
	return 0;
}

