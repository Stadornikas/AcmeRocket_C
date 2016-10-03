/*
 * main.c
 *
 *  Created on: 02/10/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "libs/equipes.h"
#include "libs/pilhaPodio.h"


int main() {
	
    pilhaPodio pilha;
    podio podio;
    INIT(&pilha);
    int qtdEquipes = 0, maxTentativas = 2, numEquipes = 0, colocacao = 1, campeao;
    float menorDistancia = 9999999.9;
    char situacao;
    int x;
    char teste[] = "sair";
    char teste2[20];
    
    do{
    	printf("Digite algo \n");
    	fflush(stdin);
    	gets(teste2);
    	
	}while (strcmp(teste, teste2) != 0);
	
	printf("\n====================================================================");
	printf("\n=============== BEM VINDO AO SISTEMA ACME ROCKET ===================");
	printf("\n=============== VERSAO: 1.0 ========================================");
	printf("\n====================================================================");
	printf("\n");
	printf("\n");
	printf
	//printf("\nDigite a quantidade de equipes que deseja cadastrar na competição: ");
	printf("\nDigite a quantidade de equipes que deseja cadastrar na competicao: ");
	fflush(stdin);
	scanf("%d", &qtdEquipes);



	printf("\n\nPressione um tecla para sair \n");

system("pause");
return EXIT_SUCCESS;
}
