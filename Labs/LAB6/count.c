//read word from file until EOF, print all words
//user runs via ./a.out filename

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

	while( fscanf(fp, "%s", word) != EOF){	
		int len = strlen(word);		
		int a;
		for(a = 0; a < len; a++){
			if (isupper(word[a])){
				upperCount++;
			}	
			if(islower(word[a])){
				lowerCount++;
			}
		}
	}

	printf("%d uppercase values\n", upperCount);
	printf("%d lowercase values\n", lowerCount);

	fclose(fp);
	return 0;
}
