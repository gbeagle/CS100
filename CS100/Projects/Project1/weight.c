#include <stdio.h>

int main(void){

	/*Grace Beal  | CS100-001 | Project 1
	The code below takes eight numerical inputs: four for each type of bill and four for each type of coin. The code then prints integer values for the total value of bills and total value of change, then calculates and returns as floats the weight of the bills, the weight of the change, and the combined weight of the two.*/

	int billTwenty = 0;
	int billTen = 0;
	int billFive = 0;
	int billOne = 0;
	int coinQuarter = 0;
	int coinDime = 0;
	int coinNickel = 0;
	int coinPenny = 0;
	int billValueTotal = 0;
	int coinValueTotal = 0;
	int billTotal = 0;
	double weightBillTotal = 0;
	double weightCoinTotal = 0;
	double weightMoneyTotal = 0;
	const double WEIGHT_BILL = 1.0;
	const double WEIGHT_QUARTER = 5.67;
	const double WEIGHT_DIME = 2.268;
	const double WEIGHT_NICKEL = 5.0;
	const double WEIGHT_PENNY = 2.5;
	const double CONVERT_POUNDS = 0.00220462;

	printf("Enter the number of $20s you have: ");
	scanf("%d", &billTwenty);
	printf("Enter the number of $10s you have: ");
	scanf("%d", &billTen);
	printf("Enter the number of $5s you have: ");
	scanf("%d", &billFive);
	printf("Enter the number of $1s you have: ");
	scanf("%d", &billOne);
	printf("Enter the number of quarters you have: ");
	scanf("%d", &coinQuarter);
	printf("Enter the number of dimes you have: ");
	scanf("%d", &coinDime);
	printf("Enter the number of nickels you have: ");
	scanf("%d", &coinNickel);
	printf("Enter the number of pennies you have: ");
	scanf("%d", &coinPenny);

	billValueTotal = ((billTwenty * 20) + (billTen * 10) + (billFive * 5) + billOne);
	coinValueTotal = ((coinQuarter * 25) + (coinDime * 10) + (coinNickel * 5) + coinPenny);
	printf("You have %d dollars in bills and %d cents total.\n", billValueTotal, coinValueTotal);

	billTotal = billTwenty + billTen + billFive + billOne;
	weightBillTotal = (double)(billTotal) * WEIGHT_BILL * CONVERT_POUNDS;
	printf("The total weight of your bills is %lf pounds.\n", weightBillTotal);

	weightCoinTotal = (((double)(coinQuarter) * WEIGHT_QUARTER) + ((double)(coinDime) * WEIGHT_DIME) + ((double)(coinNickel) * WEIGHT_NICKEL) + ((double)(coinPenny) * WEIGHT_PENNY));
	weightCoinTotal = weightCoinTotal * CONVERT_POUNDS;
	printf("The total weight of your coins is %lf pounds.\n", weightCoinTotal);

	weightMoneyTotal = weightBillTotal + weightCoinTotal;
	printf("The total weight of your money is %lf pounds.\n", weightMoneyTotal);

	return 0;
}

