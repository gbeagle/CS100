#include <stdio.h>
int main(void){
	int windSpeed = 0;

	printf("Enter wind speed (mph): ");
	scanf("%d", &windSpeed);
	if (windSpeed >= 157){
		printf("category 5\n");
	}
	else if (windSpeed >= 130){
		printf("category 4\n");
	}
	else if (windSpeed >= 111){
		printf("category 3\n");
	}
	else if (windSpeed >= 96 ){
		printf("category 2\n");
	}
	else if (windSpeed >= 74){
		printf("category 1\n");
	}
	else if (windSpeed >= 39){
		printf("tropical storm\n");
	}
	else if (windSpeed > 0){
		printf("tropical depression\n");
	}
	else if (windSpeed == 0){
		printf("nothing\n");
	}
	else{
		printf("ERROR\n");
	}


	return 0;
}
