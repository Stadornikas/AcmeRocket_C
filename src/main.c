#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libs/tipofilaLancamento.h"
#include "libs/pilhaPodio.h"

int main()
{
    pilhaPodio pilha;
    sucesso podio, aux;
    INIT(&pilha);

    tipofilaLancamento inicio,fim, percorre;
    struct lancamento equipes;
    INITLANC(&inicio,&fim);

    setlocale(LC_ALL, "Portuguese");
    int qtdEquipes = 0, maxTentativas = 0, colocacao = 0, campeoes[3], auxEquipes = 0;
    int i ,x, j, qtdMinEquipe;
    float menorDistancia = 9999999;
    char situacao;


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

		printf("\n Digite nome da equipe ou 0 para parar: ");
		fflush(stdin);
		fgets(equipes.nomeEquipe);

		if(strcmp(equipes.nomeEquipe, "0") == 0)
		{
			auxEquipes = 0;
		}
		else
		{
			auxEquipes = 1;
			ENQUEUE(&inicio,&fim,equipes);
			printf("\n Cadastrado com sucesso\n");
		}

    }while(auxEquipes != 0);


    //Percorre o array de equipes
     while(PROXIMO(&inicio) == 1)
     {
       
		   while(equipes.tentativas <= 2 && equipes.situacao == 0)
		   {

				 //Máximo de 3 tentativas
				 for(x = 0 ; x < 3; x++)
				 {
					  printf("\n----------------------------------------------------------------------\n");
					  printf("\nQual a situacao do %d lancamento da equipes %s?", x+1, equipes.nomeEquipe);
					  printf("\nInforme (s) Sucesso (f) Falha: ");
					  fflush(stdin);
					  scanf(" %c", &situacao);

					  switch(situacao)
					  {
							case 's':
								  equipes.situacao = 1;

								  printf("\nDigite a distancia do alvo: ");
								  fflush(stdin);
								  scanf("%f", &equipes.distanciaAlvo);

								  printf("Digite o tempo de propulsao: ");
								  fflush(stdin);
								  scanf("%f", &equipes.tempoPropulsao);

								  equipes.tentativas++;
								  break;

							case 'f':
								  printf("Lancamento falhou \n");
								  equipes.tentativas++;
								  if(equipes.tentativas > 2)
								  {
									  equipes.situacao = -1;
								  }
								  break;

						} // END CASE

						if (equipes.situacao == 1 || equipes.situacao == -1) break;
				 } //END FOR

		   } //END WHILE

     } // End for


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


    printf("\n\nPressione um tecla para sair \n");

	system("pause");
	return EXIT_SUCCESS;
}
