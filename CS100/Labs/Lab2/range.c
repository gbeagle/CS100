#include <stdio.h>

int main(void){
	int numOne = 0;
	int numTwo = 0;
	int numThree = 0;
	int numFour = 0;
	int numSmall = 0;
	int numLarge = 0;
	int numRange = 0;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &numOne, &numTwo, &numThree, &numFour);

	if ((numOne < numTwo) && (numOne < numThree) && (numOne < numFour)){
		numSmall = numOne;
		printf("%d ", numOne);
	}
	else if((numTwo < numOne) && (numTwo < numThree) && (numTwo < numFour)){
		numSmall = numTwo;
		printf("%d ", numTwo);
	}
	else if((numThree < numOne) && (numThree < numTwo) && (numThree < numFour)){
		numSmall = numThree;
		printf("%d ", numThree);
	}
	else if((numFour < numOne) && (numFour < numThree) && (numFour < numOne)){
		numSmall = numFour;
		printf("%d ", numFour);
	}




	if ((numOne > numTwo) && (numOne > numThree) && (numOne > numFour)){
		numLarge = numOne;
		printf("%d ", numOne);
	}
	else if((numTwo > numOne) && (numTwo > numThree) && (numTwo > numFour)){
		numLarge = numTwo;
		printf("%d ", numTwo);
	}
	else if((numThree > numOne) && (numThree > numTwo) && (numThree > numFour)){
		numLarge = numThree;
		printf("%d ", numThree);
	}
	else if((numFour > numOne) && (numFour > numThree) && (numFour > numOne)){
		numLarge = numFour;
		printf("%d ", numFour);
	}


	numRange = numLarge - numSmall;
	printf("%d\n", numRange);


	return 0;
}
