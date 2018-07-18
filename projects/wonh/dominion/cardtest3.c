#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testCouncil_roomEffect()
//
// It’s an interesting card. Use of this card will allow you to 
//draw 4 cards from you deck. Then you will get to make one more 
//buy on top of the number of buys you have. A remark is that each 
//of the other players draws a card from their deck as well.
////////////////////////////////////////////////////////////////////
void testCouncil_roomEffect()
{
	struct gameState G;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;
	
	initializeGame(numPlayer, k, randomSeed, &G);
	

	G.whoseTurn = 0;
	G.deckCount[G.whoseTurn] = 5;
	G.handCount[G.whoseTurn] = 5;
	G.discardCount[G.whoseTurn] = 0;
	G.numBuys = 0;
	
	//player
	int prevDeck = 5;
	int prevHand = 5;
	int prevDis = 0 ;
	int preNumBuys = 0;
	
	//other player
	int otherPlayPrevHand = G.handCount[G.whoseTurn + 1];
	
	/*
	printf("BEFORE:\n");
	printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);
	printf("Buy Count: %d \n", G.numBuys);
	printf("Other player Hand Count: %d \n\n", otherPlayPrevHand);
	*/
	
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	int test4 = 0;
	int test5 = 0;
	
	int choice1 = 7;
	int choice2 = 8;
	int choice3 = 9;
	int handPo = 3;
	
	int result = cardEffect(council_room, choice1, choice2, choice3, &G, handPo, 0);
	

	//player
	int afterDeck = G.deckCount[G.whoseTurn];
	int afterHand = G.handCount[G.whoseTurn];
	int afterDis = G.discardCount[G.whoseTurn];
	int afterNumBuys = G.numBuys;
	
	//other player
	int otherPlayAfterHand = G.handCount[G.whoseTurn + 1];
	
	/*
	printf("AFTER:\n");
	printf("Deck Count: %d \n", G.deckCount[G.whoseTurn]);
	printf("Hand Count: %d \n", G.handCount[G.whoseTurn]);
	printf("Discard Count: %d \n", G.discardCount[G.whoseTurn]);
	printf("Buy Count: %d \n", G.numBuys);
	printf("Other player Hand Count: %d \n\n", otherPlayAfterHand);
	*/

	if(prevHand + 3 == afterHand)
	{
		printf("OK: Hand count changed correctly.\n");
		test1 = 1;
	}
	else
		printf("BUG: Hand count changed inappropriately.\n");
	
	if(prevDis + 1 == afterDis)
	{
		printf("OK: Discard count changed correctly.\n");
		test2 = 1;
	}
	else
		printf("BUG: Discard count changed inappropriately.\n");
	
	if(preNumBuys + 1 == afterNumBuys)
	{
		printf("OK: Buy count changed correctly.\n");
		test3 = 1;
	}
	else
		printf("BUG: Buy count  changed inappropriately.\n");
	
	if(prevDeck + 4 == afterDeck)
	{
		printf("OK: Deck count changed correctly.\n");
		test4 = 4;
	}
	else
		printf("BUG: Deck count changed inappropriately.\n");
	
	if(otherPlayPrevHand + 1 == otherPlayAfterHand)
	{
		printf("OK: Other player hand count changed correctly.\n");
		test5 = 4;
	}
	else
		printf("BUG: Other player hand count changed inappropriately.\n");
	

	
	
	if(result == 0 && test1 && test2 && test3 && test4 && test5)
		printf("testCouncil_roomEffect(): PASS - All counts are updated appropriately..\n\n"); 
	else
		printf("testCouncil_roomEffect(): FAIL - States changed inappropriately.\n\n");


}

	

int main(int argc, char *argv[])
{
	testCouncil_roomEffect();
	return 0;
}

