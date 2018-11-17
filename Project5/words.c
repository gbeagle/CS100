/* Grace Beal | CS100-001 | Project 5

   This program creates and populates a two-dimensional array with letters, then searches the array for a given word. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int, char**);
void reset(int, char**);
void LtoR(int, char**, char**, char*, int*, int, int); //intakes solution, word, size, counts, coordinates
void RtoL(int, char**, char**, char*, int*, int, int);
void TtoB(int, char**, char**, char*, int*, int, int);
void BtoT(int, char**, char**, char*, int*, int, int); 

// Andrew definitely wasn't here...

int main(int count, char *array[]){

	int num = atoi(array[1]);
	char **puzzle;
	char **solution;
	FILE *fp = fopen(array[2], "r");
	int a;
	int b;

	if(fp == NULL){
		printf("ERROR: File not found");
		exit(1);
	}

	puzzle = malloc(sizeof(char *) * num);
	for(a = 0; a < num; a++){
		puzzle[a] = malloc(sizeof(char*) * num);
	}

	solution = malloc(sizeof(char *) * num);
	for(a = 0; a < num; a++){
		solution[a] = malloc(sizeof(char*) * num);
	}
	
	for(a = 0; a < num; a++){
		for(b = 0; b < num; b++){
			fscanf(fp, " %c", &puzzle[a][b]);
		}
	}

	reset(num, solution);

	printf("Word puzzle: \n");
	print(num, puzzle);

	char word[num];
	printf("Enter word to find (or 'zzz' to exit): ");
	scanf("%s", word);

	while( strcmp(word, "zzz") != 0){
		int Lcount = 0;
		int Tcount = 0;
		int Bcount = 0;
		int Rcount = 0;
		int total = 0;
	
		for(a = 0; a < num; a++){
			for(b = 0; b < num; b++){
				if(puzzle[a][b] == word[0]){	
					if( (num - b) >= strlen(word)){
						LtoR(num, puzzle, solution, word, &Lcount, a, b);
					}
					if( (num - a) >= strlen(word)){
						TtoB(num, puzzle, solution, word, &Tcount, a, b);
					}
					if((a+1) >= strlen(word)){
						BtoT(num, puzzle, solution, word, &Bcount, a, b);
					}
					if((b+1) >= strlen(word)){
						RtoL(num, puzzle, solution, word, &Rcount, a, b);
					}
				}
			}
		}
		total = Lcount + Tcount + Bcount + Rcount;
		printf("\nThe word %s was found %d times: \n", word, total);
		printf("\t%d times written left-to-right\n", Lcount);
		printf("\t%d times written top-to-bottom\n", Tcount);
		printf("\t%d times written bottom-to-top\n", Bcount);
		printf("\t%d times written right-to-left\n", Rcount);
		printf("\n");
		print(num, solution);
		reset(num, solution);
		printf("Enter word to find (or 'zzz' to exit): ");
		scanf("%s", word);
	}
	return 0;
}


void print(int num, char **array){
	int a;
	for(a = 0; a < num; a++){
		int b;
		for( b = 0; b < num; b++){
			printf("%c ",array[a][b]);
		}
		printf("\n");
	} 
	printf("\n");
	return;
} 



void LtoR(int num, char** puzzle, char ** solution, char *word, int *count, int y, int x){ 
	int c = 0;
	int xo = x;
	int len = strlen(word);
	int a;
	while(puzzle[y][x] == word[c]){
		c++;
		if(word[c] == '\0'){
			*count = *count + 1;
			for(a = 0; a < len; a++){
				solution[y][xo+a] = puzzle[y][xo+a];
			}
			break;
		}
		x++;
	}
	return;
}


void RtoL(int num, char** puzzle, char ** solution, char *word, int *count, int y, int x){ 
	int c = 0;
	int xo = x;
	int len = strlen(word);
	int a;
	while(puzzle[y][x] == word[c]){
		c++;
		if(word[c] == '\0'){
			*count = *count + 1;
			for(a = len-1; a >= 0; a--){
				solution[y][xo-a] = puzzle[y][xo-a];
			}
			break;
		}
		x--;
	}
	return;
}


void TtoB(int num, char** puzzle, char ** solution, char *word, int *count, int y, int x){ 
	int c = 0;
	int yo = y;
	int len = strlen(word);
	int a;
	while(puzzle[y][x] == word[c]){
		c++;
		if(word[c] == '\0'){
			*count = *count + 1;
			for(a = 0; a < len; a++){
				solution[yo+a][x] = puzzle[yo+a][x];
			}
			break;
		}
		y++;
	}
	return;
}


void BtoT(int num, char** puzzle, char ** solution, char *word, int *count, int y, int x){ 
	int c = 0;
	int yo = y;
	int len = strlen(word);
	int a;
	while(puzzle[y][x] == word[c]){
		c++;
		if(word[c] == '\0'){
			*count = *count + 1;
			for(a = len-1; a >= 0; a--){
				solution[yo-a][x] = puzzle[yo-a][x];
			}
			break;
		}
		y--;
	}
	return;
}

void reset(int num, char **array){
	int a;
	for(a = 0; a < num; a++){
		int b;
		for(b = 0; b < num; b++){
			array[a][b] = '.';
		}
	}
	return;
}
