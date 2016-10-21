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

    //definicoes de lista
    tipofilaLancamento inicio,fim, percorre;
    lancamento equipes;
    INITLANC(&inicio,&fim);

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
			ENQUEUE(&inicio,&fim, equipes);
			printf("\n Equipe %s cadastrada com sucesso \n",equipes.nomeEquipe);
		}

		printf("\n Deseja cadadastrar outra equipe?(s/n):");
		fflush(stdin);
		scanf("%c",&continuar);

    }while(continuar == 's');

  	percorre = inicio;

    //Percorre a lista de equipes equanto conter itens na lista
     while(percorre->prox != NULL)
     {
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

					   // Elimina demais tentativas em caso de sucesso ou desclassificacao
						if (percorre->dado.situacao == 1 || percorre->dado.situacao == -1) break;
				 } //END FOR

		   } //END WHILE

		   //avanca item da lista para proxima iteracao
		   percorre = percorre->prox;

     } // End While

     /*

  int vencedorTemp;


  qtdMinEquipe = (qtdEquipes > 3)? 3 : qtdEquipes;
  menorDistancia = 999999;
    // Enquanto nao encontrar campeoes
  while(colocacao < qtdMinEquipe)
  {

		campeoes[colocacao] = 0;

		//printf("entrou no while, num equipe %d \n", qtdEquipes);

		// Percorre array de equipes
		for(j = 0; j < qtdEquipes; j++)
		{

			  //Apenas equipe com lancamento concluido
			  if(equipes.situacao == 1)
			  {

				//Sempre a menor distancia do alvo
					if(equipes.distanciaAlvo < menorDistancia )
					{
						  //TODO Criar lógica para critério de desempate

						  menorDistancia = equipes.distanciaAlvo;
						  vencedorTemp = j;
					}
					else if (equipes.distanciaAlvo == menorDistancia)
					{
						  if(equipes.tempoPropulsao > equipes.tempoPropulsao)
						  {
							vencedorTemp = j;
						  }
					}
			  }
		}// end for

		campeoes[colocacao] = vencedorTemp;
		menorDistancia = 999999;

		equipes.situacao = 0;

		colocacao++;

  }//end while

x = colocacao;

  for(colocacao = 0; colocacao < x; colocacao ++)
  {
      strcpy(podio.nomeEquipe,equipes.nomeEquipe);
      podio.distanciaAlvo = equipes.distanciaAlvo;
      podio.tempoPropulsao = equipes.tempoPropulsao;
      PUSH(&pilha, podio);
  }


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

*/
    printf("\n\nPressione um tecla para sair \n");

	system("pause");
	return EXIT_SUCCESS;
}
