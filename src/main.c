/*
 * main.c
 *
 *  Created on: 02/10/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "libs/equipes.h"
#include "libs/lancamento.h"
#include "libs/pilhaPodio.h"


int main()
{
    pilhaPodio pilha;
    podio strPodio;
    INIT(&pilha);
    
    
    int qtdEquipes = 0, maxTentativas = 0, numEquipes = 0, colocacao = 1, campeao;
    float menorDistancia = 9999999.9;
    char situacao;
    int x;
    int j;
    int i;
    int vencedores[3];

	printf("\n====================================================================");
	printf("\n=============== BEM VINDO AO SISTEMA ACME ROCKET ===================");
	printf("\n=============== VERSAO: 1.0 ========================================");
	printf("\n====================================================================");
	printf("\n");
	printf("\n");
	//printf("\nDigite a quantidade de equipes que deseja cadastrar na competiÃ§Ã£o: ");
	printf("\nDigite a quantidade de equipes que deseja cadastrar na competicao: ");
	fflush(stdin);
	scanf("%d", &qtdEquipes);


	Lancamento lancamento[qtdEquipes];

	for(i = 0 ; i < qtdEquipes; i++){

		lancamento[i].tentativas = 0;
		lancamento[i].situacao = 0;

		x = i;

    	printf("\nDigite nome da equipe %d: ",x+1);
    	fflush(stdin);
    	fgets(lancamento[i].nomeEquipe,MAX,stdin);


    };

	numEquipes = qtdEquipes-1;

	 for(i = 0 ; i <= numEquipes; i++){	
	 	while(lancamento[i].tentativas <= 2 && lancamento[i].situacao == 0){
	 		
		 		for(x = lancamento[i].tentativas ; i <= 2; x++){	
				x = lancamento[i].tentativas;				
				//printf("\n %dÂ° Tentativa de lanÃ§amento da equipe %s: ",x+1,lancamento[i].nomeEquipe);
				printf("\n %d Tentativa de lancamento da equipe %s: ",x+1,lancamento[i].nomeEquipe);
		
						//printf("\nInforme a situaÃ§Ã£o do %dÂ° lanÃ§amento da equipe %s: (s = Sucesso ou f = Falha) ",x+1,lancamento[i].nomeEquipe);
						printf("\nInforme a situacao do %d lancamento da equipe %s: (s = Sucesso ou f = Falha) ",x+1,lancamento[i].nomeEquipe);
						fflush(stdin);
						scanf("%c", &situacao);
						
		
						switch(situacao){
							case 's':
								lancamento[i].situacao = 1;
		
								printf("\nDigite a distancia do alvo: ");
								fflush(stdin);
								scanf("%f", &lancamento[i].distanciaAlvo);
								
		
								//printf("\nDigite o tempo de propulsÃ£o: ");
								printf("\nDigite o tempo de propulsao: ");
								fflush(stdin);
								scanf("%f", &lancamento[i].tempoPropulsao);
								
		
								lancamento[i].tentativas++;
								
								break;
		
							case 'f':
								lancamento[i].tentativas++;
								if(lancamento[i].tentativas > 2){
									lancamento[i].situacao = -1;
									
								}
								break;		
						}
						break;			 
				}
		}
	}

	x = 0;
	int posicao;
	campeao = 0;
	menorDistancia = 999999;
	
	while(colocacao <= 3){
	
	printf("Colocacao %d \n", colocacao);	
	for(i = 0; i<= numEquipes; i++){
			printf("\n ");	
		if(lancamento[i].situacao == 1){
			if(lancamento[i].distanciaAlvo < menorDistancia){
				posicao = i;
				menorDistancia = lancamento[i].distanciaAlvo;
				lancamento[i].situacao = 0;
				printf("\n menorDistancia %f", menorDistancia);	
			}
			printf("\n Distancia Alvo %f", lancamento[i].distanciaAlvo );
			
		}	
	}
	
	
	vencedores[colocacao-1] = posicao;
	
	
	colocacao++;
	x++;
	}
	
	if(campeao != 0){
			printf("DistanciaAlvo %f", lancamento[campeao].distanciaAlvo);
//			strcpy(podio.nomeEquipe,lancamento[campeao].nomeEquipe);
			strPodio.distanciaAlvo = lancamento[campeao].distanciaAlvo;
			printf("tempoPro %f", lancamento[campeao].tempoPropulsao);
			strPodio.tempoPropulsao = lancamento[campeao].tempoPropulsao;
			PUSH(&pilha,strPodio);
		}

    printf("\n======================================================");
    printf("\n=============  Resultados da competicao  =============");
    printf("\n======================================================");
	printf("Pilha%d", IsEmpty(pilha));
	while (!IsEmpty(pilha)){
		
		if(POP(&pilha, &strPodio)){
			printf("\nEm %d Lugar: ",colocacao);
       printf("\nNome da Equipe: %s",strPodio.nomeEquipe);
       printf("\nDistancia do alvo: %f \n",strPodio.distanciaAlvo);
       printf("\nTempo de propulsao: %f \n",strPodio.tempoPropulsao);
       printf("\n");
       printf("\n");
       colocacao--;
		}
       
       
    }


	printf("\n\nPressione um tecla para sair \n");

system("pause");
return EXIT_SUCCESS;
}