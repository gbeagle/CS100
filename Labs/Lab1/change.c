#include <stdio.h>

int main(void){

	int numQuarters = 0;
	int numDimes = 0;
	int numNickels = 0;
	int numPennies = 0;
	int totalChange = 0;
	const int QUARTER_VAL = 25;
	const int DIME_VAL = 10;
	const int NICKEL_VAL = 5;

	printf("Enter the number of coins (order: quarters dimes nickels pennies): ");
	scanf("%d %d %d %d", &numQuarters, &numDimes, &numNickels, &numPennies);
	
	totalChange = (numQuarters * QUARTER_VAL) + (numDimes * DIME_VAL) + (numNickels * NICKEL_VAL) + numPennies;
	printf("You have %d cents total.\n", totalChange);


return 0;
}
