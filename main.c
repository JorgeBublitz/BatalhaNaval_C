#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define RED   "\x1B[31m"
#define BLU   "\x1B[34m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"


void inicializaTabuleiro(int tabuleiro[][5]) {
    int linha, coluna;
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            tabuleiro[linha][coluna] = -1;
        }
    }
}

void inicializaShot(int shot[][5]) {
    int linha, coluna;
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            shot[linha][coluna] = -1;
        }
    }
}
void mostraTabuleiroSozinho(int tabuleiroSozinho[][5])
{

    int linha, coluna;

        printf("\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(linha=0 ; linha < 5 ; linha++ ){
            printf("%d",linha+1);
            for(coluna=0 ; coluna < 5 ; coluna++ ){
                if (tabuleiroSozinho[linha][coluna] == -1) {
            	printf("\t|");
                printf(BLU " ~ " RESET);
                printf("|");
            	} else if (tabuleiroSozinho[linha][coluna] == 0) {
                printf(RED "\t| * |" RESET);
            	} else if (tabuleiroSozinho[linha][coluna] == 1) {
                printf(GRN "\t| X |" RESET);
            	}
            }
            printf("\n");
        }
    }


void mostraTabuleiro(int tabuleiro[][5], int tabuleiro2[][5], int score, int score2) {
    int linha, coluna;
    printf("\t\t|| BATALHA NAVAL ||\n\n");
    printf("\t  1 \t  2 \t  3 \t  4 \t  5 \t||Player 1 \t||Score: " YEL "%03d" RESET, score);
    printf("\n");

    for (linha = 0; linha < 5; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < 5; coluna++) {
            if (tabuleiro2[linha][coluna] == -1) {
            	printf("\t|");
                printf(BLU " ~ " RESET);
                printf("|");
            } else if (tabuleiro2[linha][coluna] == 0) {
                printf(RED "\t| * |" RESET);
            } else if (tabuleiro2[linha][coluna] == 1) {
                printf(GRN "\t| X |" RESET);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (linha = 0; linha < 5; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < 5; coluna++) {
            if (tabuleiro[linha][coluna] == -1) {
                printf("\t|");
                printf(BLU " ~ " RESET);
                printf("|");
            } else if (tabuleiro[linha][coluna] == 0) {
                printf(RED "\t| * |" RESET);
            } else if (tabuleiro[linha][coluna] == 1) {
                printf(GRN "\t| X |" RESET);
            }
        }
        printf("\n");
    }
    printf("\t  1 \t  2 \t  3 \t  4 \t  5 \t||Player 2 \t||Score: " YEL "%03d" RESET, score2);
}

void iniciaNavios(int navios[][2], int player) {
    int navio, linha, coluna, coordenadasRepetidas = 0, i, cont = 0;

    for (navio = 0; navio < 1; navio++) {
        coordenadasRepetidas = 0; 
        printf("|| Localização dos navios do Player %d ||\n", player);
        printf("|| Linha (1 - 5): ");
        scanf("%d", &linha);
        if (linha < 1 || linha > 5) {
            printf("Número de linha" RED "inválido" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
        navios[navio][0] = linha - 1;

        printf("|| Coluna (1 - 5): ");
        scanf("%d", &coluna);
        if (coluna < 1 || coluna > 5) {
            printf("Número de coluna" RED "inválido" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            cont++;
            continue;
        }
        navios[navio][1] = coluna - 1;

        for (i = 0; i < navio; i++) {
            if (navios[i][0] == linha - 1 && navios[i][1] == coluna - 1) {
                coordenadasRepetidas = 1;
                break;
            }
        }
    	
        if (coordenadasRepetidas == 1) {
            printf("Coordenadas já foram usadas. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
		
        sleep(2);
        system("cls");
    }
}
void iniciaNaviosSozinho(int navios[][2]){
    srand(time(NULL));
    int navio, anterior;

    // Gerar posições aleatórias para os navios
    for(navio = 0 ; navio < 3 ; navio++){
        navios[navio][0]= rand()%5;
        navios[navio][1]= rand()%5;
    }

    // Verificar e corrigir colisões
    for(navio = 0; navio < 3; navio++){
        for(anterior = 0; anterior < navio; anterior++){
            while((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1])){
                // Corrigir colisão gerando novas posições
                navios[navio][0] = rand() % 5;
                navios[navio][1] = rand() % 5;
                // Reiniciar a verificação com todos os navios anteriores
                anterior = 0;
            }
        }
    }
}

void darTiroSozinho(int tiro[2],int shot1[][5],int tabuleiroSozinho){
int foi = 0, i;
	while(foi == 0){
		system("cls");
		mostraTabuleiroSozinho(tabuleiroSozinho);
    	printf("Linha: ");
    	scanf("%d", &tiro[0]);

   			if (tiro[0] < 1 || tiro[0] > 5) {
            	printf("Número " RED "INVÁLIDO" RESET ". Tente novamente.\n" );
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[0]--;
    
    	printf("Coluna: ");
    	scanf("%d", &tiro[1]);
        	if (tiro[1] < 1 || tiro[1] > 5) {
            	printf("Número " RED "INVÁLIDO" RESET ". Tente novamente.\n");
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[1]--;
    	
			if (shot1[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("já atirou aqui.\n" );
				sleep(2);
				system("cls");
				continue;
			}
		foi = 1;
	}

	shot1[tiro[0]][tiro[1]] = 0;
}


void darTiro(int tiro[2], int player, int tabuleiro, int tabuleiro2, int score, int score2, int shot1[][5], int shot2[][5]) {
	int foi = 0, i;
	while(foi == 0){
		system("cls");
		mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
		printf("\nVez do Player %d\n", player);
    	printf("Linha: ");
    	scanf("%d", &tiro[0]);
    
   			if (tiro[0] < 1 || tiro[0] > 5) {
            	printf("Número " RED "INVÁLIDO" RESET ". Tente novamente.\n" );
            	sleep(2);
            	continue;
        	}
    	tiro[0]--;
    
    	printf("Coluna: ");
    	scanf("%d", &tiro[1]);
        	if (tiro[1] < 1 || tiro[1] > 5) {
            	printf("Número " RED "INVÁLIDO" RESET ". Tente novamente.\n");
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[1]--;
    	
		if (player == 1) {
			if (shot1[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("já atirou aqui.\n" );
				sleep(2);
				continue;
			}
		} else {
			if (shot2[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("já atirou aqui.\n" );
				sleep(2);
				continue;
			}
		}
		foi = 1;
	}
	if (player == 1) {
		shot1[tiro[0]][tiro[1]] = 0;
	} else {
		shot2[tiro[0]][tiro[1]] = 0;
	}
}
int acertouSozinho(int tiro[2], int navios[][2]){
    int navio;

    for(navio = 0; navio < 3; navio++){
        if(tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1]){
            printf(GRN "ACERTOU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
            sleep(1);
            return 1;  // Deve retornar 1 em caso de acerto
        }
    }
    
    printf(RED "ERROU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
    sleep(1);
    return 0;  // Deve retornar 0 em caso de erro
}
    
int acertou(int tiro[2], int navios[][2], int navios2[][2], int player) {
    int navio;
    int acerto = 0;
    
    if (player == 1) {
        for (navio = 0; navio < 3; navio++) { // Check all 3 ships for player 1
            if (tiro[0] == navios2[navio][0] && tiro[1] == navios2[navio][1]) {
                printf("Player 1 " GRN "ACERTOU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
                sleep(2);
                acerto = 1;
                break;
            }
            else if(tiro[0] != navios2[navio][0] && tiro[1] != navios2[navio][1]) {
                printf("Player 1 " RED "ERROU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
                sleep(2);
                acerto = 0;
                break;
        	}
        }
    } else if (player == 2) {
        for (navio = 0; navio < 3; navio++) { // Check all 3 ships for player 2
            if (tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1]) {
                printf("Player 2 " GRN "ACERTOU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
                sleep(2);
                acerto = 1;
                break;
            }
            else if(tiro[0] != navios[navio][0] && tiro[1] != navios[navio][1]) {
                printf("Player 2 " RED "ERROU" RESET " o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
                sleep(2);
                acerto = 0;
                break;
        	}
        }
    }
    return acerto;
}
void alteraTabuleiroSozinho(int tiro[2], int navios[][2], int tabuleiroSozinho[][5], int *acertos1){
    if(acertouSozinho(tiro,navios)){
    	printf("==> Acertou ");
        tabuleiroSozinho[tiro[0]][tiro[1]] = 1;
        *acertos1 += 1;
    }else {
    	printf("==> Errou ");
        tabuleiroSozinho[tiro[0]][tiro[1]] = 0;
   	}
}

void alteraTabuleiro(int tiro[2], int navios[][2],int navios2[][2], int tabuleiro[][5], int tabuleiro2[][5], int player, int *score, int *score2, int *acertos1, int *acertos2) {
    if (acertou(tiro, navios, navios2, player)) {
        if (player == 2) {
            tabuleiro2[tiro[0]][tiro[1]] = 1;
            *score2 += 100;
            *acertos2 += 1;
        } else if (player == 1) {
            tabuleiro[tiro[0]][tiro[1]] = 1;
            *score += 100;
            *acertos1 += 1;
        }
    } else {
        if (player == 2) {
            tabuleiro2[tiro[0]][tiro[1]] = 0;
            if (*score2 == 0){
            	*score2 = *score;
			}else{
				*score2 -= 50;
			}
            
        } else if (player == 1) {
            tabuleiro[tiro[0]][tiro[1]] = 0;
            if (*score == 0){
            	*score = *score;
			}else{
				*score -= 50;
			}
        }
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	int menu = 1;
    char op;
    char escolha = ' ';
    
    int tabuleiroSozinho[5][5];
	int tabuleiro[5][5], tabuleiro2[5][5];
    int shot1[5][5], shot2[5][5];
    int player = 1;
    int tiro[2], tiro2[2];
    int navios[3][2], navios2[3][2];
    int score = 100, score2 = 100, acertos1 = 0, acertos2 = 0;
    int tentativas = 0;
    
	// Tela de boas-vindas
    printf("Bem-vindo ao menu:\n");
    sleep(2);

    // Escolha de jogo
    printf("Escolha seu jogo:\n Batalha Naval - 1 \nJogo da Velha - 2\n");
    scanf(" %c", &op); 

    // Switch case para a escolha de jogo
    switch (op) {
    	
    	// Case Batalha Naval
        case '1':
            printf("Bem-vindo à Batalha Naval\n");
            sleep(2);
            while (menu) {
                // Opções da Batalha Naval
                printf("Opções:\n Single Player - 1\n Multiplayer - 2\n Ranking - 3\n Sair - 0\n");
                scanf(" %c", &escolha);

                
                switch (escolha) {
                	case '1':
                		inicializaTabuleiro(tabuleiroSozinho);
						inicializaShot(shot1);
						iniciaNaviosSozinho(navios);
						system("cls");
						
						// Game Loop
						while (acertos1 != 3){
						    mostraTabuleiroSozinho(tabuleiroSozinho);
						    darTiroSozinho(tiro, shot1, tabuleiroSozinho);
						    tentativas++;
						    alteraTabuleiroSozinho(tiro, navios, tabuleiroSozinho, &acertos1);
						    printf("%d", acertos1);
							sleep(2);
							
						}
						
						// Game Over Message
						printf("\n\n\nJogo terminado. Você acertou os 3 navios em %d tentativas", tentativas);
						mostraTabuleiroSozinho(tabuleiroSozinho);
   					}	
                		
                    case '2':
                    	inicializaTabuleiro(tabuleiro);
				    	inicializaShot(shot1);
				    	iniciaNavios(navios, player);
				    	system("cls");
				    	player = (player == 1) ? 2 : 1;		    
				    	inicializaTabuleiro(tabuleiro2);
				    	inicializaShot(shot2);
				    	iniciaNavios(navios2, player);
				    	system("cls");
				    	player = (player == 1) ? 2 : 1;
				    	do {
					        mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
					        darTiro(tiro, player, tabuleiro, tabuleiro2, score, score2, shot1, shot2);
					        alteraTabuleiro(tiro, navios, navios2, tabuleiro, tabuleiro2, player, &score, &score2, &acertos1, &acertos2);
							player = (player == 1) ? 2 : 1;
							
					        if (acertos1 == 3) {
					            printf("Player 1 venceu!\n");
					            sleep(2);
					            system("cls");
					            break;
					        } else if (acertos2 == 3) {
					            printf("Player 2 venceu!\n");
					            sleep(2);
					            system("cls");
					            break;
					        }
					    	system("cls");
				    	} while (1); 	
					break;
				}
			}
	    return 0;		
		}
