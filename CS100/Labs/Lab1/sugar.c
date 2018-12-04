#include <stdio.h>

int main(void){

	double amtSugar = 0;
	double numCans = 0;
	const double GRAMS_TO_POUND = 453.592;

	printf("Enter the amount of sugar in this 12-ounce beverage: ");
	scanf("%lf", &amtSugar);

	numCans = (GRAMS_TO_POUND / amtSugar);
	printf("You will need to drink %lf 12-ounce beverages to consume one pound of sugar.\n", numCans);



return 0;
}
