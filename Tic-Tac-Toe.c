//Tik-Tak-Toe: 2 game modes.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showTable(char table[]);
int gameStatus(char table[], int turns);
void machine_turn(char table[]);
void mode1(int turns, char table[]); // 1vs1
void mode2(int turns, char table[]); // playerVSmachine
int playerTurn(int turns, char table[]);

int main(){
	int gamemode;
	do{
		char table[10] = {'1','2','3','4','5','6','7','8','9','\0'};
		int currentTurn;
		int turns;
		puts("New Game");
		printf("Select the game mode:\n"
			"[1]: 1vs1.\n"
			"[2]: Player vs Machine.\n"
			"[3]: Exit.\n");
		scanf("%d", &gamemode);
		if(gamemode == 1){
			puts("1vs1 Mode:");
			mode1(turns, table);
		}
		else if(gamemode == 2){
			puts("Player vs Machine Mode:");
			mode2(turns, table);
		}
		else if(gamemode == 3){
			break;
		}
		else{
			puts("Option doesn't exist");
		}
	}while(gamemode);
}

int playerTurn(int turns, char table[]){
		int currentTurn;
		showTable(table);
		printf("Choose a number: ");
		scanf("%d", &currentTurn);

		if(currentTurn <= 9 && currentTurn >= 1){
			if(table[currentTurn-1] != 'X' && table[currentTurn-1] != 'O'){
				if(turns % 2 != 0){
					table[currentTurn-1] = 'X';
				}
				else{
					table[currentTurn-1] = 'O';
				}
				return 0;

			}
			else{
				puts("Invalid number, try again.");
				return 1;
			}
		}
		else{
			puts("Invalid number, try again.");
			return 1;

		}
}


// 1 vs 1:
void mode1(int turns, char table[]){
	for(turns=1; turns<=9; ++turns){
		printf("turns = %d\n", turns);
		printf("\n\nPlayer n°%s turn\n", (turns % 2 != 0) ? "1":"2");
		if(playerTurn(turns, table)){
			--turns;
		}

		// 0 = draw	; 1 = p1 win ; 2 = p2 win.		
		if((gameStatus(table, turns)) != 0) {
			showTable(table);
			printf("Game finalized: %s wins\n", (gameStatus(table, turns) % 2 != 0) ? "player1":"player2");
			break;
		}

		if(turns == 9){
			showTable(table);
			puts("Game finalized in a draw");
		}
	}
}

// playerVSmachine:
void mode2(int turns, char table[]){
	for(turns=1; turns<=9; ++turns){
		printf("\n\nPlayer n°%s turn\n", (turns % 2 != 0) ? "1":"2");
		if(turns % 2 != 0){
			if(playerTurn(turns, table)){
				--turns;
			}
		}
		else{
			machine_turn(table);
		}

		// 0 = draw	; 1 = p1 win ; 2 = p2 win.		
		if((gameStatus(table, turns)) != 0) {
			showTable(table);
			printf("Game finalized: %s wins\n", (gameStatus(table, turns) % 2 != 0) ? "player1":"Machine");
			break;
		}

		if(turns == 9){
			showTable(table);
			puts("Game finalized in a draw");
		}
	}
}


void machine_turn(char table[]){
	size_t i;
	do{
		i = 1 + (rand() % 8);
	}while(table[i-1] == 'X' || table[i-1] == 'O');
	
	table[i-1] = 'O';
	printf("Machine choose: %lu\n",i);
}

void showTable(char table[]){
	for(size_t i =0; i<=8; i += 3){
		puts("-------------");
		printf("| %c | %c | %c |\n", table[i], table[i+1], table[i+2]);		
	}
	puts("-------------");
}

int gameStatus(char table[], int turns){

	if((table[0] == table[1]) && (table[0] == table[2]))
		return turns;
	else if((table[0] == table[4]) && (table[0] == table[8]))
		return turns;
	else if((table[0]== table[3]) && (table[0]== table[6]))
		return turns;
	else if((table[3]== table[4]) && (table[3]== table[5]))
		return turns;
	else if((table[1]== table[4]) && (table[1]== table[7]))
		return turns;
	else if((table[6]== table[7]) && (table[6]== table[8]))
		return turns;
	else if((table[6]== table[4]) && (table[6]== table[2]))
		return turns;
	else if((table[2]== table[5]) && (table[2]== table[8]))
		return turns;
	else
		return 0;
}
