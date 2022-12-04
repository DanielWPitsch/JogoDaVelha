#ifndef FUNCOES
#define FUNCOES

void inserirRank(int contadorEmpate, int contadorVitoriaJ1, int contadorVitoriaJ2, char jogador1[100], char jogador2[100], int qtdPartidas){
	FILE *arq;
	arq = fopen("rank.txt", "a");
	
	if(arq == NULL){
		printf("Erro na abertura do arquivo!");
	}else{		
		fprintf(arq, "\n\nPartidas jogadas: %d", qtdPartidas);
		fprintf(arq, "\nEmpate: %d", contadorEmpate);
		fprintf(arq, "\n%s: %d", jogador1, contadorVitoriaJ1);
		fprintf(arq, "\n%s: %d", jogador2, contadorVitoriaJ2);
		fprintf(arq, "\n=====================");
				
		fclose(arq);
	}
}

void lerArquivo(char arquivo[]){
	FILE *arq;
	char ler[500];
	arq = fopen(arquivo, "r");
	if(arq != NULL){	
		while(fgets(ler, 500, arq) != NULL){
			printf("%s",ler );
	}
	fclose(arq);
	}else{
		printf("Erro ao Abrir arquivo");
	}
	
}

void tabuleiro(char posicao[3][3]){
	system("cls");
	printf("\n\t%c | %c | %c \n", posicao[0][0], posicao[0][1], posicao[0][2]);
	printf("\t---------\n");
	printf("\t%c | %c | %c \n", posicao[1][0], posicao[1][1], posicao[1][2]);
	printf("\t---------\n");
	printf("\t%c | %c | %c \n", posicao[2][0], posicao[2][1], posicao[2][2]);
}

int ganhou(char caractere){
	int vitoria;
	if(caractere == 'X'){
		vitoria = 11;
	}else{
		vitoria = 12;
	}
	return vitoria;
}

int testaVitoria(int cont_jogadas, char casas[3][3]){
	int i;
	char caracteres [2] = {'X', 'O'};
	
	for (i=0; i<2; i++){
		if(casas[0][0] == caracteres[i] && casas[0][1] == caracteres[i] && casas[0][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);	
		}
		if(casas[1][0] == caracteres[i] && casas[1][1] == caracteres[i] && casas[1][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[2][0] == caracteres[i] && casas[2][1] == caracteres[i] && casas[2][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[0][0] == caracteres[i] && casas[1][0] == caracteres[i] && casas[2][0] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[0][1] == caracteres[i] && casas[1][1] == caracteres[i] && casas[2][1] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[0][2] == caracteres[i] && casas[1][2] == caracteres[i] && casas[2][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[2][0] == caracteres[i] && casas[1][1] == caracteres[i] && casas[0][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
		if(casas[0][0] == caracteres[i] && casas[1][1] == caracteres[i] && casas[2][2] == caracteres[i]){
			cont_jogadas = ganhou(caracteres[i]);
		}
	}
	return cont_jogadas;
}

void limpaMatriz(char matriz[3][3]){
	int i, j;
	
	//limpando matriz
	for(i=0; i <= 2; i++){
			for(j=0; j <= 2; j++){
				matriz[i][j] = ' ';
			}
	}
}

struct partida{
	char jogador1[100];
	char jogador2[100];
	int contadorVitoriaJ1;
	int contadorVitoriaJ2;
	int contadorEmpate;
	int qtdPartidas;
};
void jogar(){
	
	char casas[3][3]; char resposta;
	int cont_jogadas = 0; int linha = 0; int coluna = 0; int jog_vez = 0; 
	
	struct partida s_partida;
	
	s_partida.contadorVitoriaJ1 = 0;
	s_partida.contadorVitoriaJ2 = 0;
	s_partida.contadorEmpate = 0;
	s_partida.qtdPartidas  = 0;	
	
	printf("Digite o nome do primeiro jogador: ");
	fgets(s_partida.jogador1, 100, stdin);
	//retirando a quebra de linha da string
	s_partida.jogador1[strlen(s_partida.jogador1)-1] = '\0';
	
	printf("Digite o nome do segundo jogador: ");
	fgets(s_partida.jogador2, 100, stdin);
	s_partida.jogador2[strlen(s_partida.jogador2)-1] = '\0';
	do{
		limpaMatriz(casas);
		
		cont_jogadas = 1;
		do{
			//desenha o tabuleiro
			tabuleiro(casas);
			//jog_vez comeca 0 e vai alternando para entrar na vez do jogador X ou O
			if(jog_vez %2 == 0){
				printf("\nJogador X, %s", s_partida.jogador1);
			}
			else{
				printf("\nJogador O, %s", s_partida.jogador2);	
			}
			//pega linha e coluna da matriz para inserir o X ou O
			printf("\nDigite para a linha: ");
			scanf("%d", &linha);
			printf("Digite para a coluna: ");
			scanf("%d", &coluna);
			//trata os erro de posicao
			if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3){
				printf("\nA posicao desejada eh invalida! Digite novamente...\n");
				system("pause");
			//trata os erro de posicao repetida
			}else if(casas[linha - 1][coluna - 1] != ' '){
				printf("\nA posicao solicitada jah estah ocupada! Digite novamente...\n");
				system("pause");
			//colocarah X ou O na linha e coluna dada, e conta jogada e vez
			}else{
				if(jog_vez %2 == 0){
					casas[linha - 1][coluna - 1] = 'X';	
				}
				else{
					casas[linha - 1][coluna - 1] = 'O';
				}
				jog_vez++;
				cont_jogadas++;
			}
			cont_jogadas = testaVitoria(cont_jogadas, casas);
		}while(cont_jogadas <= 9);
		
		tabuleiro(casas);
		if(cont_jogadas == 10){
			s_partida.contadorEmpate = s_partida.contadorEmpate + 1;
			printf("\nJogo EMPATADO!!");
		}
		else if(cont_jogadas == 11){
			s_partida.contadorVitoriaJ1++;
			printf("\nO VENCEDOR foi %s", s_partida.jogador1);
		}
		else{
			s_partida.contadorVitoriaJ2++;
			printf("\nO VENCEDOR foi %s", s_partida.jogador2);
		}
		
		s_partida.qtdPartidas = s_partida.qtdPartidas + 1;
		
		printf("\n\nDeseja jogar novamente ?(S-N)");
		scanf("%s", &resposta);
	}while(resposta == 'S');
	inserirRank(s_partida.contadorEmpate, s_partida.contadorVitoriaJ1, s_partida.contadorVitoriaJ2, s_partida.jogador1, s_partida.jogador2, s_partida.qtdPartidas);
	system("cls");
}

#endif
