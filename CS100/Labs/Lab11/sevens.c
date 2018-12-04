#include <stdio.h>
#include <stdlib.h>

int sevens(int i){
	if(i == 0){
		return 0;
	}

	if(i%10 == 7){
		return (1 + sevens(i/10));
	}

	return (0 + sevens(i/10));
}

int main(int argc, char *argv[]) {
	int val = atoi(argv[1]);
	printf("%d contains %d sevens\n", val, sevens(val) );
	return 0;
}
