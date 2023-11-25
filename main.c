#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

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
    printf("\n\t\t\tBATALHA "YEL "NAVAL\n\n" RESET);
    printf("          ");
    for (linha = 0; linha < qC; linha++) {
        if (linha <= 8) {
            printf("%d       ", linha + 1);
        } else {
            printf("%d     ", linha + 1);
        }
    }
    printf("||Player 1\n");

    for (linha = 0; linha < qL; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < qC; coluna++) {
            if (tabuleiroPersonalizado2[linha][coluna] == -1) {
            	printf("\t|");
                printf(BLU " ~ " RESET);
                printf("|");
            } else if (tabuleiroPersonalizado2[linha][coluna] == 0) {
                printf(RED "\t| * |" RESET);
            } else if (tabuleiroPersonalizado2[linha][coluna] == 1) {
                printf(GRN "\t| X |" RESET);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (linha = 0; linha < qL; linha++) {
        printf("%d", linha + 1);
        for (coluna = 0; coluna < qC; coluna++) {
            if (tabuleiroPersonalizado[linha][coluna] == -1) {
                printf("\t|");
                printf(BLU " ~ " RESET);
                printf("|");
            } else if (tabuleiroPersonalizado[linha][coluna] == 0) {
                printf(RED "\t| * |" RESET);
            } else if (tabuleiroPersonalizado[linha][coluna] == 1) {
                printf(GRN "\t| X |" RESET);
            }
        }
        printf("\n");
    }
    printf("          ");
    for (linha = 0; linha < qC; linha++) {
        if (linha <= 8) {
            printf("%d       ", linha + 1);
        } else {
            printf("%d     ", linha + 1);
        }
    }
    printf("||Player 2\n");
}

void iniciaNaviosPersonalizadoMult(int navios[][2], int player, int qL, int qC) {
    int navio, linha, coluna, coordenadasRepetidas = 0, i;

    for (navio = 0; navio < 3; navio++) {
        printf("\n\n\n\t\t\t BATALHA " YEL "NAVAL\n\n" RESET);
        coordenadasRepetidas = 0;
        printf("|| Localiza��o dos navios %d do Player %d ||\n",navio+1 , player);
        printf("|| Linha (1 - %d): ", qL);

        char linhaInput[10];
        scanf("%s", linhaInput);

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(linhaInput[0])) {
            printf("Entrada invalida. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }

        linha = atoi(linhaInput);

        if (linha < 1 || linha > qL) {
            printf("Numero de linha invalido. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
        navios[navio][0] = linha - 1;

        printf("|| Coluna (1 - %d): ", qC);

        char colunaInput[10];
        scanf("%s", colunaInput);

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(colunaInput[0])) {
            printf("Entrada invalida. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }

        coluna = atoi(colunaInput);

        if (coluna < 1 || coluna > qC) {
            printf("Numero de coluna invalido. Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
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

void darTiroPersonalizadoMult(int tiroPersonalizado[2], int tabuleiroPersonalizado[][10], int tabuleiroPersonalizado2[][10], int score, int score2, int shotPersonalizado[][10], int shotPersonalizado2[][10], int qL, int qC, int player) {
    int foi = 0;

    while (foi == 0) {
    	mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
        printf("\n\nVez do Player %d", player);
        printf("\nLinha: ");

        char linhaInput[10];
        scanf("%s", linhaInput);

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(linhaInput[0])) {
            printf("Entrada invalida. Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[0] = atoi(linhaInput);

        if (tiroPersonalizado[0] < 1 || tiroPersonalizado[0] > qL) {
            printf("Numero invalido. Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[0]--;

        printf("Coluna: ");

        char colunaInput[10];
        scanf("%s", colunaInput);

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(colunaInput[0])) {
            printf("Entrada invalida. Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[1] = atoi(colunaInput);

        if (tiroPersonalizado[1] < 1 || tiroPersonalizado[1] > qC) {
            printf("Numero invalido. Tente novamente.\n");
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
        } else if (player == 2) {
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
    } else if (player == 2) {
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
  	printf("\n\t\t\tBATALHA "YEL "NAVAL\n\n" RESET);
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

        // Verifica se a posi��o ja foi ocupada por outro navio
        for (anterior = 0; anterior < navio; anterior++) {
            while ((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1])) {
                navios[navio][0] = rand() % qL;
                navios[navio][1] = rand() % qC;
                anterior = 0;  // Reinicia a verifica��o desde o inicio
            }
        }
    }
}

void darTiroPersonalizado(int tiroPersonalizado[2], int shotPersonalizado[][15], int tabuleiroPersonalizado[][15], int naviosPersonalizado[][2], int qL, int qC) {
    int foi = 0, i;
    while (foi == 0) {
        system("cls");
        mostraTabuleiroPersonalizado(tabuleiroPersonalizado, qL, qC);
        printf("Linha: ");
        char linhaInput[10];
        scanf("%s", linhaInput);

        // Verifica se o input � "777"
        if (strcmp(linhaInput, "777") == 0) {
            for (i = 0; i < 3; i++) {
                printf("Tiro (%d,%d)\n", naviosPersonalizado[i][0] + 1, naviosPersonalizado[i][1] + 1);
            }
            sleep(2);
            continue;
        }

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(linhaInput[0])) {
            printf("Entrada " RED "INVALIDA" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[0] = atoi(linhaInput);

        if (tiroPersonalizado[0] < 1 || tiroPersonalizado[0] > qL) {
            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[0]--;

        printf("Coluna: ");
        char colunaInput[10];
        scanf("%s", colunaInput);

        // Verifica se o input cont�m apenas d�gitos
        if (!isdigit(colunaInput[0])) {
            printf("Entrada " RED "INVALIDA" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[1] = atoi(colunaInput);

        if (tiroPersonalizado[1] < 1 || tiroPersonalizado[1] > qC) {
            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiroPersonalizado[1]--;

        if (shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] == 0) {
            // J� atirou aqui
            printf("Ja atirou aqui.\n");
            sleep(2);
            system("cls");
            continue;
        }

        foi = 1;
    }
    shotPersonalizado[tiroPersonalizado[0]][tiroPersonalizado[1]] = 0;
}

int acertouPersonalizado(int tiroPersonalizado[2], int naviosPersonalizado[][2]) {
    int navio;
    for (navio = 0; navio < 3; navio++) {
        if (tiroPersonalizado[0] == naviosPersonalizado[navio][0] && tiroPersonalizado[1] == naviosPersonalizado[navio][1]) {
            printf(GRN "ACERTOU" RESET " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
            return 1;
        }   
    }
    printf(RED "ERROU" RESET " o tiro (%d,%d)\n", tiroPersonalizado[0] + 1, tiroPersonalizado[1] + 1);
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

void mostraTabuleiroSozinho(int tabuleiroSozinho[][5]){
    int linha, coluna;
    	printf("\n\t\t BATALHA "YEL "NAVAL\n\n" RESET);

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
    printf("\n\t\t\tBATALHA "YEL "NAVAL\n\n" RESET);
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
        char linhaInput[10], colunaInput[10];
        system("cls");
		printf("\n\t\t\tBATALHA "YEL "NAVAL\n\n" RESET);
        printf("|| Localiza��o do navio %d do Player %d ||\n", navio+1, player);
        printf("|| Linha (1 - 5): ");
        scanf("%s", linhaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isLinhaDigit = 1;
        for (i = 0; linhaInput[i] != '\0'; i++) {
            if (!isdigit(linhaInput[i])) {
                isLinhaDigit = 0;
                break;
            }
        }

        if (!isLinhaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }

        linha = atoi(linhaInput);

        if (linha < 1 || linha > 5) {
            printf("N�mero de linha " RED "inv�lido" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }
        navios[navio][0] = linha - 1;

        printf("|| Coluna (1 - 5): ");
        scanf("%s", colunaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isColunaDigit = 1;
        for (i = 0; colunaInput[i] != '\0'; i++) {
            if (!isdigit(colunaInput[i])) {
                isColunaDigit = 0;
                break;
            }
        }

        if (!isColunaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            system("cls");
            navio--;
            continue;
        }

        coluna = atoi(colunaInput);

        if (coluna < 1 || coluna > 5) {
            printf("N�mero de coluna " RED "inv�lido" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            navio--;
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

void darTiroSozinho(int tiro[2], int shot1[][5], int tabuleiroSozinho, int navios[][2], int *tentativas) {
    int foi = 0, i;

    while (foi == 0) {
        char linhaInput[10], colunaInput[10];
		system("cls");
		mostraTabuleiroSozinho(tabuleiroSozinho);
        printf("Linha: ");
        scanf("%s", linhaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isLinhaDigit = 1;
        for (i = 0; linhaInput[i] != '\0'; i++) {
            if (!isdigit(linhaInput[i])) {
                isLinhaDigit = 0;
                break;
            }
        }

        if (!isLinhaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiro[0] = atoi(linhaInput);

        if (tiro[0] == 777) {
            for (i = 0; i < 3; i++) {
                printf("Tiro (%d,%d)\n", navios[i][0] + 1, navios[i][1] + 1);
            }
            sleep(2);
            continue;
        }
		else if (tiro[0] < 1 || tiro[0] > 5) {
            printf("N�mero " RED "INV�LIDO" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }
        tiro[0]--;

        printf("Coluna: ");
        scanf("%s", colunaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isColunaDigit = 1;
        for (i = 0; colunaInput[i] != '\0'; i++) {
            if (!isdigit(colunaInput[i])) {
                isColunaDigit = 0;
                break;
            }
        }

        if (!isColunaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            system("cls");
            continue;
        }

        tiro[1] = atoi(colunaInput);

        if (tiro[1] < 1 || tiro[1] > 5) {
            printf("N�mero " RED "INV�LIDO" RESET ". Tente novamente.\n");
            sleep(2);
            system("cls");
            continue;
        }
        tiro[1]--;

        if (shot1[tiro[0]][tiro[1]] == 0) {
            // j� atirou aqui
            printf("J� atirou aqui.\n");
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

    while (foi == 0) {
        system("cls");
        mostraTabuleiro(tabuleiro, tabuleiro2, score, score2);
        printf("\n\nVez do Player %d\n", player);
        
        char linhaInput[10], colunaInput[10];

        printf("Linha: ");
        scanf("%s", linhaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isLinhaDigit = 1;
        for (i = 0; linhaInput[i] != '\0'; i++) {
            if (!isdigit(linhaInput[i])) {
                isLinhaDigit = 0;
                break;
            }
        }

        if (!isLinhaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            continue;
        }

        tiro[0] = atoi(linhaInput);

        if (tiro[0] < 1 || tiro[0] > 5) {
            printf("N�mero " RED "inv�lido" RESET ". Tente novamente.\n");
            sleep(2);
            continue;
        }
        tiro[0]--;

        printf("Coluna: ");
        scanf("%s", colunaInput);

        // Verifica se a entrada cont�m apenas d�gitos
        int isColunaDigit = 1;
        for (i = 0; colunaInput[i] != '\0'; i++) {
            if (!isdigit(colunaInput[i])) {
                isColunaDigit = 0;
                break;
            }
        }

        if (!isColunaDigit) {
            printf("Entrada inv�lida. Por favor, insira um n�mero v�lido.\n");
            sleep(2);
            continue;
        }

        tiro[1] = atoi(colunaInput);

        if (tiro[1] < 1 || tiro[1] > 5) {
            printf("N�mero " RED "inv�lido" RESET ". Tente novamente.\n");
            sleep(2);
            continue;
        }
        tiro[1]--;

        if (player == 1) {
            if (shot1[tiro[0]][tiro[1]] == 0) {
                // j� atirou aqui
                printf("J� atirou aqui.\n");
                sleep(2);
                continue;
            }
        } else {
            if (shot2[tiro[0]][tiro[1]] == 0) {
                // j� atirou aqui
                printf("J� atirou aqui.\n");
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
				*score2 -= 20;
			}
            
        } else if (player == 1) {
            tabuleiro[tiro[0]][tiro[1]] = 0;
            if (*score == 0){
            	*score = *score;
			}else{
				*score -= 20;
			}
        }
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
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
    
    
    
    printf("\n\t\t\tEm parcerias a " RED "Riot Games" RESET "\n");
    sleep(1);
    printf("\t\t\t" RED "GRUPO CADERNO" RESET " apresente...");
    sleep(2);
    system("cls");
    printf("\n\t\t\tJOGO");
    sleep(1);
    printf(" DO ");
    sleep(1);
    printf(YEL "CADERNO" RESET);
    sleep(1);
    system("cls");
    int loop = 1;
    char op1 = ' ', op2 = ' ', op3 = ' ', op4 = ' ', op5 = ' ';
    
	while (loop == 1) {
		voltar:
		system("cls");
		op1 = ' ';
		printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
		printf("\n\n  1 - BATALHA NAVAL\n  2 - CR�DITOS\n  3 - REGRAS\n  0 - " RED "SAIR" RESET "\n  ");
		scanf(" %c", &op1);
		if (op1 == '1' || op1 == '2' || op1 == '3' || op1 == '0') {
			switch (op1) {
				case '1': //MENU DO JOGO
					voltar3:
					while (loop == 1) {
						system("cls");
						op2 = ' ';
						printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
						printf("\n\n  1 - UM JOGADOR\n  2 - DOIS JOGADORES\n  3 - MODO PERSONALIZADO\n  0 - "RED"VOLTAR"RESET"\n  ");
						scanf(" %c", &op2);
	
						if (op2 != '1' && op2 != '2' && op2 != '3' && op2 != '0') {
							system("cls");
							printf(RED "N�mero Inv�lido" RESET);
							sleep(1);
							system("cls");
							continue;
						}
						switch (op2) {
							case '1': //MODO UM JOGADOR
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
								mostraTabuleiroSozinho(tabuleiroSozinho);
								tentativas -= 3;
								printf(YEL "\tPARABENS!!! Vitoria" RESET);
								printf("\nVoce acertou os 3 navios em" GRN " %d " RESET "tentativas\n", tentativas);
								system("pause");
								tentativas = 0;
								acertos1 = 0;
								break;
							case '2': //MODO DOIS JOGADORES
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
		    					score = 100;
		    					score2 = 100;
		    					acertos1 = 0;
		    					acertos2 = 0;
		    					player = 1;
		    					break;
							case '3':  //MENU DO PERSONALIZADO
								while (loop == 1) {
									system("cls");
									op2 = ' ';
									printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
									printf("\n\n  1 - UM JOGADOR\n  2 - DOIS JOGADORES\n  0 - "RED"VOLTAR"RESET"\n  ");
									scanf(" %c", &op4);
									switch(op4){
										case '1':  //PERSONALIZADO UM JOGADOR
											lol = 1;
			    							qL = 0;
										    qC = 0;
										    
			    							do {		
			    								system("cls");
			    								printf("\n\n\n\t\t\t BATALHA "YEL "NAVAL\n\n" RESET);
												printf("Tamanho do tabuleiro (2 - 15)\n");
										        printf("Linhas: ");
										        if (scanf("%d", &qL) != 1 || qL < 2 || qL > 15) {
										            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
										            while (getchar() != '\n');  
										            sleep(2);
										            system("cls");  
										        } else {
										            break;  
										        }
										    } while (1);
										
										    do {
										        printf("Colunas: ");
										        if (scanf("%d", &qC) != 1 || qC < 2 || qC > 15) {
										            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
										            while (getchar() != '\n');  
										            sleep(2);
										            system("cls");  
										        } else {
										            break;  
										        }
											}while(1);
											
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
										    break;
										case '2':
											player = 1;
											acertos1 = 0;
											acertos2 = 0;
											lol = 1;
											qL = 0;
										    qC = 0;
										    while (lol == 1) {
										        system("cls");
										        printf("\n\n\n\t\t\t BATALHA " YEL "NAVAL\n\n" RESET);
										        printf("Tamanho do tabuleiro (2 - 10)\n");
										        printf("Linhas: ");
										
										        char linhaInput[10];
										        scanf("%s", linhaInput);
										
										        // Verifica se o input cont�m apenas d�gitos
										        if (!isdigit(linhaInput[0])) {
										            printf("Entrada " RED "INVALIDA" RESET ". Tente novamente.\n");
										            sleep(2);
										            continue;
										        }
										
										        qL = atoi(linhaInput);
										
										        if (qL < 2 || qL > 10) {
										            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
										            sleep(2);
										            continue;
										        }
										
										        printf("Colunas: ");
										
										        char colunaInput[10];
										        scanf("%s", colunaInput);
										
										        // Verifica se o input cont�m apenas d�gitos
										        if (!isdigit(colunaInput[0])) {
										            printf("Entrada " RED "INVALIDA" RESET ". Tente novamente.\n");
										            sleep(2);
										            continue;
										        }
										
										        qC = atoi(colunaInput);
										
										        if (qC < 2 || qC > 10) {
										            printf("Numero " RED "INVALIDO" RESET ". Tente novamente.\n");
										            sleep(2);
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
										        darTiroPersonalizadoMult(tiroPersonalizado, tabuleiroPersonalizado, tabuleiroPersonalizado2, score, score2, shotPersonalizado, shotPersonalizado2, qL, qC, player);
												alteraTabuleiroPersonalizadoMult(tiroPersonalizado, naviosPersonalizado, naviosPersonalizado2, tabuleiroPersonalizado, tabuleiroPersonalizado2, player, &score, &score2, &acertos1, &acertos2);
												player = (player == 1) ? 2 : 1;
												if(acertos1 == 3){
													system("cls");
													mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
													printf("\nPlayer 1 Venceu!\n");
													sleep(2);
													system("cls");
													break;
												} else if(acertos2 == 3){
													system("cls");
													mostraTabuleiroPersonalizadoMult(tabuleiroPersonalizado, tabuleiroPersonalizado2, qL, qC);
													printf("\nPlayer 2 Venceu!\n");
													sleep(2);
													system("cls");
													break;
												}
												system("cls");
										    } while (1);	
										case '0':
											op4 = ' ';
											goto voltar3;
									}
								}
							case '0':
								op2 = ' ';
								goto voltar;
						}
					}
				case '2':  //CREDITOS 
					voltar2:
					system("cls");
					printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
					printf("\n\t\t\t" YEL "CR�DITOS" RESET);
					sleep(2);	
					printf("\n\nDesenvolvimento:\n\n");
					sleep(1);
					printf("   [Jorge Luis] - Desenvolvedor\n");
					sleep(1);
					printf("   [Vitor Ferreira] - Desenvolvedor\n");
					sleep(1);
					printf("   [�ris Lins] - Desenvolvedor\n");
					sleep(1);
					printf("   [Rafael Queiroz] - Desenvolvedor de Testes\n\n");
					sleep(2);
					printf("Documenta��o:\n\n");
					sleep(1);
					printf("   [�ris Lins] - Especialista em Documenta��o\n");
					sleep(1);
					printf("   Sim, a que mais escreve errado kk");
					sleep(2);
					system("cls");
					printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
					printf("\n\t\t\t" YEL "CR�DITOS" RESET);	
					printf("\n\nDesenvolvimento:\n\n");
					printf("   [Jorge Luis] - Desenvolvedor\n");
					printf("   [Vitor Ferreira] - Desenvolvedor\n");
					printf("   [�ris Lins] - Desenvolvedor\n");
					printf("   [Rafael Queiroz] - Desenvolvedor de Testes\n\n");
					printf("Documenta��o:\n\n");
					printf("   [�ris Lins] - Especialista em Documenta��o\n\n");
					sleep(2);
					printf("Equipe de Projeto:\n\n");
					sleep(1);
					printf("   [Jorge Luis] - Project Manager\n");
					sleep(1);
					printf("   [Vitor Ferreira] - L�der T�cnico\n");
					sleep(1);
					printf("   [�ris Lins] - Especialista em Documenta��o\n\n");
					sleep(2);
					printf("Agradecimentos Especiais:\n\n");
					sleep(1);
					printf("   [Leonardo Souto] - Mestre Supremo de League of Legends\n\n\n");
					
					sleep(1);
					printf("0 - VOLTAR\n");
					scanf(" %c", &op3);
					if (op3 != '0') {
						printf(RED "N�mero Inv�lido" RESET);
						sleep(1);
						system("cls");
						op3 = ' ';
						goto voltar2;
					}
					goto voltar;
					
				case '3': //REGRAS
					voltarMenuRegras:
					system("cls");
					printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
					printf("\n\t\t\t"YEL "REGRAS" RESET);
					printf("\n\n  1 - MODO SOLIT�RIO\n  2 - DOIS JOGADORES\n  3 - MODO PERSONALIZADO\n  0 - "RED"VOLTAR"RESET"\n  ");
					scanf(" %c", &op5);
						switch(op5){
							case '1':
								voltarRegras1:
								system("cls");
								printf("\n\t\t\tJOGO DO "YEL "CADERNO" RESET);
								printf("\n\t\t\t"YEL "REGRAS\n\n" RESET);
								printf("Batalha Naval - Modo Solit�rio:\n\n");
								printf("  Objetivo:\n");
								printf("Encontrar e afundar os 3 navios no menor n�mero poss�vel de tentativas.\n\n");
								printf("  Tabuleiro:\n");
								printf("O tabuleiro � uma grade 5x5, numerado de 1 a 5 em ambas as linhas e colunas.\n\n");
								printf("  Navios:\n");
								printf("H� 3 navios no tabuleiro, cada um ocupando uma �nica c�lula.\n\n");
								printf("  Pontua��o:\n");
								printf("Cada acerto ganha 100 pontos.\n");
								printf("Cada erro resulta em uma penalidade de 20 pontos.\n");
								printf("O jogo continua at� que todos os 3 navios sejam encontrados.\n\n");
								printf("  Jogabilidade:\n");	
								printf("O jogador escolhe uma posi��o no formato linha e coluna (por exemplo, 3 4).\n");
								printf("O jogo verifica se h� um navio nessa posi��o.\n");
								printf("Se acertar, o jogador ganha 100 pontos e � informado sobre o acerto.\n");
								printf("Se errar, o jogador perde 20 pontos e � informado sobre o erro.\n");
								printf("O jogador continua a escolher posi��es at� encontrar todos os 3 navios.\n");
								printf("O jogo termina quando todos os navios forem encontrados.\n\n");
								printf("  Regras Adicionais:\n");
								printf("A posi��o escolhida deve ser um n�mero de 1 a 5 em ambas as coordenadas.\n\n");
								printf("0 - VOLTAR\n");
								scanf(" %c", &op5);
								if (op5 != '0') {
									printf(RED "N�mero Inv�lido" RESET);
									sleep(1);
									system("cls");
									op3 = ' ';
									goto voltarRegras1;
								}
								goto voltarMenuRegras;
							case '2':
								voltarRegras3:
								system("cls");
								printf("Batalha Naval - Modo Dois Jogadores:\n\n");
								printf("  Objetivo:\n");
								printf("Cada jogador tenta afundar os navios do oponente antes de ter seus pr�prios navios afundados.\n\n");
								printf("  Prepara��o:\n");
								printf("Cada jogador escolhe as posi��es para seus 3 navios no tabuleiro 5x5, sem que o oponente saiba.\n\n");
								printf("  Tabuleiro:\n");
								printf("O tabuleiro � uma grade 5x5, numerado de 1 a 5 em ambas as linhas e colunas.\n\n");
								printf("  Navios:\n");
								printf("Cada jogador possui 3 navios. A posi��o de cada navio � escolhida pelo jogador no in�cio do jogo.\n\n");
								printf("  Pontua��o:\n");
								printf("Cada acerto ganha 100 pontos.\n");
								printf("Cada erro resulta em uma penalidade de 20 pontos.\n");
								printf("O jogo continua at� que todos os navios de um jogador sejam afundados.\n\n");
								printf("  Jogabilidade:\n");
								printf("Os jogadores alternam entre escolher uma c�lula no formato linha e coluna (por exemplo, 3 4) para atacar o oponente.\n");
								printf("O jogo verifica se h� um navio na c�lula escolhida do oponente.\n");
								printf("Se acertar, o jogador ganha 100 pontos e � informado sobre o acerto.\n");
								printf("Se errar, o jogador perde 20 pontos e � informado sobre o erro.\n");
								printf("Os jogadores continuam alternando entre escolher c�lulas at� que todos os navios de um jogador sejam afundados.\n");
								printf("O jogo termina quando todos os navios de um jogador forem afundados.\n\n");
								printf("  Regras Adicionais:\n");
								printf("A c�lula escolhida deve ser um n�mero de 1 a 5 em ambas as coordenadas.\n\n");
								printf("  Exemplo de Feedback:\n");
								printf("Acertou! +100 pontos.\n");
								printf("Errou! -20 pontos. Tente novamente.\n\n");
								printf("0 - VOLTAR\n");
								scanf(" %c", &op5);
								if (op5 != '0') {
									printf(RED "N�mero Inv�lido" RESET);
									sleep(1);
									system("cls");
									op3 = ' ';
									goto voltarRegras2;
								}
								goto voltarMenuRegras;
							case '3':
								voltarRegras2:
								system("cls");
								printf("Batalha Naval - Modo Personalizado:\n\n");
								printf("  Objetivo:\n");
								printf("Os jogadores (ou jogador solit�rio) tentam afundar os navios do oponente (ou do pr�prio no modo solit�rio) antes de ter seus pr�prios navios afundados.\n\n");
								printf("  Configura��o:\n");
								printf("Escolha o modo de jogo:\n");
								printf("Solit�rio: O jogador define o tamanho do tabuleiro (de 2 a 15) e\n as posi��es dos 3 navios s�o autom�tica.\n");
								printf("Dois Jogadores: Cada jogador define o tamanho do tabuleiro (de 2 a 10) \ne escolhe as posi��es para seus 3 navios.\n\n");
								printf("  Tabuleiro:\n");
								printf("O tabuleiro � uma grade de tamanho definido pelo jogador, numerado de 1 at� o tamanho do tabuleiro em ambas as linhas e colunas.\n\n");
								printf("  Navios:\n");
								printf("Cada jogador possui 3 navios. As posi��es de cada navio s�o escolhidas pelo(s) jogador(es) no in�cio do jogo,\nou configuradas automaticamente no modo solit�rio.\n\n");
								printf("  Jogabilidade:\n");
								printf("Os jogadores (ou jogador solit�rio) alternam entre escolher uma c�lula no formato linha e coluna (por exemplo, 3 4) para atacar o oponente.\n");
								printf("O jogo verifica se h� um navio na c�lula escolhida do oponente (ou do pr�prio no modo solit�rio).\n");
								printf("Se acertar, o jogador � informado sobre o acerto.\n");
								printf("Se errar, o jogador � informado sobre o erro.\n");
								printf("Os jogadores continuam alternando entre escolher c�lulas at� que todos os navios de um jogador sejam afundados.\n");
								printf("O jogo termina quando todos os navios de um jogador forem afundados.\n\n");
								printf("  Regras Adicionais:\n");
								printf("A c�lula escolhida deve ser um n�mero de 1 at� o tamanho do tabuleiro em ambas as coordenadas.\n");
								printf("N�o h� sistema de pontua��o; o objetivo � simplesmente afundar todos os navios.\n");
								printf("Se um jogador atingir o objetivo antes do outro, ou se o jogador solit�rio afundar os navios, o jogo termina.\n\n");
								printf("0 - VOLTAR\n");
								scanf(" %c", &op5);
								if (op5 != '0') {
									printf(RED "N�mero Inv�lido" RESET);
									sleep(1);
									system("cls");
									op3 = ' ';
									goto voltarRegras3;
								}
								goto voltarMenuRegras;
							case '0':
								goto voltar;		
						}
				case '0':  //SAIR DO JOGO
					op1 = ' ';
					return 0;
				default:
					continue;
				}
		} else {
			printf(RED "\nN�mero Inv�lido" RESET);
			sleep(1);
			system("cls");
			continue;
		}
	}
}

