CFLAGS = -Wall -fpic -coverage -lm -std=c99

tests.out: testme.c
	gcc -o testme testme.c  $(CFLAGS)
	testme

clean:
	rm -f *.o testme
