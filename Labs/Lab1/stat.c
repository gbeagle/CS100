#include <stdio.h>

int main(void){

	int numFirst = 0;
	int numSecond = 0;
	int numThird = 0;
	int numFourth = 0;
	double numAverage = 0;
	double const NUMBER_TOTAL = 4.0;

	printf("Enter four numbers: ");
	scanf("%d %d %d %d", &numFirst, &numSecond, &numThird, &numFourth);

	numAverage = ( ((double)(numFirst) + (double)(numSecond) + (double)(numThird) + (double)(numFourth)) / NUMBER_TOTAL);
	printf("The average is %lf.\n", numAverage);


return 0;
}
