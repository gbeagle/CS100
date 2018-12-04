/*	Grace Beal | Project 4 | CS100-001
	This program reads words from a file on the command line and processes them according to a series of characters on the command line, then prints the word.	*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void funcL(char*);
void funcI(char*);
void funcD(char*);
void funcR(char*);

int main(int count, char *array[]){

	FILE *fp = fopen(array[1], "r"); 
	int cLen = strlen(array[2]);

	if(fp == NULL){
		printf("ERROR: Invalid Filename\n");
		exit(1);
	}

	int b;
	for(b = 0; b < cLen; b++){
		if((array[2][b] != 'L') && (array[2][b] != 'I') && (array[2][b] != 'D') && (array[2][b] != 'R')){
			printf("ERROR: Invalid Character\n");
			exit(1);
		}
	}

	char word[100];
	while(fscanf(fp, "%s", word) != EOF){ 
		int a;
		for(a = 0; a < cLen; a++){
			if ( array[2][a] == 'L'){
				funcL(word);
			}
			if( array[2][a] == 'I'){
				funcI(word);
			}
			if( array[2][a] == 'D'){
				funcD(word);
			}
			if( array[2][a] == 'R'){
				funcR(word);
			}
		}
		printf("%s", word);
		printf("\n");
	}
	return 0;
}

void funcL(char *word){
	int a;
	int len = strlen(word);
	char temp = word[0];
	for(a = 1; a < len; a++){
		word[a-1] = word[a];
	}
	word[len-1] = temp;
	return;
}


void funcI(char *word){
	int a;
	int len = strlen(word);
	for(a = 0; a < len; a++){
		if (isalnum(word[a])){
			word[a] = word[a] + 1;
			if(word[a] == '{' || word[a] == '['){
				word[a] = word[a] - 26;
			}
			if(word[a] == ':'){
				word[a] = word[a] - 10;
			}	
		}
	}
	return;
}

void funcD(char *word){
	int a;
	int len = strlen(word);
	for(a = 0; a < len; a++){
		if(isalnum(word[a])){
			word[a] = word[a] - 1;
			if(word[a] == 96 || word[a] == 64){
				word[a] = word[a] + 26;
			}
			if(word[a] == 47){
				word[a] = word[a] + 10;
			}	
		}
	}
	return;
}


void funcR(char *word){
	int a;
	int len = strlen(word);
	char temp = word[len - 1];
	for(a = len - 1; a >= 0; a--){
		word[a] = word[a - 1];
	}
	word[0] = temp;
	return;
}
