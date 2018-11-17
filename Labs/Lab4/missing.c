#include <stdio.h>
#include <string.h>

int main(void){
	int letters[26]; 
	
	int a;
	for(a=0; a<26; a++){
		letters[a] = 0;
	}
	
	char word[100];	
	scanf("%s", word);	

	while (! feof (stdin)){
		int b=0;
		for(b=0; b < strlen(word); b++){
			letters[ word[b] - 'a' ]++;	 
		}

		scanf("%s", word);
	}

	printf("Missing letters: ");
	for(a=0; a<26; a++){
		if( letters[a] == 0){
			printf("%c ", a+97);
		}	
	}
	printf("\n");

	return 0;
}
