//Tik-Tak-Toe.c: 1vs1 mode

#include <stdio.h>
void showTable(char table[]);
int gameStatus(char table[], int turns);

int main(){
	char table[10] = {'1','2','3','4','5','6','7','8','9','\0'};
	int currentTurn;
	int turns;
	int status = 0; // 0 = draw | 1 = p1 win | 2 = p2 win

	for(turns = 1; turns <= 9; ++turns){
		printf("Player n°%s turn\n", (turn % 2 != 0) ? "1":"2");
		showTable(table);
		printf("Choose a number: ");
		scanf("%d", &currentTurn);

		if(currentTurn <= 9 && currentTurn >= 1){
			if(table[currentTurn-1] != 'X' && table[currentTurn-1] != 'O'){
				if(turns == 1 || turns == 3 || turns == 5 || turns == 7 || turns == 9){
					table[currentTurn-1] = 'X';
				}
				else{
					table[currentTurn-1] = 'O';
				}

				status = gameStatus(table, turns);
			
				if(status == 1) break;
				else if(status == 2) break;
			}
			else{
				puts("Invalid number, try again.");
				--turns;
			}
			

		}
		else{
			puts("Invalid number, try again.");
			--turns;
		}
	}
	showTable(table);
	if(status == 1 || status == 2){
		printf("Game finalized, player n°%d wins\n", status);
	}
	else{
		puts("Game finalized in a draw");
	}
}

void showTable(char table[]){
	puts("-------------");
	printf("| %c | %c | %c |\n", table[0], table[1], table[2]);
	puts("-------------");
	printf("| %c | %c | %c |\n", table[3], table[4], table[5]);
	puts("-------------");
	printf("| %c | %c | %c |\n", table[6], table[7], table[8]);
	puts("-------------");

}

int gameStatus(char table[], int turns){
	int player;
	if(turns % 2 != 0){
		player = 1;
	}
	else{
		player = 2;
	}

	if((table[0] == table[1]) && (table[0] == table[2]))
		return player;
	else if((table[0] == table[4]) && (table[0] == table[8]))
		return player;
	else if((table[0]== table[3]) && (table[0]== table[6]))
		return player;
	else if((table[3]== table[4]) && (table[3]== table[5]))
		return player;
	else if((table[1]== table[4]) && (table[1]== table[7]))
		return player;
	else if((table[6]== table[7]) && (table[6]== table[8]))
		return player;
	else if((table[6]== table[4]) && (table[6]== table[2]))
		return player;
	else if((table[2]== table[5]) && (table[2]== table[8]))
		return player;
	else
		return 0;
}
