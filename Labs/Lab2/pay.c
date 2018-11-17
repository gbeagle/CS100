#include <stdio.h>

int main(void){
	double hourlyWage = 0;
	int hoursWorked = 0;
	double weeklyPay = 0;

	printf("Enter hourly wage: ");
	scanf("%lf", &hourlyWage);
	
	printf("Enter hours worked: ");
	scanf("%d", &hoursWorked);

	if (hoursWorked <= 40){
		weeklyPay = (hourlyWage) * (double)(hoursWorked);
		printf("$%lf\n ", weeklyPay);
	}

	else if (hoursWorked <= 60){
		weeklyPay = (hourlyWage*1.5) * (double)(hoursWorked - 40) + (hourlyWage * 40.0);
		printf("$%lf\n", weeklyPay);
	}	

	else if (hoursWorked >= 61){
		weeklyPay = (hourlyWage * 2) * (double)(hoursWorked - 60) +  (hourlyWage*1.5*20.0) + (hourlyWage * 40.0);
		printf("$%lf\n", weeklyPay);
	}	 
			
	return 0;
}
