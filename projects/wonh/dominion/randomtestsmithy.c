#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>


///////////////////////////////////////////////////
//testSmithy()
//
//This function runs automated random tests on
//the Smithy card.
//
//////////////////////////////////////////////////
void testSmithy()
{
        struct gameState G;
        int k[10] = {};
        int numPlayer = 2;
        int randomSeed = 30;
        int i = 0;

		
        //for random kingdom card pick
        int alreadyPicked[10]={};
        int j = 0;
        int indicator = 0;

        int iteration = 100;

		
        while(iteration > 0)
        {
            int randomKingdom = 0;

			//randomly pick 10 kingdom cards
            for(i = 0; i < 10; i++)
            {
				randomKingdom = rand()%20 + 7;
					
				do{
					indicator = 0;
					for(j = 0; j < 10; j++)
					{
                        if( alreadyPicked[j] == randomKingdom )
                        {
                            indicator = 1;
                        }
								
						if(indicator == 1)
						{
							randomKingdom = rand()%20 + 7;
							j = 0;
							indicator = 0;
						}
					}
				}while(indicator == 1);
										
                    k[i] = randomKingdom;
                    alreadyPicked[i] = randomKingdom;
            }
			
			
            //randomly assigning kindom cards
            initializeGame(numPlayer, k, randomSeed, &G);
			
			int iniDeckCount = rand()%11; //deck count can be 0~10
			int iniHandCount = rand()%11; //hand count can be 0~10
			int iniDiscardCount = rand()%11; //discard count can be 0~10
			
			int randomNum = rand()%11;
			int choice1 = k[randomNum];
			randomNum = rand()%11;
			int choice2 = k[randomNum];
			randomNum = rand()%11;
			int choice3 = k[randomNum];
			randomNum = rand()%11;
			
			int handPos = rand()%(iniDeckCount+1) - 1;
			
			G.deckCount[G.whoseTurn] = iniDeckCount;
			G.handCount[G.whoseTurn] = iniHandCount;
			G.discardCount[G.whoseTurn] = iniDiscardCount;
			
			int result = cardEffect(smithy, choice1, choice2, choice3, &G, handPos, 0);
			
			int postDeckCount = G.deckCount[G.whoseTurn];
			int postHandCount = G.handCount[G.whoseTurn];
			int postDiscardCount = G.discardCount[G.whoseTurn];
			
			int initialSum = iniDeckCount + iniHandCount + iniDiscardCount;
			int postSum = postDeckCount + postHandCount + postDiscardCount;
			
			int handCountError = 0;
			int sumError = 0;
			int deckCountError = 0;
			
			if(!(iniHandCount + 2 == postHandCount))
			{
				handCountError = 1;
			}
			
			if(!(iniDeckCount - 3 == postDeckCount))
			{
				deckCountError = 1;
				if(iniDeckCount < 3)
				{
					if(postDeckCount == iniDiscardCount - iniDiscardCount)
					{
						deckCountError = 0;
					}
				}
			}
			
			
			if(!(initialSum == postSum))
			{
				sumError = 1;
			}
			
			//if( result ==  0 && (sumError == 0) && (handCountError == 0))
			//{
			//	printf("PASS    ");
			//	printf("Initial Hand: %d   Initial Deck: %d   Initial Discard: %d\n", iniHandCount, iniDeckCount, iniDiscardCount, postHandCount);
			//}
			
			
			
			//else
			{
				//printf("\nFAIL!\n");
				if(handCountError == 1)
					printf("Hand Count Error!  Initial Hand: %d   Initial Deck: %d   Initial Discard: %d  Post Hand: %d\n", iniHandCount, iniDeckCount, iniDiscardCount, postHandCount);
				if(deckCountError == 1)
					printf("Deck Count Error!  Initial Hand: %d   Initial Deck: %d   Initial Discard: %d  Post Deck: %d\n", iniHandCount, iniDeckCount, iniDiscardCount, postDeckCount);
				if(sumError == 1)
					printf("Total card# Error!  Initial Sum: %d   Post Sum: %d\n", initialSum, postSum);
				printf("\n");
			}
			
            iteration --;
			
        }
		
}


int main()
{
        //for random# generation
        srand(time(NULL));

        testSmithy();
        return 0;
}
