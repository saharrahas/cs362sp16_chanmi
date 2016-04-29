//outpost card

#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int failed = 0;

int myassert(int b,char* msg) {
	if (b == 0) {
		printf("FAILED ASSERTION: %s\n",msg);
		failed = 1;
		printf("%d\n",b);
	}
	printf("%d\n",b);
	return 0;
}

void checkasserts() {
	if (!failed) {
		printf ("TEST SUCCESSFULLY COMPLETED.\n");
	}
}  

int main() {
	struct gameState g;
	int value;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
		outpost,baron,tribute};

	initializeGame(2, k, 5, &g);

	cardEffect(outpost,0,0,0,&g,0,0);
	value = g.outpostPlayed;

	myassert(value == 1,"outpost should be more than 0");

	checkasserts();
	return 0;
}