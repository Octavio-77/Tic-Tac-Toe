//tateti
#include <stdio.h>
#define TAMANIO 10
void imprimir_tablero(char x[], int tamanio);
int validar_turno(char turno, char lista_turnos[], int tamanio);
void cambiar_lista(char t, int r, char x[], int tamanio);
int evaluar_estatus(int r, char x[], int tamanio);

void main(){
	int i;
	char x[] = {'1','2','3','4','5','6','7','8','9','\0'};
	char lista_turnos[] = {'*','*','*','*','*','*','*','*','*','\0'};
	int estatus = 3;
	int turnos = 0;
	int turno_valido = 0;
	imprimir_tablero(x,TAMANIO);

	while(estatus == 3){
		int ronda = 1;

		while(ronda <= 2){
			int valido;
			char turno_actual;
			printf("Turno del jugador nº%d\n", ronda);
			printf("Ingrese la casilla: ");
			scanf("\n%c", &turno_actual);

			for(i=0; i<TAMANIO; i++){
				if(turno_actual == x[i]){
					turno_valido = 1;
				}
			}
			if(turno_valido == 1){
				valido = validar_turno(turno_actual, lista_turnos,TAMANIO);

				if(valido == 1){
					cambiar_lista(turno_actual, ronda, x, TAMANIO);
					imprimir_tablero(x, TAMANIO);
					estatus = evaluar_estatus(ronda, x, TAMANIO);
					++ronda;
					++turnos;

					if(estatus != 3){
						ronda = 3;
					}
					else{
						if(turnos == 9){
							ronda = 3;
							estatus = 0;
						}
					}
				}
				else{
					printf("Ingreso una casilla ocupada, vuelva a intentarlo.");
				}
			}
			else{
				printf("Ingreso una casilla incorrecta, vuelva a intentarlo.");
			}
		}
	}
	printf("Juego Terminado\n");
	if(estatus == 1 || estatus == 2){
		printf("Gana el jugador nº%d\n", estatus);
	}
	else
		printf("Es un empate\n");
}

void imprimir_tablero(char a[], int tamanio){
	printf("\n+---+---+---+\n");
	printf("| %c | %c | %c |\n", a[0], a[1], a[2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", a[3], a[4], a[5]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", a[6], a[7], a[8]);
	printf("+---+---+---+\n");
}

int validar_turno(char turno, char lista_turnos[], int tamanio){
	int i, b = 1;
	for(i=0; i<TAMANIO; i++){
		if(turno == lista_turnos[i]){
			++b;
		}
	}
	if(b == 1){
		for(i=0; i<TAMANIO; i++){
			if(lista_turnos[i] == '*'){
				lista_turnos[i] = turno;
				i = 12;
			}
		}
		return 1;
	}
	else{
		return 0;
	}
}

void cambiar_lista(char t, int r, char x[], int tamanio){
	int i;
	char signo;
	if(r == 1)
		signo = 'X';
	else
		signo = 'O';

	for(i=0; i<TAMANIO; i++){
		if(t == x[i]){
			x[i] = signo;
		}
	}
}

int evaluar_estatus(int r, char x[], int tamanio){
	char signo;
	int est;
	if(r == 1){
		signo = 'X';
		est = 1;
	}
	else{
		signo = 'O';
		est = 2;
	}

	if((x[0]== x[1]) && (x[0]== x[2]) && (x[0] == signo))
		return est;
	else if((x[0]== x[4]) && (x[0]== x[8]) && (x[0] == signo))
		return est;
	else if((x[0]== x[3]) && (x[0]== x[6]) && (x[0] == signo))
		return est;
	else if((x[3]== x[4]) && (x[3]== x[5]) && (x[3] == signo))
		return est;
	else if((x[1]== x[4]) && (x[1]== x[7]) && (x[1] == signo))
		return est;
	else if((x[6]== x[7]) && (x[6]== x[8]) && (x[6] == signo))
		return est;
	else if((x[6]== x[4]) && (x[6]== x[2]) && (x[6] == signo))
		return est;
	else if((x[2]== x[5]) && (x[2]== x[8]) && (x[2] == signo))
		return est;
	else
		return 3;
}