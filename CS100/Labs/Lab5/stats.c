#include <stdio.h>
#include <math.h>
void getData(int, int[]);
double calcMean(int, int[]);
double calcVariance(int, int[], double);
double calcStdDev(double);
void printResults(double,  double, double);

int main(void) {
	int size;
	double mean, variance, stddev;
	printf("Enter array size: ");
	scanf("%d", &size);
	int array[size];
	getData(size, array);
	mean = calcMean(size, array);
	variance = calcVariance(size, array, mean);
	stddev = calcStdDev(variance);
	printResults(mean, variance, stddev);
	return 0;
}

void getData(int size, int array[]){
	int a;
	printf("Enter %d numbers: ", size);
	for(a = 0; a < size; a++){
		scanf("%d", &array[a]);
	}
	return;
}

double calcMean(int size, int array[]){
	int a;
	int sumTotal = 0;
	double mean = 0.0;
	for(a = 0; a < size; a++){
		sumTotal = sumTotal + array[a];
	}

	mean = (double)(sumTotal) / (double)(size);
	return mean;
}

double calcVariance(int size, int array[], double mean){
	int a;
	double diff, diffSquared, sumDiff, variance = 0.0;

	for(a = 0; a < size; a++){
		diff = (double)(array[a]) - mean;
		diffSquared = diff * diff;
		sumDiff = sumDiff + diffSquared;
	}
	
	variance = sumDiff / (double)(size);
	return variance;
}

double calcStdDev(double variance){
	double stddev = 0.0;
	stddev = sqrt(variance);
	return stddev;
}

void printResults(double mean, double variance, double stddev){
	printf("Mean: %lf\n", mean);
	printf("Variance: %lf\n", variance);
	printf("Standard Deviation: %lf\n", stddev);
	return;
}
