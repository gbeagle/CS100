#include <stdio.h>
#include <stdlib.h>

int main(int count, char *values[] ){
	int sum = 0;
	double avg = 0.0;

	int a;
	for(a = 0; a < count; a++){
		sum = sum + atoi(values[a]);
	}

	avg = (double)(sum) / (double)(count - 1);

	printf("The average of these %d numbers is %lf\n.", count - 1, avg);

	return 0;
}
