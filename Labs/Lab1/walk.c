#include <stdio.h>

int main(void){

	int numHours = 0;
	int numMinutes = 0;
	double totalTime = 0;
	double milesWalked = 0;
	double const MIN_TO_HR = 60.0;
	double const WALK_SPEED = 3.1;

	printf("Enter the number of hours spent walking: ");
	scanf("%d", &numHours);

	printf("Enter the number of minutes spent walking: ");
	scanf("%d", &numMinutes);

	totalTime = (double)(numHours) + ((double)numMinutes / MIN_TO_HR);
	milesWalked = totalTime * WALK_SPEED;
	printf("You have walked %lf miles.\n", milesWalked);

return 0;
}
