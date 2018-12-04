#include <stdio.h>
#include <string.h>
/*	Grace Beal | Project 3 | CS100-001
	This program intakes a series of strings and a line width. It then prints the series of strings backwards and right justified in lines of the specified width.
*/

int main(void){
	int width = 0;
	char word[100];
	
	scanf("%d", &width);
	char line[width];

	while( scanf("%s", word)!= EOF){
	
		if(strlen(line) == 0){
			strcpy(line, word);
			strcat(line, " ");
		}
		else if( width > (strlen(line) + strlen(word))){
			strcat(line, word);
			strcat(line, " ");
		} 
		else if( width == (strlen(line) + strlen(word))){
			strcat(line, word);
		}
		else if (width < (strlen(line) + strlen(word))){
			int a;
			for(a = strlen(line); a < width; a++){
				line[a] = ' ';
			}			
			for(a = (width - 1); a >= 0; a--){
				printf("%c", line[a]);
			}
			printf("\n");
			line[0] = '\0';
			strcpy(line, word);
			strcat(line, " ");
		}
	}

	
	int a;
	for(a = strlen(line); a < width; a++){
		line[a] = ' ';
	}
	for(a = (width - 1); a >= 0; a--){
		printf("%c", line[a]);
	}

return 0;
} 
