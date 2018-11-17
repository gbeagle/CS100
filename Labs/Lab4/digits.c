#include <stdio.h>

int main(void){

//read digit

	int digit;
	printf("Enter a number: ");
	scanf("%d", &digit);


//extract last digit using % 
	int num;
	int numTest = digit % 10;

	while (digit > 0){
		digit = digit / 10;
		num = digit % 10;
		if(num == numTest){
			printf("Duplicate digits found\n");
			break;
		}
	}

	if(digit == 0 && (num != numTest)){
		printf("No duplicate digits found\n");
	}

//divide by 10, repeat loop

//for digit at position a, iterate through array at position b

//if a = b at any point, print duplicate digits found and 

	return 0;
}
