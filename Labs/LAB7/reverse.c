#include <stdio.h>
#include <string.h>
void reverse(char*);

int main(int count, char *array[]){
	int a;
	for(a = (count-1); a >= 0; a--){
		reverse(array[a]);
		printf("%s\n", array[a]);
	}
	
return 0;
}

void reverse(char *word){
	int len = strlen(word);
	int a;
	char tempchar;
	for(a = 0; a < (len / 2); a++){
		tempchar = word[a];
		word[a] = word[len - 1 - a];
		word[len - 1 - a] = tempchar;
	}
	return;
}

