//read word from file until EOF, print all words
//user runs via ./a.out filename

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void countCase(char *, int *, int *, int *);

int main(int count, char *values[]){
	if(count != 2){
		printf("ERROR: usage is './a.out [filename]'\n");
		exit(1);
	}

	char word[50];	

	FILE *fp;	
	fp = fopen(values[1], "r");	
	if( fp == NULL){
		printf("ERROR: Could not open file %s\n", values[1]);	
		exit(1); 
	}

	int upperCount = 0;
	int lowerCount = 0;
	int digitCount = 0;

	while( fscanf(fp, "%s", word) != EOF){	
		countCase(word, &upperCount, &lowerCount, &digitCount);
		printf("%s - %d uppercase, %d lowercase, %d digits\n", word, upperCount, lowerCount, digitCount);
		upperCount = 0;
		lowerCount = 0;
		digitCount = 0;
	}

	fclose(fp);
	return 0;
}

void countCase(char *word, int *upperCount, int *lowerCount, int *digitCount){
	int len = strlen(word);		
	int a;
	for(a = 0; a < len; a++){
		if (isupper(word[a])){
			*upperCount = *upperCount + 1;
		}	
		if(islower(word[a])){
			*lowerCount = *lowerCount + 1;
		}
		if(isdigit(word[a])){
			*digitCount = *digitCount + 1;
		}
	}
return;
}



