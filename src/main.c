/*
 * main.c
 *
 *  Created on: 02/10/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "libs/equipes.h"
#include "libs/pilhaPodio.h"


int main()
{
    pilhaPodio pilha;
    podio podio;
    INIT(&pilha);
    int qtdEquipes = 0, maxTentativas = 0, numEquipes = 0, colocacao = 1, campeao;
    float menorDistancia = 9999999.9;
    char situacao;
    int x;

	printf("\n====================================================================");
	printf("\n=============== BEM VINDO AO SISTEMA ACME ROCKET ===================");
	printf("\n=============== VERSAO: 1.0 ========================================");
	printf("\n====================================================================");
	printf("\n");
	printf("\n");
	printf("\nDigite a quantidade de equipes que deseja cadastrar na competição: ");
	fflush(stdin);
	scanf("%d", &qtdEquipes);


	equipes lancamento[qtdEquipes];

	for(int i = 0 ; i < qtdEquipes; i++){

		lancamento[i].tentativas = 0;
		lancamento[i].situacao = 0;

		x = i;

    	printf("\nDigite nome da equipe %d: ",x+1);
    	fflush(stdin);
    	fgets(lancamento[i].nomeEquipe,MAX,stdin);
    	getchar();


    };

	numEquipes = sizeof(lancamento);

	do{

	 for(int i = 0 ; i < numEquipes; i++){

		 x = lancamento[i].tentativas;

		printf("\n %d° Tentativa de lançamento da equipe %s: ",x+1,lancamento[i].nomeEquipe);

		if(lancamento[i].situacao == 0){
			do{
				printf("\nInforme a situação do %d° lançamento da equipe %s: (s = Sucesso ou f = Falha) ",x+1,lancamento[i].nomeEquipe);
				fflush(stdin);
				scanf("%c", &situacao);
				getchar();

				switch(situacao){
					case 's':
						lancamento[i].situacao = 1;

						printf("\nDigite a distancia do alvo: ");
						fflush(stdin);
						scanf("%f", &lancamento[i].distanciaAlvo);
						getchar();

						printf("\nDigite o tempo de propulsão: ");
						fflush(stdin);
						scanf("%f", &lancamento[i].tempoPropulsao);
						getchar();

						lancamento[i].tentativas++;
						maxTentativas++;
						break;
					case 'f':
						lancamento[i].tentativas++;
						if(lancamento[i].tentativas > 2){
							lancamento[i].situacao = -1;
							maxTentativas++;
						}
						break;

				}

			}while(situacao != 's' || situacao != 'f');
		}

	 }

	}while(maxTentativas < numEquipes);

	campeao == NULL;

	while(colocacao <= 3){
		for(int j = 0; j < numEquipes; j++){
			if(lancamento[j].situacao == 1){

				if(lancamento[j].distanciaAlvo < menorDistancia ){
					//TODO Criar lógica para critério de desempate
					menorDistancia = lancamento[j].distanciaAlvo;
//					tempoPropulsao = lancamento[j].tempoPropulsao;
					campeao = j;
				}

				lancamento[j].situacao = 0;
			}
		}

		if(campeao != NULL){
			strcpy(podio.nomeEquipe,lancamento[campeao].nomeEquipe);
			podio.distanciaAlvo = lancamento[campeao].distanciaAlvo;
			podio.tempoPropulsao = lancamento[campeao].tempoPropulsao;
			PUSH(&pilha,podio);
		}

		campeao = NULL;

		colocacao++;
	}

    printf("\n======================================================");
    printf("\n=============  Resultados da competição  =============");
    printf("\n======================================================");

	while (!IsEmpty(pilha)){
       POP(&pilha, &podio);
       printf("\nEm %d° Lugar: ",colocacao);
       printf("\nNome da Equipe: %s",podio.nomeEquipe);
       printf("\nDistancia do alvo: %f \n",podio.distanciaAlvo);
       printf("\nTempo de propulsao: %f \n",podio.tempoPropulsao);
       printf("\n");
       printf("\n");
       colocacao--;
    }


	printf("\n\nPressione um tecla para sair \n");
	getchar();

system("pause");
return EXIT_SUCCESS;
}
