/*
 * main.c
 *
 *  Created on: 02/10/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libs/lancamento.h"
#include "libs/pilhaPodio.h"
int main()
{
    pilhaPodio pilha;
    sucesso podio, aux;
    INIT(&pilha);
    setlocale(LC_ALL, "Portuguese");
    int qtdEquipes = 0, maxTentativas = 0, colocacao = 0, campeoes[3];
    int i ,x, j;
    float menorDistancia = 9999999;
    char situacao;


	printf("  ____                         _           _             \n");
	printf(" |  _ \\                       (_)         | |           \n");
	printf(" | |_) | ___ _ __ ___   __   ___ _ __   __| | ___        \n");
	printf(" |  _ < / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\ \n");
	printf(" | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) |     \n");
	printf(" |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \n");
	printf("               AO SISTEMA ACME ROCKET\n\n\n");
	
	printf("\nDigite a quantidade de equipes que deseja cadastrar na competicao: ");
	fflush(stdin);
	scanf("%d", &qtdEquipes);

	//Votor de equipes para guardar dados dos lancamentos
	lancamento equipe[qtdEquipes];

	//Pega nomes das equipes
	for(i = 0 ; i < qtdEquipes; i++){

		equipe[i].tentativas = 0;
		equipe[i].situacao = 0;

		x = i;

    	printf("\n Digite nome da equipe %d: ",x+1);
    	fflush(stdin);
    	scanf("%s",equipe[i].nomeEquipe);

    }


		//Percorre o array de equipes
		 for(i = 0 ; i < qtdEquipes; i++){
			 //Enquanto houver lancamentos pendentes
			 while(equipe[i].tentativas <= 2 && equipe[i].situacao == 0){

				 //Máximo de 3 tentativas
			 	 for(x = 0 ; x < 3; x++){
			 	 	printf("\n----------------------------------------------------------------------\n");
					//printf("\n %d° Tentativa de lançamento da equipe %s: ",x,equipe[i].nomeEquipe);
					printf("\nQual a situacao do %d� lancamento da equipe %s?", x+1, equipe[i].nomeEquipe);

					//printf("\nInforme a situação do %d° lançamento da equipe %s: (s = Sucesso ou f = Falha) ",x,equipe[i].nomeEquipe);
					printf("\nInforme (s) Sucesso (f): ");
					fflush(stdin);
					scanf(" %c", &situacao);

					switch(situacao){
						case 's':
							//printf("lancamento ok \n");
							equipe[i].situacao = 1;

							//printf("\nSituacao equipe %s : %d \n",equipe[i].nomeEquipe, equipe[i].situacao);

							printf("\nDigite a distancia do alvo: ");
							fflush(stdin);
							scanf("%f", &equipe[i].distanciaAlvo);

							printf("Digite o tempo de propulsao: ");
							fflush(stdin);
							scanf("%f", &equipe[i].tempoPropulsao);

							equipe[i].tentativas++;
							break;

						case 'f':
							printf("Lancamento falhou \n");
							equipe[i].tentativas++;
							if(equipe[i].tentativas > 2){
								equipe[i].situacao = -1;
							}
							break;

						} // END CASE

						if (equipe[i].situacao == 1 || equipe[i].situacao == -1) break;
			 	 } //END FOR

			 } //END WHILE

		 } // End for


	int vencedorTemp;
    // Enquanto nao encontrar campeoes
	while(colocacao < 3){

		campeoes[colocacao] = 0;

		printf("entrou no while, num equipe %d \n", qtdEquipes);

		// Percorre array de equipes
		for(j = 0; j < qtdEquipes; j++){

			printf("entrou no for \n");

			//Apenas equipe com lancamento concluido
			if(equipe[j].situacao == 1){

				printf("\nSituacao equipe %s : %d \n",equipe[j].nomeEquipe, equipe[j].situacao);

				//Sempre a menor distancia do alvo
				if(equipe[j].distanciaAlvo < menorDistancia ){
					//TODO Criar lógica para critério de desempate

					menorDistancia = equipe[j].distanciaAlvo;
//					tempoPropulsao = equipe[j].tempoPropulsao;
					vencedorTemp = j;
					
				}else if (equipe[j].distanciaAlvo = menorDistancia){
					if(equipe[j].tempoPropulsao > equipe[vencedorTemp].tempoPropulsao){
						vencedorTemp = j;
					}
				}


			}
		}
		campeoes[colocacao] = vencedorTemp;
		menorDistancia = 999999;

		equipe[campeoes[colocacao]].situacao = 0;

		colocacao++;
	}



	for(colocacao = 0; colocacao < 3; colocacao ++){

			x = colocacao;

			printf("\nEm %d Lugar: %s \n ",x+1, equipe[campeoes[colocacao]].nomeEquipe);
			strcpy(podio.nomeEquipe,equipe[campeoes[colocacao]].nomeEquipe);
			podio.distanciaAlvo = equipe[campeoes[colocacao]].distanciaAlvo;
			podio.tempoPropulsao = equipe[campeoes[colocacao]].tempoPropulsao;
			PUSH(&pilha, podio);


	}


    printf("\n######################################################");
    printf("\n#                                                    #");
    printf("\n#              RESULTADOS DA COMPETI��O              #");
    printf("\n#                                                    #");
    printf("\n######################################################\n");

	while (!IsEmpty(pilha)){
    	POP(&pilha, &aux);
       	printf("\nEm %d Lugar: ",colocacao);
    	printf("\nNome da Equipe: %s",aux.nomeEquipe);
       	printf("\nDistancia do alvo: %f \n",aux.distanciaAlvo);
       	printf("\nTempo de propulsao: %f \n",aux.tempoPropulsao);
       	printf("\n");
       	printf("\n");
       	colocacao--;
    }


	printf("\n\nPressione um tecla para sair \n");

system("pause");
return EXIT_SUCCESS;
}

