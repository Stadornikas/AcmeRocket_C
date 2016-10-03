/*
 * main.c
 *
 *  Created on: 02/10/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "libs/lancamento.h"
#include "libs/pilhaPodio.h"


int main()
{
	char teste[200];
    pilhaPodio pilha;
//    int num, resto;
    INIT(&pilha);
    listaLancamento lista, aux;
    lista = NULL;
    lista = (listaLancamento) malloc(sizeof(struct noLista)); //MALLOC -> faz a din�micaaloca��o

    	lista->dado.tentativas = 0;
    	lista->dado.situacao = 0;

    	if (lista == NULL)
    	    printf("nao foi possivel alocar espaco requisitado \n");
    	else {

    		printf("digite nome da equipe: ");
    		fflush(stdin);
//    		fgets(teste,MAX,stdin);
    		fgets(lista->dado.nomeEquipe,MAX,stdin);
//    		scanf("%s", &lista->dado.nomeEquipe);


    		lista->dado.tentativas++;

    		printf("Digite a distancia do alvo: ");
    		scanf("%f", &lista->dado.distanciaAlvo);

    		printf("Digite o tempo de propulsão: ");
    		scanf("%f", &lista->dado.tempoPropulsao);

    		printf("informe a situação: ");
    		scanf("%d", &lista->dado.situacao);

    		lista->prox=NULL;

    	}


//    	while(aux != NULL){
//    		printf("\nNome da Equipe: %s",teste);
    		printf("\nNome da Equipe: %s",lista->dado.nomeEquipe);
    		printf("\nDistancia do alvo: %f \n",lista->dado.distanciaAlvo);
    		printf("\nTempo de propulsao: %f \n",lista->dado.tempoPropulsao);
    		printf("\nSituacao: %d \n",lista->dado.situacao);
//    		aux = aux->prox;
//    	}




system("pause");
}
