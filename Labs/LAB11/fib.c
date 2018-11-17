#include <stdio.h>
#include <stdlib.h>

long count = 0;

long fib(long val){
	count = count + 1;

	if( val == 0 ){
		return 1;
	}

	else if(val == 1){
		return 1;
	}

	else{
		return( fib(val-1) + fib(val-2) );
	}
}

int main(int argc, char *argv[]) {
    long num = atoi(argv[1]);
    long answer = fib(num);
    printf("fib(%ld) = %ld\n", num, answer);
    printf("\tIt took %ld recursive calls\n", count);
    return 0;
}

