#include <stdio.h>
#include <string.h>

int main(void){

	char str1[20];
	char str2[20];
	char str3[20]; 	

	printf("Enter the first string: ");
	scanf("%s", str1);
	printf("Enter the second string: ");
	scanf("%s", str2);
	printf("Enter the third string: ");
	scanf("%s", str3);

	if( (strcmp(str1, str2) == 0) || (strcmp(str1, str3) == 0)){
		printf("%s\n", str1);
	}
	else if ( (strcmp(str2, str3) == 0)){
		printf("%s\n", str2);
	}
	
	return 0;
}
