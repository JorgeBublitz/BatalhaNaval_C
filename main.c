#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define RED   "\x1B[31m"
#define BLU   "\x1B[34m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

void iniciarTabuleiroPersonalizadoMult(int tabuleiroPersonalizado[][10], int qL, int qC) {
    int linha, coluna;
    for (linha = 0; linha < qL; linha++) {
        for (coluna = 0; coluna < qC; coluna++) {
            tabuleiroPersonalizado[linha][coluna] = -1;
        }
    }
}

void iniciarShotPersonalizado(int shotPersonalizado[][10], int qL, int qC) {
    int linha, coluna;
    for (linha = 0; linha < qL; linha++) {
        for (coluna = 0; coluna < qC; coluna++) {
            shotPersonalizado[linha][coluna] = -1;
        }
    }
}

void mostraTabuleiroPersonalizadoMult(int tabuleiroPersonalizado[][10], int tabuleiroPersonalizado2[][10], int qL, int qC) {
    int linha, coluna;
    printf("\t\t\t BATALHA NAVAL\n");

    printf("\n");
    for (linha = 0; linha < qL; linha++) {
        printf("%d\t", linha + 1);
        for (coluna = 0; coluna < qC; coluna++) {
            if (tabuleiroPersonalizado[linha][coluna] == -1) {
                printf("|"BLU"~"RESET"|");
            } else if (tabuleiroPersonalizado[linha][coluna] == 0) {
                printf(RED"|*|"RESET);
            } else if (tabuleiroPersonalizado[linha][coluna] == 1) {
                printf(GRN"|X|"RESET);
            }
        }
        printf("\n");
    }

    printf("\n\n");

    for (linha = 0; linha < qL; linha++) {
        printf("%d\t", linha + 1);
        for (coluna = 0; coluna < qC; coluna++) {
            if (tabuleiroPersonalizado2[linha][coluna] == -1) {
                printf("|"BLU"~"RESET"|");
            } else if (tabuleiroPersonalizado2[linha][coluna] == 0) {
                printf(RED"|*|"RESET);
            } else if (tabuleiroPersonalizado2[linha][coluna] == 1) {
                printf(GRN"|X|"RESET);
            }
        }
        printf("\n");
    }
}

void iniciaNaviosPersonalizadoMult(int navios[][2], int player, int qL, int qC) {
    int navio, linha, coluna, coordenadasRepetidas = 0, i, cont = 0;

    for (navio = 0; navio < 3; navio++) {
    	printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
        coordenadasRepetidas = 0;
        printf("|| Localiza��o dos navios do Player %d ||\n", player);
        printf("|| Linha (1 - %d): ", qL);
        scanf("%d", &linha);
        if (linha < 1 || linha > qL) {
            printf("Numero de linha invalido. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
        navios[navio][0] = linha - 1;

        printf("|| Coluna (1 - %d): ", qC);
        scanf("%d", &coluna);
        if (coluna < 1 || coluna > qC) {
            printf("Numero de coluna invalido. Tente novamente.\n");
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
            printf("Coordenadas j� foram usadas. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }

        sleep(2);
        system("cls");
    }
}

void darTiroPersonalizadoMult(int tiroPersonalizado[2], int tabuleiroPersonalizado[][10], int tabuleiroPersonalizado2[][10],int score, int score2, int shotPersonalizado[][10], int shotPersonalizado2[][10], int qL, int qC, int player) {
    int foi = 0, i;
    while (foi == 0) {
        printf("\n\nVez do Player %d", player);
        printf("\nLinha: ");
        scanf("%d", &tiroPersonalizado[0]);
        if (tiroPersonalizado[0] < 1 || tiroPersonalizado[0] > qL) {
            printf("Numero invalido. Tente novamente");
            sleep(2);
            system("cls");
            continue;
        }
        tiroPersonalizado[0]--;

        printf("Coluna: ");
        scanf("%d", &tiroPersonalizado[1]);
        if (tiroPersonalizado[1] < 1 || tiroPersonalizado[1] > qC) {
            printf("Numero invalido. Tente novamente");
            sleep(2);
            system("cls");
            continue;
        }
        tiroPersonalizado[1]--;

        if (player == 1) {
            if (shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] == 0) {
                printf("J� atirou aqui. \n");
                sleep(2);
                system("cls");
                continue;
            }
            foi = 1;
        } else if(player == 2) {
            if (shotPersonalizado2[tiroPersonalizado[0]][tiroPersonalizado[1]] == 0) {
                printf("J� atirou aqui. \n");
                sleep(2);
                system("cls");
                continue;
            }
            foi = 1;
        }
    }

    if (player == 1) {
        shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
    } else if(player == 2) {
        shotPersonalizado2[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
    }
}


int acertouPersonalizadoMult(int tiroPersonalizado[2], int naviosPersonalizado[][2], int naviosPersonalizado2[][2], int player) {
    int navio;
    int acerto = 0;
    
    if (player == 1) {
        for (navio = 0; navio < 3; navio++) { // Check all 3 ships for player 1
            if (tiroPersonalizado[0] == naviosPersonalizado2[navio][0] && tiroPersonalizado[1] == naviosPersonalizado2[navio][1]) {
                printf("Player 1 "  "ACERTOU"  " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
                sleep(2);
                acerto = 1;
                break;
            }
            else if(tiroPersonalizado[0] != naviosPersonalizado2[navio][0] && tiroPersonalizado[1] != naviosPersonalizado2[navio][1]) {
                printf("Player 1 " "ERROU" " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
                sleep(2);
                acerto = 0;
                break;
        	}
        }
    } else if (player == 2) {
        for (navio = 0; navio < 3; navio++) { // Check all 3 ships for player 2
            if (tiroPersonalizado[0] == naviosPersonalizado[navio][0] && tiroPersonalizado[1] == naviosPersonalizado[navio][1]) {
                printf("Player 2 "  "ACERTOU"  " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
                sleep(2);
                acerto = 1;
                break;
            }
            else if(tiroPersonalizado[0] != naviosPersonalizado[navio][0] && tiroPersonalizado[1] != naviosPersonalizado[navio][1]) {
                printf("Player 2 " "ERROU" " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
                sleep(2);
                acerto = 0;
                break;
        	}
        }
    }
    return acerto;
}

void alteraTabuleiroPersonalizadoMult(int tiroPersonalizado[2], int naviosPersonalizado[][2],int naviosPersonalizado2[][2], int tabuleiroPersonalizado[][10], int tabuleiroPersonalizado2[][10], int player, int *score, int *score2, int *acertos1, int *acertos2) {
    if (acertouPersonalizado(tiroPersonalizado, naviosPersonalizado, naviosPersonalizado2, player)) {
        if (player == 2) {
            tabuleiroPersonalizado2[tiroPersonalizado[0]][tiroPersonalizado[1]] = 1;
            *score2 += 100;
            *acertos2 += 1;
        } else if (player == 1) {
            tabuleiroPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 1;
            *score += 100;
            *acertos1 += 1;
        }
    } else {
        if (player == 2) {
            tabuleiroPersonalizado2[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
            if (*score2 == 0){
            	*score2 = *score;
			}else{
				*score2 -= 50;
			}
            
        } else if (player == 1) {
            tabuleiroPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
            if (*score == 0){
            	*score = *score;
			}else{
				*score -= 50;
			}
        }
    }
}





//JOGO PERSONALISADO

void inicializaTabuleiroPersonalizado(int tabuleiro[][15], int qL, int qC) {
    int linha, coluna;
    for (linha = 0; linha < qL; linha++) {
        for (coluna = 0; coluna < qC; coluna++) {
            tabuleiro[linha][coluna] = -1;
        }
    }
}

void inicializaShotPersonalizado(int shot[][15], int qL, int qC) {
    int linha, coluna;
    for (linha = 0; linha < qL; linha++) {
        for (coluna = 0; coluna < qC; coluna++) {
            shot[linha][coluna] = -1;
        }
    }
}

void mostraTabuleiroPersonalizado(int tabuleiroPersonalizado[][15], int qL, int qC) {
    int linha, coluna;
    printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
    printf("      ");
    for (linha = 0; linha < qC; linha++) {
        if (linha <= 8) {
            printf("    %d", linha + 1);
        } else {
            printf("   %d", linha + 1);
        }
    }
    printf("\n");

    for(linha=0 ; linha < qL ; linha++ ){
        printf(YEL "%d\t" RESET,linha+1);
        for(coluna=0 ; coluna < qC ; coluna++ ){
            if (tabuleiroPersonalizado[linha][coluna] == -1) {
            	printf("|");
                printf(BLU " ~ " RESET);
                printf("|");
           	} else if (tabuleiroPersonalizado[linha][coluna] == 0) {
                printf(RED "| * |" RESET);
           	} else if (tabuleiroPersonalizado[linha][coluna] == 1) {
                printf(GRN "| X |" RESET);
           	}
        }
        printf("\n");
    }
    printf("\n");
}

void iniciaNaviosPersonalizado(int navios[][2], int qL, int qC) {
    srand(time(NULL));
    int navio, anterior;

    for (navio = 0; navio < 3; navio++) {
        navios[navio][0] = rand() % qL;
        navios[navio][1] = rand() % qC;

        // Verifica se a posição já foi ocupada por outro navio
        for (anterior = 0; anterior < navio; anterior++) {
            while ((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1])) {
                navios[navio][0] = rand() % qL;
                navios[navio][1] = rand() % qC;
                anterior = 0;  // Reinicia a verificação desde o início
            }
        }
    }
}

void darTiroPersonalizado(int tiroPersonalizado[2],int shotPersonalizado[][15],int tabuleiroPersonalizado[][15], int naviosPersonalizado[][2], int qL, int qC){
int foi = 0, i;
	while(foi == 0){
		system("cls");
		mostraTabuleiroPersonalizado(tabuleiroPersonalizado, qL, qC);
    	printf("Linha: ");
    	scanf("%d", &tiroPersonalizado[0]);
    		if (tiroPersonalizado[0] == 777){
				for(i = 0; i < 3; i++){
			        printf("Tiro (%d,%d)\n", naviosPersonalizado[i][0] + 1, naviosPersonalizado[i][1] + 1);
			    }
			    sleep(2);
			    continue;
			}
   			else if (tiroPersonalizado[0] < 1 || tiroPersonalizado[0] > qL) {
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiroPersonalizado[0]--;
    
    	printf("Coluna: ");
    	scanf("%d", &tiroPersonalizado[1]);
        	if (tiroPersonalizado[1] < 1 || tiroPersonalizado[1] > qC) {
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiroPersonalizado[1]--;
    	
			if (shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] == 0) {
				// já atirou aqui
				printf("Ja atirou aqui.\n" );
				sleep(2);
				system("cls");
				continue;
			}
		foi = 1;
	}

	shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
}


int acertouPersonalizado(int tiroPersonalizado[2], int naviosPersonalizado[][2])
{
    int navio;
        for(navio=0 ; navio < 3 ; navio++){
            if( tiroPersonalizado[0]==naviosPersonalizado[navio][0] && tiroPersonalizado[1]==naviosPersonalizado[navio][1]){
                printf("Voce acertou o tiro (%d,%d)\n",tiroPersonalizado[0]+1,tiroPersonalizado[1]+1);
                return 1;
            }
        }
        return 0;
    }

void alteraTabuleiroPersonalizado(int tiroPersonalizado[2], int naviosPersonalizado[][2], int tabuleiroPersonalizado[][15], int *acertos1) {
    if (acertouPersonalizado(tiroPersonalizado, naviosPersonalizado)) {
        tabuleiroPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 1;
        *acertos1 += 1;
    } else {
        tabuleiroPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
    }
}

//JOGO 1 JOGADOR

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
    	printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);

        printf(YEL "\t    1    2    3    4    5" RESET);
        printf("\n");

        for(linha=0 ; linha < 5 ; linha++ ){
            printf(YEL "\t%d " RESET,linha+1);
            for(coluna=0 ; coluna < 5 ; coluna++ ){
                if (tabuleiroSozinho[linha][coluna] == -1) {
            	printf("|");
                printf(BLU " ~ " RESET);
                printf("|");
            	} else if (tabuleiroSozinho[linha][coluna] == 0) {
                printf(RED "| * |" RESET);
            	} else if (tabuleiroSozinho[linha][coluna] == 1) {
                printf(GRN "| X |" RESET);
            	}
            }
            printf("\n");
        }
        printf("\n");
    }


void mostraTabuleiro(int tabuleiro[][5], int tabuleiro2[][5], int score, int score2) {
    int linha, coluna;
    printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
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

    for (navio = 0; navio < 3; navio++) {
        coordenadasRepetidas = 0; 
        printf("|| Localiza��o dos navios do Player %d ||\n", player);
        printf("|| Linha (1 - 5): ");
        scanf("%d", &linha);
        if (linha < 1 || linha > 5) {
            printf("Numero de linha" RED "invalido" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
        navios[navio][0] = linha - 1;

        printf("|| Coluna (1 - 5): ");
        scanf("%d", &coluna);
        if (coluna < 1 || coluna > 5) {
            printf("Numero de coluna" RED "invalido" RESET ". Tente novamente.\n");
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
            printf("Coordenadas ja foram usadas. Tente novamente.\n");
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

void darTiroSozinho(int tiro[2],int shot1[][5],int tabuleiroSozinho, int navios[][2], int *tentativas){
int foi = 0, i;
	while(foi == 0){
		system("cls");
		mostraTabuleiroSozinho(tabuleiroSozinho);
    	printf("Linha: ");
    	scanf("%d", &tiro[0]);
    		if (tiro[0] == 777){
				for(i = 0; i < 3; i++){
			        printf("Tiro (%d,%d)\n", navios[i][0] + 1, navios[i][1] + 1);
			    }
			    sleep(2);
			    continue;
			}
   			else if (tiro[0] < 1 || tiro[0] > 5) {
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[0]--;
    
    	printf("Coluna: ");
    	scanf("%d", &tiro[1]);
        	if (tiro[1] < 1 || tiro[1] > 5) {
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[1]--;
    	
			if (shot1[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("Ja atirou aqui.\n" );
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
		printf("\n\nVez do Player %d\n", player);
    	printf("Linha: ");
    	scanf("%d", &tiro[0]);
    		if (tiro[0] < 1 || tiro[0] > 5) {
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
            	sleep(2);
            	continue;
        	}
    	tiro[0]--;
    
    	printf("Coluna: ");
    	scanf("%d", &tiro[1]);
    		if (tiro[1] < 1 || tiro[1] > 5) {	
            	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
            	sleep(2);
            	system("cls");
            	continue;
        	}
    	tiro[1]--;
    	
		if (player == 1) {
			if (shot1[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("Ja atirou aqui.\n" );
				sleep(2);
				continue;
			}
		} else {
			if (shot2[tiro[0]][tiro[1]] == 0) {
				// já atirou aqui
				printf("Ja atirou aqui.\n" );
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
int acertouSozinho(int tiro[2], int navios[][2], int *tentativas){
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
void alteraTabuleiroSozinho(int tiro[2], int navios[][2], int tabuleiroSozinho[][5], int *acertos1, int *tentativas){
    if(acertouSozinho(tiro,navios,tentativas)){
        tabuleiroSozinho[tiro[0]][tiro[1]] = 1;
        *acertos1 += 1;
    }else {
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
	int ver = 0;
    int op, op2, op3;
   	
    
    int tabuleiroSozinho[5][5];
	int tabuleiro[5][5], tabuleiro2[5][5];
    int shot1[5][5], shot2[5][5];
    int player = 1;
    int tiro[2], tiro2[2];
    int navios[3][2], navios2[3][2];
    int score = 100, score2 = 100, acertos1 = 0, acertos2 = 0, tentativas = 0;
    
    
    
    //variaveis do jogo personalisado 
    int tabuleiroPersonalizado[15][15];
    int tabuleiroPersonalizado2[15][15];
    int shotPersonalizado[15][15];
    int shotPersonalizado2[15][15];
    int naviosPersonalizado[3][2];
    int naviosPersonalizado2[3][2];
    int tiroPersonalizado[2];
    int tentativasPersonalizado = 0, acertosPersonalizado = 0;
    int qL, qC, lol = 1; //qL: Tamanho da linha | qC: Tamanho da coluna
    
	// Tela de boas-vindas
	printf("\n\n\n\t\t\tEm parcerias a " RED "Riot Games" RESET ":\n");
	sleep(2);
    printf("\t\t\t" RED "Grupo Caderno" RESET " apresenta...\n");
    sleep(2);
    system("cls");
    
    printf("\n\n\n\t\t\t JOGO ");
    sleep(2);
    printf("DO");
    sleep(1);
    printf(YEL " CADERNO" RESET);
    sleep(2);

    // Escolha de jogo
    while(ver != 1){		
	    system("cls");
	    printf("\n\n\n\t\t\t JOGO DO "YEL "CADERNO" RESET);
	    printf("\n\n1 - Batalha Naval \n2 - " RED "SAIR\n" RESET);
	    scanf("%d", &op);
		if(op != 1 && op != 2){
			printf("Numero Invalido");
			sleep(2);
			continue;
		}
		ver = 1; 
	}
			
    // Switch case para a escolha de jogo
    switch (op) {
    	case 1:
    		while (menu) {
    			system("cls");
    			printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL" RESET);
    			sleep(1);
    			printf("\n " GRN "Single Player " RESET "- 1\n Multiplayer - 2\n " YEL "Personalisado" RESET " - 3\n " RED "Sair " RESET "- 0\n");
    			scanf("%d", &op2);
    			switch (op2) {
    				case 1:
    					inicializaTabuleiro(tabuleiroSozinho);
    					inicializaShot(shot1);
    					iniciaNaviosSozinho(navios);
    					while (acertos1 != 3){
    						system("cls");
    						mostraTabuleiroSozinho(tabuleiroSozinho);
    						darTiroSozinho(tiro, shot1, tabuleiroSozinho, navios, &tentativas);
    						alteraTabuleiroSozinho(tiro, navios, tabuleiroSozinho, &acertos1, &tentativas);
    						tentativas++;
    						sleep(2);
    					}
    					system("cls");
    					printf(YEL "Vitoria\n\n" RESET);
    					mostraTabuleiroSozinho(tabuleiroSozinho);
    					tentativas -= 3;
    					printf("\nVoce acertou os 3 navios em" GRN " %d " RESET "tentativas\n", tentativas);
    					system("pause");
    					tentativas = 0;
    					acertos1 = 0;
    					continue;
    				case 2:
    					acertos1 = 0;
    					acertos2 = 0;
    					system("cls");
    					printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
    					inicializaTabuleiro(tabuleiro);
    					inicializaShot(shot1);
    					iniciaNavios(navios, player);
    					system("cls");
    					printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
    					player = (player == 1) ? 2 : 1;	
    					inicializaTabuleiro(tabuleiro2);
    					inicializaShot(shot2);
    					iniciaNavios(navios2, player);
    					player = (player == 1) ? 2 : 1;
    					do {
    						system("cls");
    						printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
    						mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
    						darTiro(tiro, player, tabuleiro, tabuleiro2, score, score2, shot1, shot2);
    						alteraTabuleiro(tiro, navios, navios2, tabuleiro, tabuleiro2, player, &score, &score2, &acertos1, &acertos2);
    						sleep(2);
    						player = (player == 1) ? 2 : 1;
    						if (acertos1 == 3) {
    							system("cls");
    							mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
    							printf("\n\nPlayer 1 venceu!\n");
    							printf("Score: "YEL"%d"RESET"\n", score);
    							system("pause");
    							system("cls");
    							break;
    						} else if (acertos2 == 3) {
    							system("cls");
    							mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
    							printf("\n\nPlayer 2 venceu!\n");
    							printf("Score: "YEL"%d"RESET"\n", score2);
    							system("pause");
    							system("cls");
    							break;
    						}
    						system("cls");
    					}while(1);
    					continue;
    				case 3:
    					system("cls");
    					printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL" RESET);
    					sleep(1);
    					printf("\n1 - " GRN "Single Player" RESET "\n2 - " YEL "Multiplayer " RESET "\n3 - " RED "Sair\n" RESET);
    					scanf("%d", &op3);
    					switch(op3) {
    						case 1:
    							lol = 1;
    							qL = 0;
							    qC = 0;
    							while(lol == 1){		
    								system("cls");
    								printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
									printf("Tamanho do tabuleiro (2 - 15)\n");
								    printf("Linhas: ");
								    scanf("%d", &qL);
								    if (qL < 2 || qL > 15) {
							            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
							            sleep(2);
							            system("cls");
							            continue;
							        }
								    printf("Colunas: ");
								    scanf("%d", &qC);
								    if (qC < 2 || qC > 15 ) {
							        	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
							            sleep(2);
							            system("cls");
							            continue;
							        }
							        lol = 0;
								}
								inicializaTabuleiroPersonalizado(tabuleiroPersonalizado, qL, qC);
							    inicializaShotPersonalizado(shotPersonalizado, qL, qC);
							    iniciaNaviosPersonalizado(naviosPersonalizado, qL, qC);	
							    while (acertosPersonalizado != 3) {
							        system("cls");
							        mostraTabuleiroPersonalizado(tabuleiroPersonalizado, qL, qC);
							        darTiroPersonalizado(tiroPersonalizado, shotPersonalizado, tabuleiroPersonalizado, naviosPersonalizado, qL, qC);
							        alteraTabuleiroPersonalizado(tiroPersonalizado, naviosPersonalizado, tabuleiroPersonalizado, &acertosPersonalizado);
							        tentativasPersonalizado++;
							        sleep(2);
							    }
							
							    system("cls");
							    mostraTabuleiroPersonalizado(tabuleiroPersonalizado, qL, qC);
							    printf(YEL "Vitoria" RESET);
							    tentativasPersonalizado -= 3;
							    printf("\nVoce acertou os 3 navios em" GRN " %d " RESET "tentativas\n\n", tentativasPersonalizado);
							    system("pause");
							    tentativasPersonalizado = 0;
							    acertosPersonalizado = 0;
							    continue;
							case 2:
								lol = 1;
								qL = 0;
							    qC = 0;
								while(lol == 1){		
    								system("cls");
    								printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
									printf("Tamanho do tabuleiro (2 - 10)\n");
								    printf("Linhas: ");
								    scanf("%d", &qL);
								    if (qL < 2 || qL > 10) {
							            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
							            sleep(2);
							            system("cls");
							            continue;
							        }
								    printf("Colunas: ");
								    scanf("%d", &qC);
								    if (qC < 2 || qC > 10 ) {
							        	printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n" );
							            sleep(2);
							            system("cls");
							            continue;
							        }
							        lol = 0;
								}
								system("cls");
								iniciarTabuleiroPersonalizadoMult(tabuleiroPersonalizado, qL, qC);
							    iniciarShotPersonalizado(shotPersonalizado, qL, qC);
							    iniciaNaviosPersonalizadoMult(naviosPersonalizado, player, qL, qC);
							    player = (player == 1) ? 2 : 1;
							    system("cls");
							    iniciarTabuleiroPersonalizadoMult(tabuleiroPersonalizado2, qL, qC);
							    iniciarShotPersonalizado(shotPersonalizado2, qL, qC);
							    iniciaNaviosPersonalizadoMult(naviosPersonalizado2, player, qL, qC);
							    player = (player == 1) ? 2 : 1;
							    system("cls");
							    do {
							        mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
							        darTiroPersonalizadoMult(tiroPersonalizado, tabuleiroPersonalizado, tabuleiroPersonalizado2, score, score2, shotPersonalizado, shotPersonalizado2, qL, qC, player);
									alteraTabuleiroPersonalizadoMult(tiroPersonalizado, naviosPersonalizado, naviosPersonalizado2, tabuleiroPersonalizado, tabuleiroPersonalizado2, player, &score, &score2, &acertos1, &acertos2);
									player = (player == 1) ? 2 : 1;
									if(acertos1 == 3){
										system("cls");
										mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
										printf("Player 1 Venceu!\n");
										sleep(2);
										system("cls");
										break;
									} else if(acertos2 == 3){
										system("cls");
										mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
										printf("Player 2 Venceu!\n");
										sleep(2);
										system("cls");
										break;
									}
									system("cls");
							    } while (1);
							    continue;   
							}			
						} 
					case 2:
						printf("Obrigado, volte sempre!");
						return 0;	   						
    				}
    			}

		}
    
    
