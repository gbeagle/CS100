#include <stdio.h>
#include <string.h>
/*	|Grace Beal|CS100-001|Project 2|
	This project simulates the "Keeping In Touch Guide" flowchart provided in the document. There are fifteen possible paths.   			*/


int main(void){
	char userstr[20];
	char stry[20] = "yes";
	char strn[20] = "no";
	char strignore[100] = "Do nothing (let them call you)\n";
	char strtext[100] = "Send a quick text about your day\n";
	char strcall[100] = "Call them (and be prepared to spend at least 10 minutes on the phone)\n";

	printf("Who were you thinking about? ");
	scanf("%s", userstr);

	if ( strcmp(userstr, "parents") == 0){
		printf("Mom? ");
		scanf("%s", userstr);
		if (strcmp(userstr, stry) == 0){
			printf("Are things bothering you? ");
			scanf("%s", userstr);
			if (strcmp(userstr, stry) == 0){
				printf("%s", strcall);    
			}
			else if (strcmp(userstr, strn) == 0){
				printf("%s", strtext);
			}
		}
		else if (strcmp(userstr, strn) == 0){
			printf("Talked recently? ");
			scanf("%s", userstr);
			if (strcmp(userstr, stry) == 0){
				printf("%s", strignore);
			}
			else if (strcmp(userstr, strn) == 0){
				printf("%s", strtext);
			}
		}
	}
	else if( strcmp(userstr, "sibling") == 0){
		printf("Younger or older? ");
		scanf("%s", userstr);
		if (strcmp(userstr, "younger")== 0){
			printf("How do they view you? ");
			scanf("%s", userstr);
			if (strcmp(userstr, "hero") == 0){
				printf("Do you have a test tomorrow? ");
				scanf("%s", userstr);
					if (strcmp(userstr, stry) == 0){
						printf("%s", strtext); 
					}
					else if(strcmp(userstr, strn) == 0){
						printf("%s", strcall);  
					}
			}
			else if (strcmp(userstr, "useless") == 0){
				printf("%s", strignore);
			}
		}
		else if(strcmp(userstr, "older")==0){
			printf("Were they always there for you? ");
			scanf("%s", userstr);
			if(strcmp(userstr, stry)==0){
				printf("%s", strcall);
			} 
			else if(strcmp(userstr, strn) == 0){
				printf("Was it due to the way you acted? ");
				scanf("%s", userstr);
				if (strcmp(userstr, stry) == 0){
					printf("%s", strtext);
				}
				else if(strcmp(userstr,strn) == 0){
					printf("%s", strignore);
				}
			}
		}
	}
	else if( strcmp(userstr, "other") == 0){
		printf("Is it one of your grandparents? ");
		scanf ("%s", userstr);
		if (strcmp(userstr, stry) == 0){
			printf("Do they like you? ");
			scanf("%s", userstr);
			if(strcmp(userstr, stry) == 0){
				printf("But do they like everyone? ");
				scanf("%s", userstr);
				if(strcmp(userstr, stry) == 0){
					printf("%s", strtext);
				}
				else if(strcmp(userstr, strn) == 0){
					printf("%s", strcall);
				}
			}
			else if (strcmp(userstr, strn) == 0){
				printf("%s", strignore);
			} 
		}
		else if (strcmp(userstr, strn) == 0){
			printf("Are you in their will? ");
			scanf("%s", userstr);
			if(strcmp(userstr, stry)== 0){
				printf("%s", strcall); 
			}
			else if(strcmp(userstr, strn) == 0){
				printf("%s", strignore);
			}
		}
	}

return 0;
}
