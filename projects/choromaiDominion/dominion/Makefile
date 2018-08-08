CFLAGS = -Wall -fpic -coverage -lm -std=c99

tests.out: randomtestadventurer.c randomtestsmithy.c cardtest1.c cardtest2.c dominion.c rngs.c
	echo "Result for randomtestadventurer(adventurer card): " >> randomtestadventurer.out
	echo " " >> randomtestadventurer.out
	echo "randomTest1.c: " >> randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out

	echo "Result for randomtestsmithy(smithy card): " >> randomtestsmithy.out
	echo " " >> randomtestsmithy.out
	echo "randomTest2.c: " >> randomtestsmithy.out
	gcc -o randomtestsmithy randomtestsmithy.c dominion.c rngs.c $(CFLAGS)
	randomtestsmithy >> randomtestsmithy.out
	gcov dominion.c >> randomtestsmithy.out
	gcov -b randomtestsmithy.c >> randomtestsmithy.out
	
	echo "cardtest1.c:" >> tests.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c  $(CFLAGS)
	cardtest1 >> tests.out
	gcov dominion.c >> tests.out
	
	echo "cardtest2.c:" >> tests.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c  $(CFLAGS)
	cardtest2 >> tests.out
	gcov dominion.c >> tests.out
	
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestsmithy cardtest1 cardtest2

