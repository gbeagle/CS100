#include <stdio.h>
#include <stdlib.h>

int main(int count, char *values[]){
        if(count != 3){
                printf("Usage: ./a.out [filename] [parameter]\n");
                exit(1);
        }

        FILE *fp;
        fp = fopen(values[1], "r");
        if( fp == NULL){
                printf("Could not open file %s\n", values[1]);
                exit(1);
        }
	
	FILE *fp2 = fopen("more.txt", "w");
	FILE *fp3 = fopen("less.txt", "w");
	int param = atoi(values[2]);
	int num = 0;

	while( fscanf(fp,"%d", &num) != EOF){
		if(num > param){
			fprintf(fp2, "%d\n", num);
		}
		if(num < param){
			fprintf(fp3, "%d\n", num);
		}
	}

	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	
	return 0;
}
