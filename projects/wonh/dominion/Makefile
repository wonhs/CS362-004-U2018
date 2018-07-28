CFLAGS = -Wall -fpic -coverage -lm -std=c99

RANDOM_TESTS: randomtestadventurer.c randomtestcard1.c  randomtestcard2.c dominion.c rngs.c
	echo "Result for randomtestadventurer(adventurer card): " >> randomtestadventurer.out
	echo " " >> randomtestadventurer.out
	echo "randomTest1.c: " >> randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out

	echo "Result for randomtestcard1(smithy card): " >> randomtestcard1.out
	echo " " >> randomtestcard1.out
	echo "randomTest2.c: " >> randomtestcard1.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	gcov -b randomtestcard1.c >> randomtestcard1.out
	
	echo "Result for randomtestcard2(village card): " >> randomtestcard2.out
	echo " " >> randomtestcard2.out
	echo "randomTest3.c: " >> randomtestcard2.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	gcov -b randomtestcard2.c >> randomtestcard2.out
	
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
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestcard1 randomtestcard2
