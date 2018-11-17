#include <stdio.h>
#include <stdlib.h>

int main(void){
	srand(0);

	int numToGen;
	printf("How many random values to generate: ");
	scanf("%d", &numToGen);	

	int x;
	int numCount[100];
	int a;
	int b;

	for(b = 0; b < 100; b++){
		numCount[b] = 0;
	}

	for(a = 0; a < numToGen; a++){
		x = rand() % 100;
		for(b = 0; b < 100; b++){
			if(x == b){
				numCount[b] = numCount[b] + 1;
			}
		}
		
	}

	int uniqueVals = 0;
	for(b = 0; b < 100; b++){
		if(numCount[b] > 0){
			uniqueVals = uniqueVals + 1;
		}
	}

	printf("%d random numbers generated %d out of 100 possible values.\n", numToGen, uniqueVals);

	return 0;
}
