#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libs/tipofilaLancamento.h"
#include "libs/pilhaPodio.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");

	//definicoes da pilha
    pilhaPodio pilha;
    sucesso podio, aux;
    INIT(&pilha);

    //definicoes de listas
    tipofilaLancamento iniLancamento,fimLancamento,  iniSucesso, fimSucesso, percorre, filaSucesso;
    lancamento equipes, campeao;
    INITLANC(&iniLancamento,&fimLancamento);
	INITLANC(&iniSucesso,&fimSucesso);

    //definicoes de variaveis
    int qtdEquipes = 0, maxTentativas = 0, colocacao = 0, campeoes[3], auxEquipes = 0;
    int x, j, qtdMinEquipe;
    float menorDistancia = 9999999;
    char situacao, continuar = 's';


	  printf("  ____                         _           _             \n");
	  printf(" |  _ \\                       (_)         | |           \n");
	  printf(" | |_) | ___ _ __ ___   __   ___ _ __   __| | ___        \n");
	  printf(" |  _ < / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\ \n");
	  printf(" | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) |     \n");
	  printf(" |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \n");
	  printf("               AO SISTEMA ACME ROCKET\n\n\n");
  

  //Pega nomes das equipes
  do{
    //Insiro todos as equipes na fila Lancamento, iniciando os valores padrao.
		equipes.tentativas = 0;
		equipes.situacao = 0;

		printf("\n Digite nome da proxima equipe a ser cadastrada 2:");
		fflush(stdin);
		fgets(equipes.nomeEquipe, MAX, stdin);

		if(strcmp(equipes.nomeEquipe, "") == 0 || strlen(equipes.nomeEquipe)==0)
		{
			printf("\n Digite um nome valido \n");
		}
		else
		{
			auxEquipes = 1;
			ENQUEUE(&iniLancamento,&fimLancamento, equipes);
			printf("\n Equipe %s cadastrada com sucesso \n",equipes.nomeEquipe);
		}

		printf("\n Deseja cadadastrar outra equipe?(s/n):");
		fflush(stdin);
		scanf("%c",&continuar);

    }while(continuar == 's');
	

  	percorre = iniLancamento;

    //Percorre a lista de equipes equanto conter itens na lista
    while(percorre != NULL){
    	 //repete ate que todas as equipes tenham participado
		   while(percorre->dado.tentativas <= 2 && percorre->dado.situacao == 0)
		   {
				 //Máximo de 3 tentativas por equipe
				 for(x = 0 ; x < 3; x++)
				 {
					  printf("\n----------------------------------------------------------------------\n");
					  printf("\nQual a situacao do %d lancamento da equipes %s?", x+1, percorre->dado.nomeEquipe);
					  printf("\nInforme (s) Sucesso (f) Falha: ");
					  fflush(stdin);
					  scanf(" %c", &situacao);

					  switch(situacao)
					  {
							case 's':
								 percorre->dado.situacao = 1;

								  printf("\nDigite a distancia do alvo: ");
								  fflush(stdin);
								  scanf("%f", &percorre->dado.distanciaAlvo);

								  printf("Digite o tempo de propulsao: ");
								  fflush(stdin);
								  scanf("%f", &percorre->dado.tempoPropulsao);

								  percorre->dado.tentativas++;
								  break;

							case 'f':
								  printf("Lancamento falhou \n");
								  percorre->dado.tentativas++;
								  if(percorre->dado.tentativas > 2)
								  {
									  percorre->dado.situacao = -1;
								  }
								  break;

						} // END CASE

					   // Insere na fila de sucesso as equipes com status 1
						if (percorre->dado.situacao == 1){
							ENQUEUE(&iniSucesso,&fimSucesso, percorre->dado);
							break;	
						}
				 } //END FOR

		   } //END WHILE

		   //avanca item da lista para proxima iteracao
		   percorre = percorre->prox;

     } // End While




ORDER(&iniSucesso,&fimSucesso);



    // Enquanto nao encontrar campeoes
  while(colocacao < 3)
  {
		percorre = iniSucesso;
				
		// Percorre lista de equipes que obtiveram sucesso
		while(percorre != NULL)
		{
				//Pega sempre a menor distancia do alvo
				if(percorre->dado.distanciaAlvo < menorDistancia )
				{
		            menorDistancia = percorre->dado.distanciaAlvo;
				}
				else if (percorre->dado.distanciaAlvo == menorDistancia)
				{
					//Criterio de dempate = maior tempo de propulsao
				   if(percorre->dado.tempoPropulsao > percorre->dado.tempoPropulsao)
				   {
//						vencedorTemp = j;
						menorDistancia = percorre->dado.distanciaAlvo;
				   }
				}
					
			//avanca item da lista para proxima iteracao
		    percorre = percorre->prox;		
			  
		}// end for
		
		percorre = iniSucesso;
		
		// Percorre lista de equipes que obtiveram sucesso
		while(percorre != NULL)
		{
			if(percorre->dado.distanciaAlvo == menorDistancia )
			{
				DEQUEUE(&iniSucesso,&fimSucesso,&campeao);
				strcpy(podio.nomeEquipe,percorre->dado.nomeEquipe);
			    podio.distanciaAlvo = percorre->dado.distanciaAlvo;
			    podio.tempoPropulsao = percorre->dado.tempoPropulsao;
			    PUSH(&pilha, podio);
				
			}
			//avanca item da lista para proxima iteracao
			percorre = percorre->prox;
		}
	
		menorDistancia = 999999;

		colocacao++;

  }//end while



    printf("\n######################################################");
    printf("\n#                                                    #");
    printf("\n#              RESULTADOS DA COMPETICAO              #");
    printf("\n#                                                    #");
    printf("\n######################################################\n");

  while (!IsEmpty(pilha))
  {
      POP(&pilha, &aux);
      printf("\nEm %d Lugar: ",colocacao);
      printf("\nNome da Equipe: %s",aux.nomeEquipe);
      printf("\nDistancia do alvo: %0.2f \n",aux.distanciaAlvo);
      printf("\nTempo de propulsao: %0.2f \n",aux.tempoPropulsao);
      printf("\n");
      printf("\n");
      colocacao--;
  }


    printf("\n\nPressione um tecla para sair \n");

	system("pause");
	return EXIT_SUCCESS;
}
