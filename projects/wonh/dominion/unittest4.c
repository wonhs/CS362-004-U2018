#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

////////////////////////////////////////////////////////////////////
// testUpdateCoins()
//
// Player's coin gets updated.  The function goes through the
// player's hand then account for coin values for all treasure
// cards.  
// Copper +1
// Silver +2
// Gold +3
////////////////////////////////////////////////////////////////////

void testUpdateCoins()
{
	struct gameState G, G2, G3;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int numPlayer = 2;
	int randomSeed = 30;

	/////////////////////////////////////////////////////////////
	//First Condition
	//  # of coins is 0.
	//	bonus is 0.
	//  1 copper, 1 silver, and 1 gold treasure cards.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G);
	G.handCount[G.whoseTurn] = 3;
	int bonus = 0;
	G.coins = 0;
	G.whoseTurn = 0;
	G.hand[0][0] = copper;
	G.hand[0][1] = silver;
	G.hand[0][2] = gold;

	int previousCoin = G.coins;
	int result = updateCoins(G.whoseTurn, &G, bonus);
	int afterCoin = G.coins;
	
	printf("Coin(before): %d\n", previousCoin);
	printf("Coin(after): %d\n", afterCoin);
	if( (result == 0) && G.coins == bonus + 6)
		printf("updateCoins(): PASS oins increased properly for 0 coin, 1 copper, 1 silver, 1 gold, and 0 bonus.\n"); 
	else
		printf("updateCoins(): FAIL Coins added improperly.\n");
	
	
	
	
	

	/////////////////////////////////////////////////////////////
	//Second Condition
	//  # of coins is 1.
	//	bonus is 0.
	//  1 copper, 1 silver, and 1 gold treasure cards.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G2);
	G2.handCount[G2.whoseTurn] = 3;
	bonus = 0;
	G2.coins = 1;
	G2.whoseTurn = 0;
	G2.hand[0][0] = copper;
	G2.hand[0][1] = silver;
	G2.hand[0][2] = gold;

	previousCoin = G2.coins;
	
	result = updateCoins(G2.whoseTurn, &G2, bonus);
	
	afterCoin = G2.coins;
	printf("Coin(before): %d\n", previousCoin);
	printf("Coin(after): %d\n", afterCoin);
	
	if( (result == 0) && G2.coins == bonus + 6 )  // 6 since the coin values for the state gets reset in updateCoins function
		printf("updateCoins(): PASS Coins increased properly for 1 coin, 1 copper, 1 silver, 1 gold, and 0 bonus.\n"); 
	else
		printf("updateCoins(): FAIL Coins added improperly.\n");
	

	

	/////////////////////////////////////////////////////////////
	//Third Condition
	//  # of coins is 1.
	//	bonus is 1.
	//  1 copper, 1 silver, and 1 gold treasure cards.
	/////////////////////////////////////////////////////////////
	initializeGame(numPlayer, k, randomSeed, &G3);
	G3.handCount[G3.whoseTurn] = 3;
	bonus = 1;
	G3.coins = 1;
	G3.whoseTurn = 0;
	G3.hand[0][0] = copper;
	G3.hand[0][1] = silver;
	G3.hand[0][2] = gold;

	previousCoin = G3.coins;
	
	result = updateCoins(G3.whoseTurn, &G3, bonus);
	afterCoin = G3.coins;
	printf("Coin(before): %d\n", previousCoin);
	printf("Coin(after): %d\n", afterCoin);
	
	if(result == 0 && G3.coins ==  (bonus + 6))
		printf("updateCoins(): PASS Coins increased properly for 1 coin, 1 copper, 1 silver, 1 gold, and 1 bonus.\n"); 
	else
		printf("updateCoins(): FAIL Coins added improperly.\n");

	
	

	
	
}	
	

int main(int argc, char *argv[])
{
	testUpdateCoins();
	return 0;
}

