#include <stdio.h>
#include <stdlib.h>
int getNumGames(void);
int findWinner(int, int);
void printResults(int, int, int, int);

int main(void){
	srand(0);
	int a, games, p1, p2, ans, ties=0, p1wins=0, p2wins=0;
	games = getNumGames();
	for(a = 0; a < games; a++){
		p1 = rand() % 5;
		p2 = rand() % 5;
		ans = findWinner(p1, p2);
		if (ans == 0) ties++;
		if (ans == 1) p1wins++;
		if (ans == 2) p2wins++;
	}
	printResults(games, ties, p1wins, p2wins);
	return 0;
}

int getNumGames(void){
	int games;
	printf("Enter number of games: ");
	scanf("%d", &games);
	return games;
}

int findWinner(int p1, int p2){
	int ans = 0;
	if (p1 != p2){
		if (p1 == 0){
			if( (p2 == 2) || (p2 == 3) ){
				ans = 1;
			}
			else if( (p2 == 1) || (p2 == 4) ){
				ans = 2;
			}
		}
		else if (p1 == 1){
			if( (p2 == 0) || (p2 == 4) ){
				ans = 1;
			}
			else if( (p2 == 2) || (p2 == 3) ){
				ans = 2;
			}
		}
		else if (p1 == 2){
			if( (p2 == 1) || (p2 == 3) ){
				ans = 1;
			}
			else if( (p2 == 0) || (p2 == 4) ){
				ans = 2;
			}
		}
		else if (p1 == 3){
			if( (p2 == 1) || (p2 == 4) ){
				ans = 1;
			}
			else if( (p2 == 0) || (p2 == 2) ){
				ans = 2;
			}
		}
		else if (p1 == 4){
			if( (p2 == 0) || (p2 == 2) ){
				ans = 1;
			}
			else if( (p2 == 1) || (p2 == 3) ){
				ans = 2;
			}
		}	
	}
	return ans;
}

void printResults(int games, int ties, int p1wins, int p2wins){
	printf("Number of games: %d\n", games);
	printf("Ties: %d\n", ties);
	printf("Player 1 wins: %d\n", p1wins);
	printf("Player 2 wins: %d\n", p2wins);
	return;
}
