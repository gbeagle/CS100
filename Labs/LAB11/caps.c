#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int caps(char *str){
	if( str[0] == '\0' ) {
		return 0;
	}

	if( isupper(str[0]) != 0 ){
		return(1 + caps(str+1) );
	}

	return (0 + caps(str+1) );
}

int main(int argc, char *argv[]) {
	printf("%s contains %d capital letters\n",
		argv[1], caps(argv[1]) );
	return 0;
}
